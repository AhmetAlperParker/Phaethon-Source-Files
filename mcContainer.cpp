#include "stdafx.h"
#include "mcContainer.h"

mcContainer mySecMC; 
//------------------------------------------------------------------------------------------------------------------------------------------
void mcContainer::clear(){	
	if (inized){ //clear only if initialized
		delete[] SectionsMC;
		inized = false;
		nConvergCount = 0;
	}		
}
//------------------------------------------------------------------------------------------------------------------------------------------
void mcContainer::init(guiInput myGI){	
	clear();
	
	dKappa = myGI.dKappaInp;
	dGamma = myGI.dGammaInp;
	nSteps = myGI.nStepsMCInp+1; //gia to mideniko
	Naxial = myGI.nAxInp;

	SectionsMC = new Section[nSteps];
	mcSecTyp = (myGI.isRect)?stRect:stCirc;		
	
	//initialize sections.
	
	switch (mcSecTyp) {
		case stRect :{		
			for (int n = 0; n < nSteps ; n++){			
				(SectionsMC[n]).initRect(myGI.dInp, myGI.bInp, myGI.nIPInp, myGI.nFibersInp, myGI.fAsInp, myGI.covInp);
				SectionsMC[n].secNaxial = Naxial;
			}
			break;
		}
		case stCirc :{				
			for (int n = 0; n < nSteps ; n++){			
				(SectionsMC[n]).initCirc(myGI.dInp, myGI.nIPInp, myGI.nBarsInp, myGI.dBarInp, myGI.covInp);
				SectionsMC[n].secNaxial = Naxial;
			}
			break;
		}		
		default:
			MessageBoxW(NULL,L"Given Section Type not known", L"Element Type", MB_OK);
	}
	inized = true;
}
				
//------------------------------------------------------------------------------------------------------------------------------------------
void mcContainer::evalMC(guiInput myGI, System::Windows::Forms::DataVisualization::Charting::Chart^  chartMC1, System::Windows::Forms::DataVisualization::Charting::Chart^  chartFS){	

/*	moment-curvature analysis of a section
	variables required in the workspace: SecName, SecData, N, Dkappa, Dgama, no_step, tol, maxiter
	section:  SecName (function name of section description), SecData (section properties)
	loading:  N (applied axial force), Dkappa (imposed curvature increment)
	Dgama (imposed shear strain increment)
	solution: no_step (number of load steps), tol (solution tolerance), maxiter (max no of iterations for each step) */
	//progress mask 
	Phaethon::F_SolvProgress ^ fProg = gcnew Phaethon::F_SolvProgress(false,myGI.nStepsMCInp,0);
	fProg->Show();
	fProg->Refresh();
	
	init(myGI);
	
	// pre-size complete vector of section forces and deformations for plotting
	eResults.resize(3,nSteps+1);  
	sResults.resize(3,nSteps+1);
	ePlot.resize(3,nSteps+1); 
	sPlot.resize(3,nSteps+1);
	
	
	//first step set to zero
	eResults.col(0) = Vector3d::Zero(); 
	sResults.col(0) = Vector3d::Zero(); 
	ePlot.col(0) = Vector3d::Zero(); 
	sPlot.col(0) = Vector3d::Zero(); 
	
	Vector3d eInit;
	eInit << -0.00001,  0.000001, 0.00001; //initialize for first step
	
	int kLastConverging = 0; //teleftaio converging step
	nConvergCount = 0; //counter gia ta converging steps

	double Dkap; double Dgam;
	//loop for moment-curvature relation under constant axial force
	for (int k=1 ; k<nSteps ; k++){ //ana vima  < or <=
		fProg->updStep(k);
		
		if (k==1){
			// set the curvature and strain increment for first steps (equal to zero only axial)
			Dkap = 0; Dgam=0;
		}
		else{
			// set the curvature and strain increment for all subsequent load steps
			Dkap = dKappa;
			Dgam = dGamma;
		}

		if(SectionsMC[k].MCStep(eInit,Dkap,Dgam)){
			nConvergCount = nConvergCount+1;
			// store response information for plotting and analysis
			sPlot.col(nConvergCount) = SectionsMC[k].sr;
			sResults.col(k) = SectionsMC[k].sr;	
			// store axial strain for plotting and analysis
			ePlot.col(nConvergCount) = SectionsMC[k].e;
			eResults.col(k) = SectionsMC[k].e;
			//keep last converging step in mind
			kLastConverging = k;
			eInit = SectionsMC[k].e;
		}
		else{
			eResults.col(k) = Vector3d::Zero(); 
			sResults.col(k) = Vector3d::Zero(); 
			eInit << eResults(0,kLastConverging), 0.000001+((k-1)*dKappa), 0.00001+((k-1)*dGamma); //(k-1) because one more step is added at the beginning of the next loop
		}
	}//end for loop on k
	
	ePlot.conservativeResize(NoChange,nConvergCount+1); 
	sPlot.conservativeResize(NoChange,nConvergCount+1);

	ePlotGaussian.resize(3,ePlot.row(0).size()-6); 
	sPlotGaussian.resize(3,sPlot.row(0).size()-6);

	//applying gaussian filter
	for (int i = 0; i < 3; i++){ 
		ePlotGaussian.row(i) = GaussianSmooth(ePlot.row(i),7,true);
		sPlotGaussian.row(i) = GaussianSmooth(sPlot.row(i),7,true);
	}


	//createGraphs
	chartMC1->Series[0]->Points->Clear();
	chartFS->Series[0]->Points->Clear();

	for (int iStep = 0; iStep <= nConvergCount; iStep++){
		if (iStep<=(nConvergCount-6)){// both mc and fs
			chartMC1->Series[0]->Points->AddXY(ePlot(1,iStep),(sPlot(1,iStep)/1E6));
			chartFS->Series[0]->Points->AddXY(ePlotGaussian(2,iStep),(sPlotGaussian(2,iStep)/1E3));
		}
		else{//only mc
			chartMC1->Series[0]->Points->AddXY(ePlot(1,iStep),(sPlot(1,iStep)/1E6));
		}
	}
	
	//axis fixing
	//Moment - Curvature
	
	chartMC1->ChartAreas[0]->Axes[0]->Minimum = 0;
	chartMC1->ChartAreas[0]->Axes[0]->Crossing = 0;
	double intervalX1 = intervalChoice(0, ePlot(1,nConvergCount), 7);
	chartMC1->ChartAreas[0]->Axes[0]->Interval = intervalX1;
	chartMC1->ChartAreas[0]->Axes[0]->IntervalOffset = intervalX1;

	chartMC1->ChartAreas[0]->Axes[1]->Minimum = 0;
	chartMC1->ChartAreas[0]->Axes[1]->Crossing = 0;
	double intervalY1 = intervalChoice(0, (sPlot(1,nConvergCount)/1E6), 4);
	chartMC1->ChartAreas[0]->Axes[1]->Interval = intervalY1;
	chartMC1->ChartAreas[0]->Axes[1]->IntervalOffset = intervalY1;
	
	if(ePlot(1,nConvergCount)<0.001){
		chartMC1->ChartAreas[0]->Axes[0]->LabelStyle->Format = "#.0E0"; 
	}
	else{
		chartMC1->ChartAreas[0]->Axes[0]->LabelStyle->Format = "";
	}
	if(ePlot(1,nConvergCount)<0.1){
		chartMC1->Series[0]->ToolTip="#VALX{#.00E0};#VAL{N2}";		
	}
	else{
		chartMC1->Series[0]->ToolTip="#VALX{N2};#VAL{N2}";
	}

	//Shear Force - Moment
	
	chartFS->ChartAreas[0]->Axes[0]->Minimum = 0;
	chartFS->ChartAreas[0]->Axes[0]->Crossing = 0;
	double intervalX2 = intervalChoice(0, ePlot(2,nConvergCount-6), 7);
	chartFS->ChartAreas[0]->Axes[0]->Interval = intervalX2;
	chartFS->ChartAreas[0]->Axes[0]->IntervalOffset = intervalX2;

	chartFS->ChartAreas[0]->Axes[1]->Minimum = 0;
	chartFS->ChartAreas[0]->Axes[1]->Crossing = 0;
	double intervalY2 = intervalChoice(0, (sPlot(2,nConvergCount-6)/1E3), 4);
	chartFS->ChartAreas[0]->Axes[1]->Interval = intervalY2;
	chartFS->ChartAreas[0]->Axes[1]->IntervalOffset = intervalY2;
	
	if(ePlot(2,nConvergCount-6)<0.001){
		chartFS->ChartAreas[0]->Axes[0]->LabelStyle->Format = "#.0E0"; 
	}
	else{
		chartFS->ChartAreas[0]->Axes[0]->LabelStyle->Format = "";
	}
	if(ePlot(2,nConvergCount-6)<0.1){
		chartFS->Series[0]->ToolTip="#VALX{#.00E0};#VAL{N2}";		
	}
	else{
		chartFS->Series[0]->ToolTip="#VALX{N2};#VAL{N2}";
	}

	

	chartMC1->Visible = true;	
	chartFS->Visible = true;

	fProg->Hide();
	delete fProg;
}
//------------------------------------------------------------------------------------------------------------------------------------------
bool mcContainer::printMCResults(const wchar_t *resFilename){
	FILE *fp;

	if ( (fp = _wfopen(resFilename, L"wt")) == NULL )	{
		MessageBox(NULL,L"Cannot create file with specified filename", L"Printing Results to File", MB_OK);
		return false;		// Failed to open file
	}

	fprintf(fp, "Curvature (1/mm);Moment (kNm);Shear Strain;Shear Force(kN);\n");	

	for (int iStep = 0; iStep <= nConvergCount; iStep++){
		if (iStep<=(nConvergCount-6)){
			fprintf(fp, "%f;%f;%f;%f;\n",
				ePlot(1,iStep),(sPlot(1,iStep)/1E6),
				ePlotGaussian(2,iStep),(sPlotGaussian(2,iStep)/1E3));
		}
		else{
			fprintf(fp, "%f;%f;\n",ePlot(1,iStep),(sPlot(1,iStep)/1E6));
		}
	}
		
															
	fclose(fp);
	return true;
}
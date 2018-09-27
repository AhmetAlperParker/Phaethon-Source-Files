//---------------------------------------------------------------------------
#include "stdafx.h"
#include "Element.h"

Element myCantil; 
extern Steel mySteel;
extern Algorithm myAlg;
extern Concrete myConcrete;

void Anchorage::init(const double fcInp,  const double DbInp,  const double dEffInp, const double LbInp, Element* ptElFath){     
	fc = fcInp; //themeliou                 
	Db = DbInp;     
	dEff = dEffInp;
	Lb = LbInp;
	parentCant = ptElFath;
}
//---------------------------------------------------------------------------
void Anchorage::paramInp(const double epsbInp, const double CurvInp, const double epscInp){
	epsb = epsbInp;
	Curv = CurvInp;
	epsc = epscInp;
}
//---------------------------------------------------------------------------
void Anchorage::lpaElBal(double &dep, double &epeln, double lpa){
//This function determines the lpa while the bar remains elastic
	double epel2 = epsb - ((4*fbmax)/(mySteel.Es*Db))*lpa ;
	double lpan = Lb - (1/(2*w))*log(((sy*w)+epel2)/((sy*w)-epel2));
	epeln = sy*w*(1-exp(-2*w*(Lb-lpa)))/(1+exp(-2*w*(Lb-lpa)));
	dep = epeln - epel2;			 			
}
//---------------------------------------------------------------------------
void Anchorage::lpaPlBal(double &dep, double &epeln, double lpa){
//This function determines the lpa while the bar remains elastic
	double esy = mySteel.fy/mySteel.Es;
	double epel4 = sy*w*(1-exp(-2*w*(Lb-lr-lpa)))/(1+exp(-2*w*(Lb-lr-lpa)));
	double lpan = (esy-epel4)*(mySteel.Es*Db)/(4*fbmax);
	epeln = epel4;
	dep = lpan - lpa;
}
//---------------------------------------------------------------------------
bool Anchorage::lpaEval(double &lpa, double &epel, bool elastic){
//This fucntion determines the length lpa of anchorage when the bar is elastic or elastoplastic.
	double lpaA = 150;
	double lpaB = 0.5*Lb;
	double esy = mySteel.fy/mySteel.Es;
	
	
	double depA, depB, depC;
	double epelA, epelB, epelC;
	bool ConvFlag = false;
    int number = 1;
	double rfTol;
	if(elastic){
		rfTol = 1e-16;
	}
	else{//plastic
		rfTol = 1e-4;
	}
    while (!ConvFlag){
		number = number+1;
		if(elastic){
			lpaElBal(depA,epelA,lpaA);
		}
		else{//plastic
			lpaPlBal(depA,epelA,lpaA);
  		}
		if (abs(depA)<=rfTol){
			lpa = lpaA;
			epel = epelA;
			ConvFlag = true ;
			return ConvFlag;
		}
		
		if(elastic){
			lpaElBal(depB,epelB,lpaB);
		}
		else{//plastic
			lpaPlBal(depB,epelB,lpaB);
  		}

		if ((abs(depB)<=rfTol)){
			lpa = lpaB;
			epel = epelB;
			ConvFlag = true ;
			return ConvFlag;
		}
		if (depB*depA>0){
			if(elastic){
				lpaB = 0.01*number ;
			}
			else{//plastic
				lpaB = 10*number ;
  			}
			continue;
		}
		double dx = depA*(lpaA - lpaB)/(depA - depB);
		double lpaC  = lpaA - dx;
		if(elastic){
			lpaElBal(depC,epelC,lpaC);
		}
		else{
			lpaPlBal(depC,epelC,lpaC);
		}
		if (abs(depC)<=rfTol){
			 lpa = lpaC;
			 epel = epelC;
			 ConvFlag = true;
			 return ConvFlag;
		}
		if  (depB*depC > 0){
		   lpaB = lpaA;
		   depB = depA;
		   lpaA = lpaC;
		   depA = depC;
		}
		else{
		   lpaA = lpaC;
		   depA =depC;
		}
		
		int insMaxiter = 30;
		int insIter = 0 ;
		while ((abs(depC) > rfTol) && (insIter<=insMaxiter)){
			insIter = insIter + 1;
			dx = depA*(lpaA - lpaB)/(depA - depB);
			lpaC  = lpaA - dx;
			if(elastic){
				lpaElBal(depC,epelC,lpaC);
			}
			else{
				lpaPlBal (depC,epelC,lpaC);			
			}
			if(depB*depC > 0){
				lpaB = lpaA;
				depB = depA;
				lpaA = lpaC;
				depA  = depC;
			}
			else{
				lpaA = lpaC;
				depA = depC;
			}	
		}//end inner while
		if (insIter<=insMaxiter){
			lpa = lpaC;
			epel = epelC;
			ConvFlag = true;
		}
		else{
			ConvFlag = false;
		}
	}//end outer while
	return ConvFlag;
}

//---------------------------------------------------------------------------
double Anchorage::eval(){

	double Comz = epsc/Curv ;
	fbmax = 1.25*sqrt(fc);
	fbres = 0.2*fbmax;
	sy = 0.2;
		
	double lpa, epel, s2;
	double esy = mySteel.fy/mySteel.Es;
		
	w = sqrt((4*fbmax)/(mySteel.Es*Db*sy));
	double epel1 = sy*w*(1-exp(-2*w*Lb))/(1+exp(-2*w*Lb));
	double EhAnch = mySteel.Eh;
	if (EhAnch<1E-14){
		EhAnch = 0.01*mySteel.Es;
	}

	lr = (epsb-esy)*(Db*EhAnch)/(4*fbres); //only usable for plastic
		
	if ((epsb<=esy) && (epsb >epel1)){//elastic
		lpaEval(lpa, epel, true);
	}
	else if ((epsb >esy) && (epsb >epel1)){//plastic
		lpaEval(lpa,epel,false);
		s2 = sy + 0.5*lpa*(esy+epel);
	}

	//initialize output vectors. 
	int lbMM = int(ceil(Lb));
	x.setZero(lbMM+1);
	Slip.setZero(lbMM+1);
	Bond.setZero(lbMM+1);
	StrAnch.setZero(lbMM+1);

	int i=0;

	if((epsb<=esy) && (epsb <= epel1)){
		for (i=0;i<=lbMM;i++){
			x(i) = i;
			StrAnch(i) = (epsb/(1-exp(-2*w*Lb)))*(exp(-w*x(i))-exp(w*x(i)-2*w*Lb));
			Slip(i) = (epsb/(w*(1-exp(-2*w*Lb))))*(exp(-w*x(i))+exp(w*x(i)-2*w*Lb));
			Bond(i) = (fbmax/sy)*Slip(i);
		}
	}
	else if((epsb<=esy) && (epsb>epel1)){
		for (i=0;i<=lbMM;i++){
			x(i) = i;
			if  (x(i)<=lpa){
				StrAnch(i) = epsb - ((4*fbmax)/(mySteel.Es*Db))*(x(i));
				Slip(i) = sy + 0.5*(lpa - x(i))*(StrAnch(i)+ epel);  
				Bond(i) = fbmax;   
			}
			else{
				StrAnch(i) = (epel/(1-exp(-2*w*(Lb-lpa))))*(exp(-w*(x(i)-lpa))-exp(w*(x(i)-lpa)-2*w*(Lb-lpa)));
				Slip(i) = (epel/(w*(1-exp(-2*w*(Lb-lpa)))))*(exp(-w*(x(i)-lpa))+exp(w*(x(i)-lpa)-2*w*(Lb-lpa)));  
				Bond(i) = (fbmax/sy)*Slip(i);   
			}
		}
	}   
	else{
		for (i=0;i<=lbMM;i++){
			x(i) = i;
			if (x(i) <=lr){
				StrAnch(i) = epsb - ((4*fbres)/(EhAnch*Db))*x(i);
				Slip(i) = s2 + 0.5*(lr - x(i))*(StrAnch(i)+ esy);  
				Bond(i) = fbres;
			}
			if ( (x(i)>lr) && (x(i)<=(lr+lpa)) ){
				StrAnch(i) = esy - ((4*fbmax)/(mySteel.Es*Db))*(x(i)-lr);
				Slip(i) = sy + 0.5*(lr+lpa - x(i))*(StrAnch(i)+ epel);  
				Bond(i) = fbmax;   
			}
			if ((x(i)>(lr+lpa)) && (x(i)<=Lb)){
				StrAnch(i) = (epel/(1-exp(-2*w*(Lb-lpa-lr))))*(exp(-w*(x(i)-lpa-lr))-exp(w*(x(i)-lpa-lr)-2*w*(Lb-lpa-lr)));
				Slip(i) = (epel/(w*(1-exp(-2*w*(Lb-lpa-lr)))))*(exp(-w*(x(i)-lpa-lr))+exp(w*(x(i)-lpa-lr)-2*w*(Lb-lpa-lr)));  
				Bond(i) = (fbmax/sy)*Slip(i);   
			}   
		}
	}
		

	double SlipPO;
	if ((epsb<=esy) && (epsb <=epel1)){
			SlipPO  = (epsb/(w*(1-exp(-2*w*Lb))))*(exp(-w*0)+exp(w*0-2*w*Lb));
			DeltaPO = (SlipPO / (dEff - 0.4*Comz))*parentCant->Ls;
	}
	if((epsb<=esy) && (epsb>epel1)){
			SlipPO  = sy + 0.5*lpa*(epsb+ epel); 
			DeltaPO = (SlipPO / (dEff - 0.4*Comz))*parentCant->Ls;
	}
	if((epsb > esy) && (epsb >epel1)){
			SlipPO = s2 + 0.5*lr*(epsb + esy);  
			DeltaPO = (SlipPO / (dEff - 0.4*Comz))*parentCant->Ls;
	}
	
	return DeltaPO;
}

//---------------------------------------------------------------------------
void Element::clear(){
	if (inized){ //clear only if initialized
		//lobatto results
		if(wSP){ 
			delete[] wSP;
			delete[] xSP;
		}

		//poSteps
		delete[] poSteps;
		
		befYieldStep = -1;	
		lastConvStep = -1;

		inized = false;
	}
}
//---------------------------------------------------------------------------
void Element::init(guiInput myGI){
	
	// clean up first
	clear();

	nSecPoints = myGI.nSPInp;
	nStepsPO = myGI.nStepPOInp+1; //gia na paroume kai to mideniko
	Vstep = myGI.VStepInp;
	anchExists = myGI.anExistsInp;
	Ls = myGI.LsInp;
	Naxial = myGI.nAxInp;
	eSecTyp = (myGI.isRect)?stRect:stCirc;
	nTransSB = myGI.nTransSBInp;
	stirrSp = myGI.stirrSpInp;
	Asw = myGI.AswInp;
	fyStirr = myConcrete.fyy;

	
	wSP = new double[nSecPoints];
	xSP = new double[nSecPoints];
	
	VectorXd xSPun(nSecPoints); //unitary vectors, from 0 to 1 
	VectorXd wSPun(nSecPoints);
	Lobatto(xSPun, wSPun, nSecPoints);

	for (int i=0; i < nSecPoints ; i++){
		wSP[i] = (0.5*Ls)*wSPun(i);
		xSP[i] = (0.5*Ls)*(1 + xSPun(i)); 
	}

	poSteps = new stepPO[nStepsPO];
	
	for (int j=0;j < nStepsPO ; j++){ //initializing steps
		poSteps[j].parElem = this;
		poSteps[j].Vend = Vstep*j;
		poSteps[j].SectionsPO =  new Section[nSecPoints];
		poSteps[j].idStep = j;
	}

	//also needed for the element
	hw = myGI.dInp ; //ypsos diatomis
	cov = myGI.covInp;

	//initialize sections.
	switch (eSecTyp) {
		case stRect :{	
			for (int n1 = 0; n1 < nStepsPO ; n1++){
				for (int n2 = 0; n2 < nSecPoints ; n2++){			
					(poSteps[n1].SectionsPO[n2]).initRect(myGI.dInp, myGI.bInp, myGI.nIPInp, myGI.nFibersInp, myGI.fAsInp, myGI.covInp);
				}
			}
		}
		break;
		case stCirc :{	
			for (int n1 = 0; n1 < nStepsPO ; n1++){
				for (int n2 = 0; n2 < nSecPoints ; n2++){			
					(poSteps[n1].SectionsPO[n2]).initCirc(myGI.dInp, myGI.nIPInp, myGI.nBarsInp, myGI.dBarInp, myGI.covInp); 
				}
			}
		}
		break;
		default:
			MessageBox(NULL,L"Given Section Type not known", L"Element Type", MB_OK);
	}

	
	double andEff = hw - cov - 0.5*myGI.anDbInp; //apostasi apo kentro varous ravdou 

	//anchorage initialize. 
	if(anchExists){  	
		for (int m = 0; m < nStepsPO ; m++){
			(poSteps[m].myAnch).init(myGI.anfcInp, myGI.anDbInp,  andEff, myGI.anLbInp, this); //stous ypologismous tis agkyrwisis to fc toy skyrodematos mpainei me anapodo prosimo
		}
	}
	inized = true; //element initialized
}
//---------------------------------------------------------------------------
void stepPO::eval(Phaethon::F_SolvProgress ^ fProg){
//evaluates step of iterative procedure
//practically evaluates situation of sections and Element at a certain load
	int iSec;

	double sInp[3];
	sInp[0] = parElem->Naxial;
	
	//calculate the situation at each Section
	for (iSec = 0; iSec < parElem->nSecPoints ; iSec++){ 
		fProg->updSec(iSec+1);
				
		//evaluate force vector
		sInp[2] = Vend;
		sInp[1] = -(Vend*(parElem->Ls)*(1-(parElem->xSP[iSec]/parElem->Ls)));	//Μ	
		SectionsPO[iSec].initLoads(sInp);
		SectionsPO[iSec].RCΙter(myAlg);		
	}

	deltaFl = 0;
	deltaSh = 0;
	for (iSec = 0; iSec < parElem->nSecPoints ; iSec++){ 
		deltaFl = deltaFl + abs(SectionsPO[iSec].e(1))*(parElem->Ls-parElem->xSP[iSec])*parElem->wSP[iSec]; //to Ls-xSP prokyptei giati theloyme tin apostasi apo to akro
		deltaSh = deltaSh + abs(SectionsPO[iSec].e(2))*parElem->wSP[iSec]; 
	}		

	//anchorage computation 
	if( parElem->anchExists){
		//epsc apo tin akraia thlivomeni feta tis diatomis tis paktosi		
		double epsbInp = SectionsPO[0].getEpsbAnch();
		double CurvInp = abs(SectionsPO[0].e(1));
		double epscInp = SectionsPO[0].getEpscAnch();
		
		myAnch.paramInp(epsbInp, CurvInp, epscInp); //parametrical input
		if ((epsbInp==0)&&(epscInp==0)){	//omosimes paramorfosis, den exoume kykliki exolkefsi
			deltaPOn = 0;
		}
		else{
			deltaPOn = myAnch.eval();
			anchRes = true; //there are nonzero anchorage results
		}
		
	}

	delta = abs(deltaFl) + abs(deltaSh) + abs(deltaPOn) ; //ο τελευταίος όρος είναι από την αγκύρωση, ειναι μηδενικό αν δεν υπάρχει αγκύρωση
	// ypologismos diarrois
	if (SectionsPO[0].getEpsbAnch()>(mySteel.fy/mySteel.Es)){
		bYield = true;
		if(parElem->befYieldStep==-1){
			parElem->befYieldStep = idStep-1;
		}
	}
}
//---------------------------------------------------------------------------
void Element::evalPO(guiInput myGI, System::Windows::Forms::DataVisualization::Charting::Chart^  chartPOGen
									, System::Windows::Forms::DataVisualization::Charting::Chart^  chartPOContr){
	
	//progress mask 
	Phaethon::F_SolvProgress ^ fProg = gcnew Phaethon::F_SolvProgress(true,myGI.nStepPOInp,myGI.nSPInp);
	fProg->Show();
	fProg->Refresh();
		
	//initialize
	init(myGI);
	
	//step zero 
	for (int iSec = 0; iSec < nSecPoints ; iSec++){ 
		(poSteps[0].SectionsPO[iSec]).e.setZero();
		(poSteps[0].SectionsPO[iSec]).s.setZero();
	}

	for (int iStep = 1; iStep < nStepsPO ; iStep++){ 
		fProg->updStep(iStep);
		
		poSteps[iStep].eval(fProg);
		//check if step has converged  		
		poSteps[iStep].conv = true;
		poSteps[iStep].convWoV = true;
		

		for (int iSec = 0; iSec < nSecPoints ; iSec++){ 		
			if (!(poSteps[iStep].SectionsPO[iSec]).hasConv){	//if one cross - section has not converged, problem
				poSteps[iStep].conv = false;
			}

			if (!(((poSteps[iStep].SectionsPO[iSec]).hasConv)||((poSteps[iStep].SectionsPO[iSec]).hasConvWoV)||((poSteps[iStep].SectionsPO[iSec]).hasConvOneMC))){	//if one cross - section has not converged, problem				
				poSteps[iStep].convWoV = false;
				poSteps[iStep].anchRes = false;
				if (poSteps[iStep-1].convWoV){
					lastConvStep = iStep-1;	// last converging step is the previous one
				}						// there might be intermediate converging steps
				
			/*	if (debugMsg){//yg reform
					wstring strStep = to_wstring(static_cast<long long>(iStep));
					wstring msg = L"Step "+strStep+L" has not converged";
					MessageBox(NULL,msg.c_str(),L"Pushover Calculation", MB_OK);
				}	*/
				//break; yg with 2017.5.7
			}
		}
	}

	if(lastConvStep==-1){//means all steps hav converged
		lastConvStep = nStepsPO-1;
	}

	evalDesc(); 

	//apply to GUI graphs
	chartPOGen->Visible = true;
	chartPOGen->Series[0]->Points->Clear();
	chartPOGen->Series[1]->Points->Clear();

	chartPOContr->Visible = true;
	chartPOContr->Series["Flexure"]->Points->Clear();
	chartPOContr->Series["Shear"]->Points->Clear();
	chartPOContr->Series["Anchorage Slip"]->Points->Clear();

	chartPOContr->Series["Anchorage Slip"]->IsVisibleInLegend = anchExists;

	int contCounter = -1;
	for (int iStep = 0; iStep < nStepsPO ; iStep++){
		if(poSteps[iStep].convWoV){ 
			chartPOGen->Series[0]->Points->AddXY(poSteps[iStep].delta, (poSteps[iStep].Vend/1000));
			//contributions
			contCounter++;
			chartPOContr->Series["Flexure"]->Points->AddXY(contCounter,poSteps[iStep].deltaFl);
			chartPOContr->Series["Shear"]->Points->AddXY(contCounter,poSteps[iStep].deltaSh);
			if(anchExists){
			chartPOContr->Series["Anchorage Slip"]->Points->AddXY(contCounter,poSteps[iStep].deltaPOn);			
			}
		}
	}
	//dashed line φθίνοντα κλάδου 
	chartPOGen->Series[1]->Points->AddXY(poSteps[lastConvStep].delta,(poSteps[lastConvStep].Vend/1000));
	chartPOGen->Series[1]->Points->AddXY(deltaDrift,(vDrift/1000));
	chartPOGen->Series[1]->Points[1]->Label = "Axial Failure:\n#VALX{N2};#VAL{N2}";//label
	chartPOGen->Series[1]->Points[1]->LabelBorderColor = System::Drawing::Color::Orange;
	chartPOGen->Series[1]->Points[1]->LabelForeColor = System::Drawing::Color::Orange;
	chartPOGen->Series[1]->Points[1]->LabelBackColor = System::Drawing::Color::White;

	//x axis 1st part
	chartPOGen->ChartAreas[0]->Axes[0]->Minimum = 0;
	chartPOGen->ChartAreas[0]->Axes[0]->Crossing = 0;
	double intervalX = intervalChoice(0 ,poSteps[lastConvStep].delta, 6);
	chartPOGen->ChartAreas[0]->Axes[0]->Interval = intervalX;
	chartPOGen->ChartAreas[0]->Axes[0]->IntervalOffset = intervalX;
	chartPOGen->ChartAreas[0]->Axes[0]->Maximum = poSteps[lastConvStep].delta;

	//x axis 2nd part
	chartPOGen->ChartAreas[1]->Axes[0]->Minimum = poSteps[lastConvStep].delta;
	chartPOGen->ChartAreas[1]->Axes[0]->Crossing = poSteps[lastConvStep].delta;
	double intervalXdrift = intervalChoice(poSteps[lastConvStep].delta,deltaDrift, 3);
	chartPOGen->ChartAreas[1]->Axes[0]->Interval = intervalXdrift;
	chartPOGen->ChartAreas[1]->Axes[0]->IntervalOffset = (ceil(poSteps[lastConvStep].delta/intervalXdrift)*intervalXdrift)-poSteps[lastConvStep].delta;
	chartPOGen->ChartAreas[1]->Axes[0]->Maximum = deltaDrift*1.1;

	//contributions
	chartPOContr->ChartAreas[0]->Axes[0]->Minimum = 0;
	chartPOContr->ChartAreas[0]->Axes[0]->Crossing = 0;
	double intervalX2 = intervalChoice(0 ,	double(contCounter), 7, true);
	chartPOContr->ChartAreas[0]->Axes[0]->Interval = intervalX2;
	chartPOContr->ChartAreas[0]->Axes[0]->IntervalOffset = intervalX2;


	//y axis
	double intervalY = intervalChoice(0 , poSteps[lastConvStep].Vend/1000.0, 6);
	if (poSteps[lastConvStep].Vend>0){
		chartPOGen->ChartAreas[0]->Axes[1]->Minimum = 0;
		chartPOGen->ChartAreas[1]->Axes[1]->Minimum = 0;
	}
	else{
		chartPOGen->ChartAreas[0]->Axes[1]->Maximum = 0;
		chartPOGen->ChartAreas[1]->Axes[1]->Maximum = 0;
		intervalY = - intervalY; 
	}
	chartPOGen->ChartAreas[0]->Axes[1]->Crossing = 0; 
	chartPOGen->ChartAreas[0]->Axes[1]->Interval = intervalY;
	chartPOGen->ChartAreas[0]->Axes[1]->IntervalOffset = intervalY;
	//y axis second part
	chartPOGen->ChartAreas[1]->Axes[1]->Crossing = chartPOGen->ChartAreas[0]->Axes[1]->Crossing;
	chartPOGen->ChartAreas[1]->Axes[1]->Interval = intervalY;
	chartPOGen->ChartAreas[1]->Axes[1]->IntervalOffset = intervalY;

	double intervalY2 = intervalChoice(0 , poSteps[lastConvStep].delta, 6);
	chartPOContr->ChartAreas[0]->Axes[1]->Minimum = 0;
	chartPOContr->ChartAreas[0]->Axes[1]->Crossing = 0; 
	chartPOContr->ChartAreas[0]->Axes[1]->Interval = intervalY2;
	chartPOContr->ChartAreas[0]->Axes[1]->IntervalOffset = intervalY2;

	//annotation lines for yieldpoint
	if(befYieldStep!=-1){
		//vertical
		chartPOGen->Annotations["VLAyield"]->Visible = true;
		chartPOGen->Annotations["VLAyield"]->AnchorDataPoint = chartPOGen->Series[0]->Points[befYieldStep];
		chartPOGen->Annotations["VLAyield"]->Height = 10*poSteps[lastConvStep].Vend/1000.0; //max possible height
		//horizontal
		chartPOGen->Annotations["HLAyield"]->Visible = true;
		chartPOGen->Annotations["HLAyield"]->AnchorDataPoint = chartPOGen->Series[0]->Points[befYieldStep];
		chartPOGen->Annotations["HLAyield"]->Width = - 1000*poSteps[lastConvStep].delta; //max possible height
		//label
		chartPOGen->Annotations["txtYield"]->Visible = true;
		chartPOGen->Annotations["txtYield"]->AnchorDataPoint = chartPOGen->Series[0]->Points[befYieldStep];
	}
	else{
		chartPOGen->Annotations["VLAyield"]->Visible = false;
		chartPOGen->Annotations["HLAyield"]->Visible = false;
		chartPOGen->Annotations["txtYield"]->Visible = false;
	}
		
	//scalebreak on x axis
	//align charts
	
	
	fProg->Hide();
	delete fProg;
}
//---------------------------------------------------------------------------
double Element::evalDesc(){
	
	vDrift = 0.2*((poSteps[lastConvStep]).Vend);
	double tan65 = 2.1445069205095586163562607910459;	
	double Nc = (Naxial<0)?abs(Naxial):0;	
	eDrift = 0.04*(1+pow(tan65,2))/(tan65+Nc*(stirrSp/(nTransSB*Asw*fyStirr*(hw-2*cov)*tan65)));
	deltaDrift = eDrift*Ls;
	return eDrift;
}
//---------------------------------------------------------------------------
bool Element::printResults(const wchar_t *resFilename){
	FILE *fp;

	if ( (fp = _wfopen(resFilename, L"wt")) == NULL )	{
		MessageBox(NULL,L"Cannot create file with specified filename", L"Printing Results to File", MB_OK);
		return false;		// Failed to open file
	}

	double deltaY = poSteps[befYieldStep].delta; 
	fprintf(fp, "Disp(mm);Lat.Load(KN);flexure(mm);flexure(%%);slip(mm);slip(%%);shear(mm);shear(%%);Δy(mm);\n");	
	for (int iStep = 0; iStep < nStepsPO ; iStep++){
		if(poSteps[iStep].convWoV){ 
			fprintf(fp, "%f;%f;%f;%f;%f;%f;%f;%f;%f;\n",
				poSteps[iStep].delta,(poSteps[iStep].Vend/1000),
				poSteps[iStep].deltaFl,100.0*poSteps[iStep].deltaFl/poSteps[iStep].delta,
				poSteps[iStep].deltaPOn,100.0*poSteps[iStep].deltaPOn/poSteps[iStep].delta,
				poSteps[iStep].deltaSh,100.0*poSteps[iStep].deltaSh/poSteps[iStep].delta,
				deltaY);
		}
		else{ //not converging
			fprintf(fp, "%s;%f;\n","not Converging",(poSteps[iStep].Vend/1000));
		}
	}
	//εκτύπωση φθίνοντος κλάδου
	fprintf(fp, "%f;%f;\n",deltaDrift, (vDrift/1000));
															
	fclose(fp);
	return true;
}
//---------------------------------------------------------------------------
int Element::showAnchResults(System::Windows::Forms::DataVisualization::Charting::Chart^  chartAnch, System::Windows::Forms::ComboBox^  cmbChartAnch,	int stepId){
	//when stepId = -1 shows last converging step of Anchorage (first time called)
	if(!anchExists){
		chartAnch->Visible = false;
		return 0;
	}
	
	int step;
	if(stepId == -1){
		//populate combobox
		int lastOne = 0;
		cmbChartAnch->Items->Clear();
		for (int iStep = 1; iStep < nStepsPO ; iStep++){
			if((poSteps[iStep].anchRes) && (poSteps[iStep].myAnch.StrAnch(0)>(2E-6))){ 
				cmbChartAnch->Items->Add(System::Convert::ToString(iStep));
				lastOne = iStep;
			}
		}
		
		if (lastOne>0){
			step = lastOne;
		}
		else{
			chartAnch->Visible = false;
			return 0;
		}
	}
	else{
		step = stepId; 	
	}

	int lbMM = int(ceil(poSteps[step].myAnch.Lb));

	chartAnch->Series["Strain"]->Points->Clear();
	chartAnch->Series["Slip"]->Points->Clear();
	chartAnch->Series["Bond"]->Points->Clear();

	for (int i = 0; i <=lbMM ; i++){ 
		chartAnch->Series["Strain"]->Points->AddXY(poSteps[step].myAnch.x(i),	poSteps[step].myAnch.StrAnch(i));		
		chartAnch->Series["Slip"]->Points->AddXY(poSteps[step].myAnch.x(i),	poSteps[step].myAnch.Slip(i));
		chartAnch->Series["Bond"]->Points->AddXY(poSteps[step].myAnch.x(i),	poSteps[step].myAnch.Bond(i));
	}
	
	//axis fixing
	double intervalX = intervalChoice(0, lbMM, 7);
	
	for (int iCA = 0; iCA <3 ; iCA++){ //loop over chartareas
		//x - axis
		chartAnch->ChartAreas[iCA]->Axes[0]->Minimum = 0;
		chartAnch->ChartAreas[iCA]->Axes[0]->Crossing = 0;
		chartAnch->ChartAreas[iCA]->Axes[0]->Maximum = lbMM;
		chartAnch->ChartAreas[iCA]->Axes[0]->Interval = intervalX;
		chartAnch->ChartAreas[iCA]->Axes[0]->IntervalOffset = intervalX;
		//y - axis
		chartAnch->ChartAreas[iCA]->Axes[1]->Minimum = 0;
		chartAnch->ChartAreas[iCA]->Axes[1]->Crossing = 0;	
	}

	double intervalY[3];
	double maxY[3];
	maxY[0] = poSteps[step].myAnch.StrAnch.maxCoeff();
	intervalY[0] = intervalChoice(0 , maxY[0], 4);
	
	maxY[1] = poSteps[step].myAnch.Slip.maxCoeff();
	intervalY[1] = intervalChoice(0 , maxY[1], 4);

	maxY[2] = poSteps[step].myAnch.Bond.maxCoeff();
	intervalY[2] = intervalChoice(0 , maxY[2], 4);

	for (int iCA = 0; iCA <3 ; iCA++){ 
		chartAnch->ChartAreas[iCA]->Axes[1]->Interval = intervalY[iCA];
		chartAnch->ChartAreas[iCA]->Axes[1]->IntervalOffset = intervalY[iCA];
		if(maxY[iCA]<0.001){
			chartAnch->ChartAreas[iCA]->AxisY->LabelStyle->Format = "#.0E0"; 
		}
		else{
			chartAnch->ChartAreas[iCA]->AxisY->LabelStyle->Format = "";
		}
		if(maxY[iCA]<0.1){
			chartAnch->Series[iCA]->ToolTip="#VALX;#VAL{#.0E0}";		
		}
		else{
			chartAnch->Series[iCA]->ToolTip="#VALX;#VAL{N2}";
		}

	}

	chartAnch->Visible = true;
	return step;
}
//---------------------------------------------------------------------------
bool Element::printAnchResults(const wchar_t *resFilename,int iStep){
	FILE *fp;

	if ( (fp = _wfopen(resFilename, L"wt")) == NULL )	{
		MessageBox(NULL,L"Cannot create file with specified filename", L"Printing Results to File", MB_OK);
		return false;		// Failed to open file
	}

	int lbMM = int(ceil(poSteps[iStep].myAnch.Lb));
	
	fprintf(fp, "Anchor. Length (mm);Strain;Slip (mm);Bond (MPa);\n");	
	for (int i = 0; i <=lbMM ; i++){
			fprintf(fp, "%d;%f;%f;%f;\n",
			poSteps[iStep].myAnch.x(i),	poSteps[iStep].myAnch.StrAnch(i), poSteps[iStep].myAnch.Slip(i), poSteps[iStep].myAnch.Bond(i));
	}
															
	fclose(fp);
	return true;
}
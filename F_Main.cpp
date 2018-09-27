#include "stdafx.h"
#include "F_Main.h"

using namespace Phaethon;
extern Concrete myConcrete;
extern Steel mySteel;
extern mcContainer mySecMC;
extern Algorithm myAlg;
extern Element myCantil;
extern guiInput myGI;
bool decimalComma;
using namespace std;

FILE *fpSave;

//------------------------------------------------------------------------------------------------------------------------------
bool F_Main::assignValuesFromGui(bool pushover, int saveClear){//if pushover false, moment curvature. 
	//saveload stands for assigning values to and from files -1: solving, 1: saving, 2: loading
	
	int bChecks = 1; //multiplied everytime with result. If zero, then false

	// define material properties (N/mm/MPa)
	//Concrete
	bChecks *= inputDoubleFromGui(txtConcFc,myConcrete.fc, saveClear);
	myConcrete.fc = -myConcrete.fc;
	bChecks *= inputDoubleFromGui(txtConcEpc,myConcrete.epc0, saveClear);
	myConcrete.epc0 = -myConcrete.epc0;
	bChecks *= inputDoubleFromGui(txtConcFcr,myConcrete.fcr, saveClear);
	bChecks *= inputDoubleFromGui(txtConcEcr,myConcrete.ecr, saveClear);

	//Reinforcement Longitudinal
	bChecks *= inputDoubleFromGui(txtSteelEs,myConcrete.Es, saveClear);
	bChecks *= inputDoubleFromGui(txtSteelFy,myConcrete.fyx, saveClear);
	//same for steel
	mySteel.Es = myConcrete.Es;
	mySteel.fy  = myConcrete.fyx;
	if(!String::IsNullOrEmpty(txtSteelEh->Text)){ 
		bChecks *= inputDoubleFromGui(txtSteelEh,mySteel.Eh, saveClear);
	}
	else{
		mySteel.Eh = 0.0;
		if(saveClear==1){
			fprintf(fpSave, "txtSteelEh 0.0\n");
		}
	}
	
	//Reinforcement Transversal
	bChecks *= inputDoubleFromGui(txtConcRsy,myConcrete.rsy, saveClear);
	bChecks *= inputDoubleFromGui(txtConcFyy,myConcrete.fyy, saveClear);
	
	//myGI
	myGI.isRect = rbRect->Checked;	 
	if(saveClear==1){
		fprintf(fpSave, "rbRect %d\n",rbRect->Checked?1:0);
	}
	if((rbRect->Checked)||(saveClear == 2)){//rect or to clear
		bChecks *= inputDoubleFromGui(txth,myGI.dInp, saveClear);
		bChecks *= inputDoubleFromGui(txtb,myGI.bInp, saveClear);
		//myGI.nFibersInp has aleady been assigned, is being checked in basic checks
		if (saveClear!=2){
			if(myGI.nFibersInp != (Convert::ToInt32(nmrNMid->Value)+2)){//so has to be equal to fibers otherwise cannot work
				MessageBoxW(NULL,L"Number of Intermediate Reinforcing Steel Bars on One Section Side Parallel to Load has been changed without assigning respective Areas.\nPlease assign respective areas to continue", L"Number of Intermediate Reinforcing Steel Bars", MB_OK);	
				return false;
			}
			if(saveClear==1){
				fprintf(fpSave, "nmrNMid %d\n",Convert::ToInt32(nmrNMid->Value));
				for (int i = 0; i < myGI.nFibersInp; i++){
					fprintf(fpSave, "fAsInp%d %f\n",i,myGI.fAsInp[i]);
				} 
			}
		}
	}
	else if((rbCirc->Checked)||(saveClear == 2)){//circ
		bChecks *= inputDoubleFromGui(txtd,myGI.dInp, saveClear);
		bChecks *= inputIntFromGui(nmrCircNSB,myGI.nBarsInp, saveClear);
		bChecks *= inputDoubleFromGui(txtCircDbar,myGI.dBarInp, saveClear);
	}
		
	bChecks *= inputDoubleFromGui(txtCov,myGI.covInp, saveClear);	
	bChecks *= inputDoubleFromGui(txtSp,myGI.stirrSpInp, saveClear);
	bChecks *= inputDoubleFromGui(txtNumStirLegs,myGI.nTransSBInp, saveClear);			
	double dtStirr;
	bChecks *= inputDoubleFromGui(txtStirrDt,dtStirr, saveClear);	
	myGI.AswInp = M_PI*pow(dtStirr,2)/4;
	//analysis common
	bChecks *= inputIntFromGui(nmrNIPSec,myGI.nIPInp, saveClear);
	bChecks *= inputDoubleFromGui(txtNaxial,myGI.nAxInp, saveClear);	
	myGI.nAxInp*=1000; //kn transformation
	if(rbNaxComp->Checked){
		myGI.nAxInp*=-1;	
	}
	if(saveClear==1){
		fprintf(fpSave, "rbNaxComp %d\n",rbNaxComp->Checked?1:0);
	}


	if(pushover||(saveClear>0)){
		bChecks *= inputDoubleFromGui(txtPOLs,myGI.LsInp, saveClear);
		bChecks *= inputIntFromGui(nmrNPO,myGI.nStepPOInp, saveClear);
		bChecks *= inputDoubleFromGui(txtPushStep,myGI.VStepInp, saveClear);
		myGI.VStepInp*=1000; //kn
		bChecks *= inputIntFromGui(nmrNIPLs,myGI.nSPInp, saveClear);
		//integration of sections always lobatto, so n input
		
		
		myGI.anExistsInp = ckbAnch->Checked;
		if(saveClear==1){
			fprintf(fpSave, "ckbAnch %d\n",ckbAnch->Checked?1:0);
		}
		if((myGI.anExistsInp)||(saveClear==2)){
			bChecks *= inputDoubleFromGui(txtAnchFc,myGI.anfcInp, saveClear);
			bChecks *= inputDoubleFromGui(txtAnchDb,myGI.anDbInp, saveClear);
			bChecks *= inputDoubleFromGui(txtAnchLb,myGI.anLbInp, saveClear);
		}
	}
	if ((!pushover)||(saveClear>0)){//moment-curvature
		bChecks *= inputDoubleFromGui(txtPhiIncr,myGI.dKappaInp, saveClear);
		bChecks *= inputDoubleFromGui(txtGammaIncr,myGI.dGammaInp, saveClear);
		bChecks *= inputIntFromGui(nmrNStepsMC,myGI.nStepsMCInp, saveClear);
	}	
	

	

	//input checks
	if(saveClear<0){
		if (bChecks == 0){
			return false;
		}
		if(!inputChecks()){
			return false;
		}
	}
	return true;
}
//------------------------------------------------------------------------------------------------------------------------------
void F_Main::btnPushoverSolve_Click(System::Object^  sender, System::EventArgs^  e){
	
	if(!assignValuesFromGui(true,-1)){
		return;
	}
	
	myAlg.init();

	// Incrementation phase: apply axial force, curvature and shear
	myCantil.evalPO(myGI, chartPushoverGeneral, chartPushoverContr);

	//anchorage show res (hides and returns if no anchorage)
	int anchResStep = myCantil.showAnchResults(chartAnchorage,cmbChartAnch);	 	
	cmbChartAnch->Visible = (anchResStep>0);
	lblChartAnchStep->Visible = (anchResStep>0);
	cmbChartAnch->Text = Convert::ToString(anchResStep);

}
//------------------------------------------------------------------------------------------------------------------------------
void F_Main::btnMCSolve_Click(System::Object^  sender, System::EventArgs^  e){
	
	if(!assignValuesFromGui(false,-1)){
		return;
	}

	mySecMC.evalMC(myGI, chartMC, chartMCFS);
}
//------------------------------------------------------------------------------------------------------------------------------
void F_Main::rbCirc_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	//enable and disable controls
	lbld->Enabled = rbCirc->Checked;
	txtd->Enabled = rbCirc->Checked;
	lblCircNSB->Enabled = rbCirc->Checked;
	nmrCircNSB->Enabled = rbCirc->Checked;
	lblCircDbar->Enabled = rbCirc->Checked;
	txtCircDbar->Enabled = rbCirc->Checked;

	lblb->Enabled = rbRect->Checked;
	txtb->Enabled = rbRect->Checked;
	lblh->Enabled = rbRect->Checked;
	txth->Enabled = rbRect->Checked;
	lblNMid->Enabled = rbRect->Checked;
	nmrNMid->Enabled = rbRect->Checked;
	btnAreaOfReinfLayers->Enabled = rbRect->Checked;

	//change tooltip for Dt
	if(rbRect->Checked){ //rectangular
		myToolTip->SetToolTip(lblStirrDt, L"Diameter of Stirrups");
		myToolTip->SetToolTip(txtStirrDt, L"Diameter of Stirrups");
	}
	else{	//circular
		myToolTip->SetToolTip(lblStirrDt, L"Diameter of Spiral/Stirrups");
		myToolTip->SetToolTip(txtStirrDt, L"Diameter of Spiral/Stirrups");
	}

	//fix stirrup number to two for circular
	txtNumStirLegs->Enabled = rbRect->Checked;
	if(rbCirc->Checked){ //rectangular
		txtNumStirLegs->Text = L"2";
	}

}
//------------------------------------------------------------------------------------------------------------------------------
void F_Main::ckbAnch_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	
	//inputs
	lblAnchFc->Enabled = ckbAnch->Checked;
	txtAnchFc->Enabled = ckbAnch->Checked;
	lblAnchDb->Enabled = ckbAnch->Checked;
	txtAnchDb->Enabled = ckbAnch->Checked;
	lblAnchLb->Enabled = ckbAnch->Checked;
	txtAnchLb->Enabled = ckbAnch->Checked;

	//results
	tbPPOAnchor->Enabled = ckbAnch->Checked;	
	if((ckbAnch->Checked)&&(tabControlPORes->SelectedIndex==1)){ //an einai epilegmeno to tab mono
		btnSavePOAnch->Enabled = true;
	}
	else{
		btnSavePOAnch->Enabled = false;
	}
}

//------------------------------------------------------------------------------------------------------------------------------
void F_Main::btnAreaOfReinfLayers_Click(System::Object^  sender, System::EventArgs^  e){
	myGI.nFibersPrev = myGI.nFibersInp;
	F_LongReinf ^ formLongReinf = gcnew F_LongReinf(Convert::ToInt32(nmrNMid->Value),myGI.fAsInp,myGI.nFibersPrev);
	
	if(formLongReinf->ShowDialog()== ::DialogResult::OK){
		delete[] myGI.fAsInp;
		myGI.nFibersInp = Convert::ToInt32(nmrNMid->Value)+2;
		myGI.fAsInp = new double[myGI.nFibersInp];
		for (int i = 0; i < myGI.nFibersInp; i++){
			myGI.fAsInp[i]  = formLongReinf->getCell(i,1,decimalComma);
		} 
	}

	delete formLongReinf;
}

//------------------------------------------------------------------------------------------------------------------------------
void F_Main::txtConcFc_Leave(System::Object^  sender, System::EventArgs^  e){
	
	if((txtAnchFc->Text==L"21.1")||(txtAnchFc->Text==L"")){
		txtAnchFc->Text = txtConcFc->Text;
	}

}
//------------------------------------------------------------------------------------------------------------------------------
bool F_Main::inputChecks(){
	if(myConcrete.fc>=0){
		MessageBoxW(NULL,L"Concrete fc must be given a positive value", L"Input Data Error", MB_OK);
		return false;
	}
	if(myConcrete.epc0>=0){
		MessageBoxW(NULL,L"Concrete epc0 must be given a positive value", L"Input Data Error", MB_OK);
		return false;
	}
	if((ckbAnch->Checked) && (myGI.anfcInp<0)){
		MessageBoxW(NULL,L"Anchorage fc must be given a positive value", L"Input Data Error", MB_OK);
		return false;
	}

	return true;
}
//------------------------------------------------------------------------------------------------------------------------------
bool F_Main::inputDoubleFromGui(TextBox^  txtGui, double &num, int saveClear){
	String^ inpText = txtGui->Text;
	if(decimalComma){
		inpText = inpText->Replace(".", ",");
	}
	else{
		inpText = inpText->Replace(",", ".");
	}
	if (saveClear<0){//solution
		if(! Double::TryParse(inpText, num)){
			wstring message = L"The data format of the input given for the following entity is not acceptable:\n"+ 
								SystemStringToWstring(this->myToolTip->GetToolTip(txtGui));

			MessageBoxW(NULL,message.c_str(), L"Input Data Error", MB_OK);
			num = 1.0;
			return false;
		}
		else{
			return true;
		}
	}
	else if(saveClear==1){ //savegui
		fprintf(fpSave, "%s %s\n",txtGui->Name, txtGui->Text);
		return true;
	}
	else if(saveClear==2){ //clear
		txtGui->Text = L"";
		return true;
	}
}
//------------------------------------------------------------------------------------------------------------------------------
bool F_Main::inputIntFromGui(NumericUpDown^  nmrGui, int &inum, int saveClear){
	
	if (saveClear<0){//solution
		inum = Convert::ToInt32(nmrGui->Value);
		return true;
	}
	else if(saveClear==1){
		fprintf(fpSave, "%s %d\n",nmrGui->Name, Convert::ToInt32(nmrGui->Value));
		return true;
	}
	else if(saveClear==2){
		nmrGui->Value = nmrGui->Minimum;
	}
	//no further checks needed, input is protected from control side
}
//------------------------------------------------------------------------------------------------------------------------------
void F_Main::aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e){
	
	f_about ^ f = gcnew f_about();
	
	f->ShowDialog();
	delete f;

}
//------------------------------------------------------------------------------------------------------------------------------
void  F_Main::saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e){
 
	saveFileDialog1->Filter = "Phaethon Input File|*.phn";  
	saveFileDialog1->Title = "Save Phaethon Input File";   
	saveFileDialog1->OverwritePrompt = true;
	saveFileDialog1->InitialDirectory = Environment::GetFolderPath(Environment::SpecialFolder::MyDocuments)+"\\Phaethon\\Inputs";
	saveFileDialog1->FileName = "PhaethonInput.phn";

	if(saveFileDialog1->ShowDialog()== ::DialogResult::OK){
		if ( (fpSave = _wfopen((SystemStringToWstring(saveFileDialog1->FileName).c_str()), L"wt")) == NULL )	{
			MessageBoxW(NULL,L"Cannot create file with specified filename", L"Saving Phaethon Input File", MB_OK);
			return;		// Failed to open file
		}
		//save input attributtes
		assignValuesFromGui(true,1); //pairnoume tis teleftaies times 
		fclose(fpSave);
	}											      
}
//------------------------------------------------------------------------------------------------------------------------------
void  F_Main::openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e){
	
	openFileDialog1->Filter = "Phaethon Input File|*.phn";  
	openFileDialog1->Title = "Load Phaethon Input File";   
	openFileDialog1->InitialDirectory = Environment::GetFolderPath(Environment::SpecialFolder::MyDocuments)+"\\Phaethon\\Examples";
	openFileDialog1->FileName = "Example Rectangular.phn";

	if(openFileDialog1->ShowDialog()== ::DialogResult::OK){
		openFile(openFileDialog1->FileName);	
	}
}
//------------------------------------------------------------------------------------------------------------------------------
void  F_Main::F_Main_Shown(System::Object^  sender, System::EventArgs^  e){
   array<String^>^ arguments = Environment::GetCommandLineArgs();
   if (arguments->Length>1){ 
	   String^ strFileName = arguments[1];
	   openFile(strFileName);
   }   
	
	TCHAR szSep[8];
	GetLocaleInfo(LOCALE_USER_DEFAULT,LOCALE_SDECIMAL,szSep,8);
	wstring point(szSep);

   if(point.compare(L",")==0){
	   decimalComma = true;
   }
   else{
	    decimalComma = false;
   }
}
//------------------------------------------------------------------------------------------------------------------------------
bool  F_Main::openFile(String ^strFileName){
	FILE *fpLoad;
	if ( (fpLoad = _wfopen((SystemStringToWstring(strFileName).c_str()), L"r+")) == NULL ){
		MessageBoxW(NULL,L"Cannot create file with specified filename", L"Saving Phaethon Input File", MB_OK);
		return false;		// Failed to open file
	}
	char buf[1024];
	const char *p;
	char keyword[128], value[64];

	while ( fgets(buf, 1024, fpLoad) )	{
		buf[strlen(buf)-1] = '\0';
		p = buf;
		while ( *p == ' ' || *p == '\t' )	p ++;	// skip spaces
		if	( *p != '#' && *p != '\0' ) { // # is for comments
			assignKeyValue(p,keyword,value);
			if ((strncmp (keyword,"txt",3) == 0)||(strncmp (keyword,"nmr",3) == 0)||(strncmp (keyword,"rb",2) == 0)||(strncmp (keyword,"ckb",3) == 0)){//is control
				String ^strControlName = gcnew String(keyword);
				String ^strValue = gcnew String(value);
				if (!(strControlName->Length == 0 || this->Controls->Find(strControlName, true)->Length == 0)){ //nullptr
					Control^ ctrlPtr = this->Controls->Find(strControlName, true)[0];
					if (strncmp(keyword,"txt",3) == 0){
						TextBox^ txtGui = (TextBox^) ctrlPtr;
						txtGui->Text = strValue;
						delete strValue;
					}
					else if (strncmp (keyword,"nmr",3) == 0){
						NumericUpDown^ nmrGui = (NumericUpDown^) ctrlPtr;
						nmrGui->Value = Convert::ToInt32(strValue);
						if (strncmp(keyword,"nmrNMid",7)==0){//reallocate					
							delete[] myGI.fAsInp;								
							myGI.nFibersInp = Convert::ToInt32(nmrNMid->Value)+2;
							myGI.nFibersPrev = myGI.nFibersInp; //it is like a restart
							myGI.fAsInp = new double[myGI.nFibersInp];
						}
					}
					else if (strncmp(keyword,"rb",2) == 0){	//radiobuttons
						if (strncmp(keyword,"rbRect",6) == 0){
							if((*value)=='1') {
								rbRect->PerformClick();
							}
							else{
								rbCirc->PerformClick();
							}						
						}
						else if(strncmp(keyword,"rbNaxComp",9) == 0){
							if((*value)=='1') {
								rbNaxComp->PerformClick();
							}
							else{
								rbNaxTens->PerformClick();
							}							
						}
					}
					else if (strncmp(keyword,"ckb",3) == 0){
						CheckBox^ ckbGui = (CheckBox^) ctrlPtr;
						ckbGui->Checked = ((*value)=='1');
					}
				}
				delete strControlName;
				delete strValue;
			}//end of control
			else{
				if (strncmp(keyword,"fAsInp",6)==0){
					myGI.fAsInp[atoi(keyword+6)] = atof(value);
				}
			}
		}//end of not comment
	}// end of while buffer

	fclose(fpLoad);
	return true;
}
//------------------------------------------------------------------------------------------------------------------------------
void  F_Main::tabControlInput_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e){
	tabControlResults->SelectedIndex = tabControlInput->SelectedIndex;
}
//------------------------------------------------------------------------------------------------------------------------------
void  F_Main::tabControlPORes_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e){
	if(tabControlPORes->SelectedIndex==0){//general po results selected
		btnSavePOGen->Enabled = true;
		btnSavePOAnch->Enabled = false;
	}
	else if(tabControlPORes->SelectedIndex==1){//anchorage po results selected
		btnSavePOGen->Enabled = false;
		if(ckbAnch->Checked){//an einai apenergopoiimeno to anchorage na min anoigei
		btnSavePOAnch->Enabled = true;
		}
	}	
}
//------------------------------------------------------------------------------------------------------------------------------
void  F_Main::tabControlResults_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e){
	btnSaveMC->Enabled = (tabControlResults->SelectedIndex==1);
	tabControlInput->SelectedIndex = tabControlResults->SelectedIndex;
}

//------------------------------------------------------------------------------------------------------------------------------
void  F_Main::btnSavePOGen_Click(System::Object^  sender, System::EventArgs^  e){
	if(!myCantil.isInized()){
		MessageBoxW(NULL,L"There are no Pushover Analysis Results available to save", L"Saving Phaethon Pushover Analysis Results", MB_OK);	
		return;
	}
	
	saveFileDialog1->Filter = "Phaethon Results File|*.txt";  
	saveFileDialog1->Title = "Save Phaethon General Pushover Analysis Results";   
	saveFileDialog1->OverwritePrompt = true;
	saveFileDialog1->InitialDirectory = Environment::GetFolderPath(Environment::SpecialFolder::MyDocuments)+"\\Phaethon\\Results";
	saveFileDialog1->FileName = "Phaethon_Pushover_Load_Displacement_Results.txt";

	if(saveFileDialog1->ShowDialog()== ::DialogResult::OK){
		myCantil.printResults(SystemStringToWstring(saveFileDialog1->FileName).c_str());
	}								
}
//------------------------------------------------------------------------------------------------------------------------------
void  F_Main::btnSavePOAnch_Click(System::Object^  sender, System::EventArgs^  e){
	if((!myCantil.isInized())||(cmbChartAnch->Text=="")){
		MessageBoxW(NULL,L"There are no Pushover Anchorage Results available to save", L"Saving Phaethon Pushover Anchorage Results", MB_OK);
		return;
	}
	saveFileDialog1->Filter = "Phaethon Results File|*.txt";  
	saveFileDialog1->Title = "Save Phaethon Pushover Anchorage Results";   
	saveFileDialog1->OverwritePrompt = true;
	saveFileDialog1->InitialDirectory = Environment::GetFolderPath(Environment::SpecialFolder::MyDocuments)+"\\Phaethon\\Results";
	saveFileDialog1->FileName = "Phaethon_Pushover_Anchorage_Results_Step_"+cmbChartAnch->Text+".txt";

	if(saveFileDialog1->ShowDialog()== ::DialogResult::OK){
		myCantil.printAnchResults(SystemStringToWstring(saveFileDialog1->FileName).c_str(),Convert::ToInt32(cmbChartAnch->Text));
	}								
}
//------------------------------------------------------------------------------------------------------------------------------
void  F_Main::btnSaveMC_Click(System::Object^  sender, System::EventArgs^  e){
	if(!mySecMC.isInized()){
		MessageBoxW(NULL,L"There are no Moment - Curvature Results available to save", L"Saving Moment - Curvature Results", MB_OK);	
		return;
	}
	
	saveFileDialog1->Filter = "Phaethon Results File|*.txt";  
	saveFileDialog1->Title = "Save Phaethon  Moment - Curvature Results";   
	saveFileDialog1->OverwritePrompt = true;
	saveFileDialog1->InitialDirectory = Environment::GetFolderPath(Environment::SpecialFolder::MyDocuments)+"\\Phaethon\\Results";
	saveFileDialog1->FileName = "Phaethon_Moment_Curvature_Results.txt";

	if(saveFileDialog1->ShowDialog()== ::DialogResult::OK){
		mySecMC.printMCResults(SystemStringToWstring(saveFileDialog1->FileName).c_str());
	}			
}
//------------------------------------------------------------------------------------------------------------------------------
void  F_Main::newToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e){
	GUIClear();
}
//------------------------------------------------------------------------------------------------------------------------------
void  F_Main::GUIClear(){
	
	rbRect->PerformClick();
	rbNaxComp->PerformClick();
	ckbAnch->Checked = true;
	
	assignValuesFromGui(true,2);//using the Clear mode for textboxes and numberboxes (the alternative was to loop over all controls but would be too slow)	
	myGI.fAsClear();
	
	//hide charts
	chartPushoverGeneral->Visible = false;
	chartPushoverContr->Visible = false;
	chartAnchorage->Visible = false;
	cmbChartAnch->Items->Clear();
	cmbChartAnch->Visible = false;
	lblChartAnchStep->Visible = false;
	chartMC->Visible = false;
	chartMCFS->Visible = false;
}
//------------------------------------------------------------------------------------------------------------------------------
void  F_Main::cmbChartAnch_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	myCantil.showAnchResults(chartAnchorage,cmbChartAnch,Convert::ToInt32(cmbChartAnch->Text));	 	
}

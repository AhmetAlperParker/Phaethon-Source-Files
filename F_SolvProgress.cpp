#include "StdAfx.h"
#include "F_SolvProgress.h"

using namespace Phaethon;

//--------------------------------------------------------------------------------------------------------
F_SolvProgress::F_SolvProgress(bool pushover, int nSteps, int nSecs){
	InitializeComponent();
	//section attributes visible only for pushover
	lblSection->Visible = pushover;
	prbSection->Visible = pushover;

	this->Text = pushover?L"Phaethon Pushover Solution Progress":L"Phaethon Moment-Curvature Solution Progress";
	this->Height  = pushover? 173:112;

	String^ strnSteps = L"Step 0/"+Convert::ToString(nSteps);
	this->lblStep->Text = strnSteps;
	prbStep->Maximum = nSteps;

	if(pushover){
		String^ strnSecs = L"Section 0/"+Convert::ToString(nSecs);
		this->lblSection->Text = strnSecs;
		prbSection->Maximum = nSecs;
	}

}
//---------------------------------------------------------------------------------------------------------
void F_SolvProgress::updStep(int iStep){
	HWND hWnd;
	System::String^ strnSteps = L"Step "+System::Convert::ToString(iStep)+L"/"+System::Convert::ToString(prbStep->Maximum);
	lblStep->Text = strnSteps;
	Refresh();
	//cheating on the defect bar
	if((iStep+1)>prbStep->Maximum){
		int oldMax = prbStep->Maximum; 
		prbStep->Maximum = iStep+1;
		prbStep->Value = iStep+1;
		prbStep->Maximum = oldMax;
	}
	else{
		prbStep->Value = iStep+1;
	}

	prbStep->Value = iStep;
	Refresh();
	UpdateWindow(hWnd);
}
//---------------------------------------------------------------------------------------------------------
void F_SolvProgress::updSec(int iSec){
	HWND hWnd;
	System::String^ strnSecs = L"Section "+System::Convert::ToString(iSec)+L"/"+System::Convert::ToString(prbSection->Maximum);
	lblSection->Text = strnSecs;
	Refresh();
	//cheating on the defect bar
	if((iSec+1)>prbSection->Maximum){
		int oldMax = prbSection->Maximum; 
		prbSection->Maximum = iSec+1;
		prbSection->Value = iSec+1;
		prbSection->Maximum = oldMax;
	}
	else{
		prbSection->Value = iSec+1;
	}

	prbSection->Value = iSec;
	Refresh();
	UpdateWindow(hWnd);
}
//---------------------------------------------------------------------------------------------------------
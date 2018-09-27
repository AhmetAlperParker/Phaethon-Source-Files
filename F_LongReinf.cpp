#include "StdAfx.h"
#include "F_LongReinf.h"
using namespace Phaethon;
using namespace std;

//------------------------------------------------------------------------------------------------------------------------------
F_LongReinf::F_LongReinf(int nMidFibers, double* fAs, int nprev){
	InitializeComponent();
	
	gridRectLonginReinf->Rows->Add("Astop");
	for (int i = 0; i < nMidFibers; i++){
		string rowTitle = "As"+to_string(static_cast<long long>(i+1));
		gridRectLonginReinf->Rows->Add("AsInter"+(i+1));
	}
	gridRectLonginReinf->Rows->Add("Asbottom");

	//adjust height
	double grdTotalHeight = 0;
	for(int j = 0; j < gridRectLonginReinf->Rows->Count; j++) {
		grdTotalHeight = grdTotalHeight + gridRectLonginReinf->Rows[j]->Height;
	}
	gridRectLonginReinf->Height = grdTotalHeight + 36;
	this->Height = gridRectLonginReinf->Height + 60;

	//populate cells
	gridRectLonginReinf->Rows[0]->Cells[1]->Value = fAs[0]; //upper
	gridRectLonginReinf->Rows[nMidFibers+1]->Cells[1]->Value = fAs[nprev-1]; //lower

	if(nMidFibers>0){
		for(int k = 1; k < (nprev-1); k++){ //populate mask me ta palia
			gridRectLonginReinf->Rows[k]->Cells[1]->Value = fAs[k];
			if (k == nMidFibers){//an einai ligotera apo ta proigoumena, den oloklironetai to population
				break;
			}
		}

		if(nMidFibers+2>nprev){//an einai perissotera apo ta proigoumena, antigrafoume teleftaia endiamesi seira
			for(int ii = (nprev-1); ii <= nMidFibers; ii++){
				gridRectLonginReinf->Rows[ii]->Cells[1]->Value = fAs[nprev-2];
			}
		}
	}
	
	
}
//------------------------------------------------------------------------------------------------------------------------------
double F_LongReinf::getCell(int iRow, int iCol, bool decimalComma){ 
	double res;
	String^ inpText = gridRectLonginReinf->Rows[iRow]->Cells[iCol]->Value->ToString();

	if(decimalComma){
		inpText = inpText->Replace(".", ",");
	}
	else{
		inpText = inpText->Replace(",", ".");
	}
	
	if(! Double::TryParse(inpText, res)){
		wstring strRow = to_wstring(static_cast<long long>(iRow));

		wstring message = L"The data format of the input given for the fiber "+strRow +L" of the Reinforcement is not acceptable";
		MessageBoxW(NULL,message.c_str(), L"Input Data Error", MB_OK);
		return -20;
	}
	else{
		return res;
	}

	
}
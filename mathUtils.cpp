#include "stdafx.h"
#include "mathUtils.h"

//-----------------------------------------------------------------
int sgn(double x){
	return (x > 0) - (x < 0);
}
//-----------------------------------------------------------------
int sgn(int x){
	return (x > 0) - (x < 0);
}
//-----------------------------------------------------------------
void MidpointRect(VectorXd &xIP, VectorXd &weight, int nIP){
	/*   MIDPOINT locations and weights for midpoint integration rule    
	[XIP,WEIGHT] = MIDPOINT (NIP)
	function determines the locations in the interval -1<x<1 and the weights
	of the midpoint integration scheme for NIP integration points;
	the locations are reported in vector XIP and the weights in vector WEIGHT */

	double dxi    = 2.0/nIP;
	double xibeg  = -1 + dxi/2;
	double xiend  =  1 - dxi/2;
	double wght   = dxi;
	weight.setOnes(); 
	weight = wght*weight;

	xIP    =  VectorXd::LinSpaced(nIP,xibeg,xiend); 
}
//-----------------------------------------------------------------
void MidpointCirc(VectorXd &yfib, VectorXd &wfib, int nLayers, double d){

	double r = 0.5*d;
	double dy   = d/nLayers;                // layer thickness for equal division
	double ystr = -r + 0.5*dy;
	double yend =  r - 0.5*dy;

	yfib = VectorXd::LinSpaced(nLayers,ystr,yend);

	for (int i = 0; i < nLayers ; i++){	//pithanos na mporouse na ginei kai eniaia alla itan poly manouvra
		wfib(i) = 2*sqrt(pow(r,2)-pow(yfib(i),2))*dy;	
	}

}
//-----------------------------------------------------------------
void Lobatto(VectorXd &xIP, VectorXd &weight, int nIP){

	/*  function [xIP,weight] = Lobatto (nIP)
	LOBATTO  locations and weights of Gauss-Lobatto integration scheme    
	[XIP,WEIGHT] = LOBATTO (NIP)
	the function determines the locations and weights of the Gauss-Lobatto integration scheme
	in the interval -1<x<1 for NIP (2-10) integration points; 
	the locations are reported in vector XIP and the weights in vector WEIGHT from x=-1 to x=1 */

	xIP.resize(nIP);
	weight.resize(nIP);
	switch ( nIP ) {
	case 2:
		xIP(0) = -1.0;
		xIP(1) = 1.0;

		weight(0) = 1.0;
		weight(1) = 1.0;
		break;
	case 3:
		xIP(0)  =  -1.0;
		xIP(1)  =  0.0;
		xIP(2)  =  1.0;

		weight(0) =  1.0 / 3.0;
		weight(1) =  4.0 / 3.0;
		weight(2) =  1.0 / 3.0;
		break;
	case 4:
		xIP(0)  =  - 1.0;
		xIP(1)  =  - 0.447213595499957939281834733746;
		xIP(2)  =    0.447213595499957939281834733746;
		xIP(3)  =    1.0;

		weight(0) =  1.0 / 6.0;
		weight(1) =  5.0 / 6.0;
		weight(2) =  5.0 / 6.0;
		weight(3) =  1.0 / 6.0;
		break;
	case 5:
		xIP(0)  =  - 1.0;
		xIP(1)  =  - 0.654653670707977143798292456247;
		xIP(2)  =    0.0;
		xIP(3)  =    0.654653670707977143798292456247;
		xIP(4)  =    1.0;

		weight(0) =  9.0 / 90.0;
		weight(1) = 49.0 / 90.0;
		weight(2) = 64.0 / 90.0;
		weight(3) = 49.0 / 90.0;
		weight(4) =  9.0 / 90.0;
		break;
	case 6:
		xIP(0)  =  - 1.0;
		xIP(1)  =  - 0.765055323929464692851002973959;
		xIP(2)  =  - 0.285231516480645096314150994041;
		xIP(3)  =    0.285231516480645096314150994041;
		xIP(4)  =    0.765055323929464692851002973959;
		xIP(5)  =    1.0;

		weight(0) =  0.066666666666666666666666666667;
		weight(1) =  0.378474956297846980316612808212;
		weight(2) =  0.554858377035486353016720525121;
		weight(3) =  0.554858377035486353016720525121;
		weight(4) =  0.378474956297846980316612808212;
		weight(5) =  0.066666666666666666666666666667;
		break;
	case 7:
		xIP(0)  =  - 1.0;
		xIP(1)  =  - 0.830223896278566929872032213967;
		xIP(2)  =  - 0.468848793470714213803771881909;
		xIP(3)  =    0.0;
		xIP(4)  =    0.468848793470714213803771881909;
		xIP(5)  =    0.830223896278566929872032213967;
		xIP(6)  =    1.0;

		weight(0) =  0.476190476190476190476190476190e-1;
		weight(1) =  0.276826047361565948010700406290;
		weight(2) =  0.431745381209862623417871022281;
		weight(3) =  0.487619047619047619047619047619;
		weight(4) =  0.431745381209862623417871022281;
		weight(5) =  0.276826047361565948010700406290;
		weight(6) =  0.476190476190476190476190476190e-1;
		break;
	case 8:
		xIP(0)  =  - 1.0;
		xIP(1)  =  - 0.871740148509606615337445761221;
		xIP(2)  =  - 0.591700181433142302144510731398;
		xIP(3)  =  - 0.209299217902478868768657260345;
		xIP(4)  =    0.209299217902478868768657260345;
		xIP(5)  =    0.591700181433142302144510731398;
		xIP(6)  =    0.871740148509606615337445761221;
		xIP(7)  =    1.0;

		weight(0) =  0.357142857142857142857142857143e-1;
		weight(1) =  0.210704227143506039382991065776;
		weight(2) =  0.341122692483504364764240677108;
		weight(3) =  0.412458794658703881567052971402;
		weight(4) =  0.412458794658703881567052971402;
		weight(5) =  0.341122692483504364764240677108;
		weight(6) =  0.210704227143506039382991065776;
		weight(7) =  0.357142857142857142857142857143e-1;
		break;
	case 9:
		xIP(0) =  - 1.0;
		xIP(1) =  - 0.899757995411460157312345244418;
		xIP(2) =  - 0.677186279510737753445885427091;
		xIP(3) =  - 0.363117463826178158710752068709;
		xIP(4) =    0.0;
		xIP(5) =    0.363117463826178158710752068709;
		xIP(6) =    0.677186279510737753445885427091;
		xIP(7) =    0.899757995411460157312345244418;
		xIP(8) =    1.0;

		weight(0) =  0.277777777777777777777777777778e-1;
		weight(1) =  0.165495361560805525046339720029;
		weight(2) =  0.274538712500161735280705618579;
		weight(3) =  0.346428510973046345115131532140;
		weight(4) =  0.371519274376417233560090702948;
		weight(5) =  0.346428510973046345115131532140;
		weight(6) =  0.274538712500161735280705618579;
		weight(7) =  0.165495361560805525046339720029;
		weight(8) =  0.277777777777777777777777777778e-1;
		break;
	case 10:
		xIP(0)  =  - 1.0;
		xIP(1)  =  - 0.919533908166458813828932660822;
		xIP(2)  =  - 0.738773865105505075003106174860;
		xIP(3)  =  - 0.477924949810444495661175092731;
		xIP(4)  =  - 0.165278957666387024626219765958;
		xIP(5)  =    0.165278957666387024626219765958;
		xIP(6)  =    0.477924949810444495661175092731;
		xIP(7)  =    0.738773865105505075003106174860;
		xIP(8)  =    0.919533908166458813828932660822;
		xIP(9) =    1.0;

		weight(0) =  0.222222222222222222222222222222e-1;
		weight(1) =  0.133305990851070111126227170755;
		weight(2) =  0.224889342063126452119457821731;
		weight(3) =  0.292042683679683757875582257374;
		weight(4) =  0.327539761183897456656510527917;
		weight(5) =  0.327539761183897456656510527917;
		weight(6) =  0.292042683679683757875582257374;
		weight(7) =  0.224889342063126452119457821731;
		weight(8) =  0.133305990851070111126227170755;
		weight(9) = 0.222222222222222222222222222222e-1;
		break;
	default:
		MessageBox(NULL,L"integration order not supported", L"Lobatto Integration", MB_OK);
	}

}
//-----------------------------------------------------------------
double RightDivide(double K, double S){
	return S/K;
}
//-----------------------------------------------------------------
void RightDivideMV2(const double* ks, const double* S, double* De){
	
	int r1,r2;
	double a21, a22;

	if (fabs(ks[1]) > fabs(ks[0])) {
		r1 = 1;
		r2 = 0;
	} 
	else {
		r1 = 0;
		r2 = 1;
	}

	a21 = ks[r2] / ks[r1];
	a22 = ks[2 + r2] - a21 * ks[2 + r1];

	De[1] = (S[r2] - S[r1] * a21) / a22;
	De[0] = (S[r1] - De[1] * ks[2 + r1]) / ks[r1];
}
//-----------------------------------------------------------------
Vector3d RightDivideMV3(const Matrix3d K, const Vector3d Divider)
{
	double A[9];
	double KLin[9];
	double ResLin[3];
	Vector3d Result;

	int r1;
	int r2;
	int r3;
	double maxval;
	double a21;
	int rtemp;

	for (int i = 0; i < 3 ; i++){
		for (int j=0; j < 3; j++){
			KLin[i*3+j] = K(i,j);
			A[i*3+j]=KLin[i*3+j];	
		}
	}

	r1 = 0;
	r2 = 1;
	r3 = 2;
	maxval = fabs(KLin[0]);
	a21 = fabs(KLin[1]);
	if (a21 > maxval) {
		maxval = a21;
		r1 = 1;
		r2 = 0;
	}

	if (fabs(KLin[2]) > maxval) {
		r1 = 2;
		r2 = 1;
		r3 = 0;
	}

	A[r2] = KLin[r2] / KLin[r1];
	A[r3] /= A[r1];
	A[3 + r2] -= A[r2] * A[3 + r1];
	A[3 + r3] -= A[r3] * A[3 + r1];
	A[6 + r2] -= A[r2] * A[6 + r1];
	A[6 + r3] -= A[r3] * A[6 + r1];
	if (fabs(A[3 + r3]) > fabs(A[3 + r2])) {
		rtemp = r2;
		r2 = r3;
		r3 = rtemp;
	}

	A[3 + r3] /= A[3 + r2];
	A[6 + r3] -= A[3 + r3] * A[6 + r2];
	ResLin[0] = Divider[r1];
	ResLin[1] = Divider[r2] - ResLin[0] * A[r2];
	ResLin[2] = (Divider[r3] - ResLin[0] * A[r3]) - ResLin[1] * A[3 + r3];
	ResLin[2] /= A[6 + r3];
	ResLin[0] -= ResLin[2] * A[6 + r1];
	ResLin[1] -= ResLin[2] * A[6 + r2];
	ResLin[1] /= A[3 + r2];
	ResLin[0] -= ResLin[1] * A[3 + r1];
	ResLin[0] /= A[r1];

	for (int ii=0; ii < 3 ; ii++){
		Result(ii) = ResLin[ii];
	}

	return Result;

}
//---------------------------------------------------------------------------
void mDebug(Vector3d vec3, double* v3d ){
	for (int i=0;i<3;i++){
		v3d[i]=vec3(i);
	}
}
//---------------------------------------------------------------------------
void m3Debug(Matrix3d mat3, double** m3d ){
	for (int i=0;i<3;i++){
		for (int j=0;i<3;i++){
			m3d[i][j]=mat3(i,j);
		}
	}	
}
//---------------------------------------------------------------------------
bool myIsnan(double x) { 
	return x != x; 
}
//---------------------------------------------------------------------------
bool myIsinf(double x) { 
	return ((!myIsnan(x)) && (myIsnan(x - x))); 
}
//---------------------------------------------------------------------------
VectorXd GaussianSmooth(const VectorXd input, int filterN, bool firstZero){
	int inpSize = input.size();
	
	if (inpSize<filterN){
		if(debugMsg){
			MessageBox(NULL,L"Vector too short", L"Gaussian smoothing", MB_OK);
		}
		return  input;
	}
	else{
		VectorXd Output;
		int outSize = inpSize-(filterN-1);
		Output.resize(outSize);
		if(firstZero){
			Output(0) = 0; //=input(0)
		}

		for (int i = 1*(firstZero); i < outSize; i++){
			double sumInp = 0;
			for (int k = 0; k < filterN; k++){
				sumInp = sumInp + input(i+k);
			}
			Output(i) = sumInp/filterN;
		}
		return  Output;
	}

}
//---------------------------------------------------------------------------
wstring SystemStringToWstring(System::String^ input){
		
		using namespace System::Runtime::InteropServices;
		const char* strInter = (const char*) (Marshal::StringToHGlobalAnsi(input)).ToPointer();
		const size_t cSize = strlen(strInter)+1;
		
		wstring wstrInter( cSize, L'#' );
		mbstowcs( &wstrInter[0], strInter, cSize );
		return wstrInter;
}
//--------------------------------------------------------------------------
void assignKeyValue(const char *p, char keyword[64], char *value){
	int iCounter = 0;
	while ((*p != ' ') && (*p != '\t')&& (*p != '\n')){
		keyword[iCounter] = *p;
		iCounter++;
		p ++;
	}
	keyword[iCounter] = '\0';
	while ( *p == ' ' || *p == '\t' )	p ++;	// skip spaces
	
	int iCounter2 = 0;
	while ((*p != ' ') && (*p != '\t')&& (*p != '\n')&& (*p != '\0')){
		value[iCounter2] = *p;
		iCounter2++;
		p ++;
	}
	value[iCounter2] = '\0';
}
//--------------------------------------------------------------------------
double intervalChoice( double minValue, double maxValue, int intervalNum, bool intsOnly){
	//να χωράνε η minValue και η maxValue, και να είμαστε στο 1,2,5,10,20,50,100 κλπ ως τιμές
	double interm = fabs(maxValue-minValue)/double(intervalNum);
	
	if (interm <= 0.000001){
		return 0.000001;
	}
	else if  ((interm <= 1)&&(intsOnly)){
		return 1;
	}
	
	double stdIntervs[28] = {0.000001,0.000002,0.000005,0.00001,0.00002,0.00005,
							0.0001,0.0002,0.0005,0.001,0.002,0.005,0.01, 0.02, 0.05,
							0.1, 0.2, 0.5, 1,2,5,10,20,50,100,200,500,1000};

	for (int i =  (intsOnly)?18:0 ; i < 28; i++){
		if (( interm >= stdIntervs[i]) && (interm<=stdIntervs[i+1])){
			if ((stdIntervs[i+1]-interm)>= (interm - stdIntervs[i])){//closer to down
				return stdIntervs[i];
			}
			else{//closer to up
				return stdIntervs[i+1];
			}
		}
	}
}
//general utilities
/*//output to file
	PWSTR mydocsPath = NULL;
	HRESULT hr = SHGetKnownFolderPath(FOLDERID_Documents, 0, NULL, &mydocsPath);	
	wstring strMyDocsPath(mydocsPath);
	CoTaskMemFree(mydocsPath);*/
//---------------------------------------------------------------------------
#include "stdafx.h"
#include "Section.h"


//ylika
Concrete myConcrete;
Steel mySteel;


Section mySection; 

//---------------------------------------------------------------------------
double Layer::MCFTlayerCon(double eInt, double Ec, double eyx, int eRedID, bool materialLaw){
	//function [sigc] = MCFTlayerCon(e,Ec,fc,ec,ecr,fcr,eyx,e1)
	//Functions determines the reinforced concrere fiber stress given the
	//strain from the fiber section - Concrete Constitutive Law
	double sigc;
	sigcEnd = false; //setting false because can be that procedure does not converge to latest time when it was true

	if (eInt>=0){
		if (eInt <= myConcrete.ecr){
			sigc = Ec*eInt;
		}
		else if ((eInt>myConcrete.ecr) && (eInt<= eyx)){
			sigc = myConcrete.fcr/(1 + sqrt(200*eInt));
		}
		else{
			sigc = 0;
		}
	} 
	else { //e<0
		if (!materialLaw){ //general case			
			double eReduc;
			if(eRedID==1){ //e reduction id
				eReduc = e1;
			}
			else if(eRedID==2){ 
				eReduc = e2;
			}
			else{
				if(debugMsg){
					MessageBox(NULL,L"Given Reduction id not known", L"Compressive strength reduction", MB_OK);
				}
			}

			double fc2max = myConcrete.fc/(0.8 - 0.34*(eReduc/myConcrete.epc0));
			if ((eReduc<0)||(abs(fc2max) > abs(myConcrete.fc))){ //e1 must be always positive and fc2max cannot exceed fc
				fc2max = myConcrete.fc; //always negative
			} 
			sigc = fc2max*(2*(eInt/myConcrete.epc0) - pow((eInt/myConcrete.epc0),2));
		}
		else{	//when sent here from material law
			sigc = myConcrete.fc*(2*(eInt/myConcrete.epc0) - pow((eInt/myConcrete.epc0),2));	//  sig = fc*(2*(ecx/ec) - (ecx/ec)^2);
		}
		if (eInt <= 2*myConcrete.epc0){
			sigc = 0; 
			sigcEnd = true;	//praktika exoume piasei to telos tou nomou tou ylikou
		}
	}
	
	return sigc;
}
//---------------------------------------------------------------------------
double Layer::compEmTan(double eInt, double Ec, double eyx){
	if (eInt>=0){ //efelkysmos
		if (eInt <= myConcrete.ecr){
				Em = Ec;
		}
		else if ((eInt>myConcrete.ecr) && (eInt<= eyx)){
			Em = - (5*sqrt(2.0)*myConcrete.fcr)/(sqrt(eInt)*pow((10*sqrt(2.0)*sqrt(eInt) + 1),2));
		}
	}
	else{//thlipsi
		Em =  abs(myConcrete.fc)*((2/abs(myConcrete.epc0)) - ((2*abs(ecx))/(pow(abs(myConcrete.epc0),2))));
	}
	return Em;
}
//---------------------------------------------------------------------------
double Layer::MCFTlayer(double thIn){

	double Ec = (2*myConcrete.fc)/myConcrete.epc0;        // initial tangent modulus
	double eyx = myConcrete.fyx / myConcrete.Es;
	double eyy = myConcrete.fyy/myConcrete.Es;
	double ang = M_PI/2 - thIn;

	ex = ecx;
	e1 = ecx + (gxy*tan(ang))/2;
	ey = e1 -  gxy/(2*tan(ang));
	e2 = ex + ey - e1;
	
	fc1 = MCFTlayerCon(e1, Ec, eyx, 2); 
	fc2 = MCFTlayerCon(e2,Ec,eyx, 1); 
	if (abs(ey) < eyy){
		fsy  = myConcrete.Es*ey ;
	}
	else{
		fsy = sgn(ey)*myConcrete.fyy;
	}

	fcy = -myConcrete.rsy*fsy;
	tao = (fcy - fc2)/(tan(ang));
	sig = fc1 - tao*tan(ang);
	if(abs(gxy)<1E-15){	//(gxy==0)
		Gm = 0;
	}
	else{
		Gm = tao/gxy;
	}

	if(abs(ex)<1E-15){	//(ex==0)
		Em = 0;
	}
	else{
		Em = sig/ex; 
	} 
	
	double thInN = atan((fc1-fcy)/tao);

	double thInNormal = thIn; int q;
    if (thInNormal>0.5*M_PI){
       q = int(ceil((thInNormal-0.5*M_PI)/M_PI));
       thInNormal = thInNormal-q*M_PI; 
	}
    else if (thInNormal<-0.5*M_PI){
       q = int(ceil((abs(thInNormal)-0.5*M_PI)/M_PI));
       thInNormal = thInNormal+q*M_PI;  
	}

	return thInN - thInNormal; 
}
//---------------------------------------------------------------------------
void Steel::eval(double epsi,double &sig,double &Em){
	// MCFT_Steel  uniaxial bilinear elastic stress-strain relation
	//  [SIG,ET] = BILINEARELASTIC (MATDATA,EPSI)
	//  the function determines the stress SIG and the tangent modulus ET for given total strain EPSI
	//  for a uniaxial bilinear elastic material;
	//auxiliary terms
	double epsy = fy/Es;         // yield strain

	// material state determination: stress and modulus for total strain epsi
	// branch switching
	if ((epsi <= epsy) && (epsi >= -epsy)){   // pre-yield linear branch
		sig = Es*epsi;
		Em  = Es;
	}
	else if (epsi <-epsy){					  // post-yield linear branch in compression
		sig = -fy + (epsi+epsy)*Eh;
		Em  = Eh;
	}
	else{									  // post-yield linear branch in tension
		sig =  fy + (epsi-epsy)*Eh;
		Em  =  Eh;
	}
}
//---------------------------------------------------------------------------
void Fiber::steelEval(){
	mySteel.eval(epsi, sig, Em);
}
//---------------------------------------------------------------------------
void Bar::steelEval(){
	mySteel.eval(epsi, sig, Em);
}
//---------------------------------------------------------------------------
bool Layer::concEval(){ 
	//function [sig,Em,tao,Gm,MatPost] = MCFT_Concrete(MatData,ecx,gxy,theta)
	// Concrete Material State Determination: stress and modulus returns true if convergence is achieved

	double thcA = 0.5*theta;
	double thcB = 3*theta;
	double thcC;
	double dthcA, dthcB; 

	bool ConvFlag = false;
	bool returnFlag = false;
	bool signChange = false;
	int number = 1; 
	double tol = 1e-6;


	while ((!signChange)&&(!ConvFlag)){ 
		number = number + 1;
		if(number>1000){
			if (debugMsg){
				MessageBox(NULL,L"Could not track sign change after 1000 attempts", L"Calculating Concrete Layer", MB_OK);
			}			
			return false; //break possible eternal loop
		}

		//forcing thcA, thcB to be in [=0.5pi,0.5pi]

		if(thcA>0.5*M_PI){ 
			thcA = 0.5*M_PI;
		}
		else if(thcA<-0.5*M_PI){
			thcA = -0.5*M_PI;
		}
		
		if (thcB>0.5*M_PI){
			thcB = 0.5*M_PI;
		}
		else if(thcB<-0.5*M_PI){
			thcB = -0.5*M_PI;
		}  

		dthcA = MCFTlayer(thcA); 
		if (abs(dthcA)< tol){
			angIt = thcA;
			ConvFlag = true ;
			continue;
		}
		dthcB = MCFTlayer(thcB);
		if (abs(dthcB)< tol){
			angIt = thcB;
			ConvFlag = true ;
			continue;
		}

		if (dthcB*dthcA >0){
			thcB = M_PI/2 - 0.1*number ;
			continue;
		}
		else{
			signChange = true;
		}

	}


	//regular falsi 
	int insMaxIter = 100;
	ConvFlag = RegularFalsiLayer(&Layer::MCFTlayer,thcA,thcB,tol,insMaxIter,thcC,returnFlag); 

	if (ConvFlag||returnFlag){
		angIt = thcC;
	}
	else{
		 //2nd convergence flag for bisection
		ConvFlag = BisectionLayer(&Layer::MCFTlayer,thcA,thcB,tol,insMaxIter,thcC,returnFlag); 
		if (ConvFlag||returnFlag){//to return gyrnaei kai to conv anagkastika mes sti bisection
			angIt = thcC;
		} //end of bisection if conv
	}//end of r-f if conv


	 //efarmozetai katastatikos nomos kathws edw egklwvizetai sinithos. efarmozetai gia oles tis periptwseis toy Bolzano return, 
	// kai gia tis krisimes gonies
	if (((abs(fcy - fc2)<1E-6)||(abs(angIt)<1E-6)||(abs(angIt-0.5*M_PI)<1E-6))||(returnFlag)){ 	
			double Ec = (2*myConcrete.fc)/myConcrete.epc0;
			double eyx = myConcrete.fyx / myConcrete.Es;
			sig = MCFTlayerCon(ecx, Ec, eyx, 1, true); //edw den exei simasia to reduction e, giati mpainei katastatiko
			Em = sig/ecx;
			tao = 0;
			Gm = 0; 
	}
		/*else{// not known result by now, gets into the flip-flop area, without the angle beeing one of the three criticals (ð/2, -ð/2, fcy = fc2)
			if(debugMsg){ 
			//	MessageBox(NULL,L"Conceval converged with the flip-flop criterion for a non typical known case", L"Bolzano trap", MB_OK);
			}
		}*/
	
	return (ConvFlag||returnFlag);

	// disp('The angle of inclination of principal stresses/strains is (rad)');
	// disp(angIt);

}
//---------------------------------------------------------------------------
bool Layer::concEvalwoV(){ 
	double Ec = (2*myConcrete.fc)/myConcrete.epc0;
	double eyx = myConcrete.fyx / myConcrete.Es;
	sig = MCFTlayerCon(ecx, Ec, eyx, 1, true); //edw den exei simasia to reduction e, giati mpainei katastatiko
	Em = compEmTan(ecx, Ec, eyx);
	tao = 0;
	Gm = 0; 
	return true;
}
//---------------------------------------------------------------------------
bool Layer::RegularFalsiLayer(double(Layer::*f)(double), double xA, double xB, double tol, int insMaxIter, double& xRes, bool& returnFlag){
	
	int insIter = 0 ;
	double xNew;

	double fxA =  (*this.*f)(xA);
	double fxÂ =  (*this.*f)(xB);

	xNew = xA - (fxA)*(xA - xB)/(fxA - fxÂ);
	double fxNew = (*this.*f)(xNew); 
	
	while ((abs(fxNew)> tol) && (insIter<=insMaxIter)){
		insIter++;
		if  (fxÂ*fxNew>0){
			xB = xNew;
			fxÂ = fxNew;
		}
		else{
			xA = xNew;
			fxA = fxNew;
		}
		
		xNew = xA - (fxA)*(xA - xB)/(fxA - fxÂ);
		fxNew = (*this.*f)(xNew);

		//gia na ginetai o ypologismos prwta kai sti synexeia o elegxos sygklisis
		if ((abs(xA-xB)<1E-12) && (fxA*fxÂ<0)){
			returnFlag = true;	//exei kleidwsi praktika ti lisi
			break;
		}
	}


	xRes = xNew;
	if(insIter<=insMaxIter){
		return true;
	}
	else{
		return false;
	}
}
//---------------------------------------------------------------------------
bool Layer::BisectionLayer(double(Layer::*f)(double), double xA, double xB, double tol, int insMaxIter, double& xRes, bool& returnFlag){
	
	int insIter = 0 ;
	double xNew;

	double fxA =  (*this.*f)(xA);
	double fxÂ =  (*this.*f)(xB);

	xNew = 0.5*(xA+xB);
	double fxNew = (*this.*f)(xNew); 
	
	while ((abs(fxNew)> tol) && (insIter<=insMaxIter)){
		insIter++;
		if  (fxÂ*fxNew>0){
			xB = xNew;
			fxÂ = fxNew;
		}
		else{
			xA = xNew;
			fxA = fxNew;
		}
				if (fxA*fxÂ>0){
					if(debugMsg){
						MessageBox(NULL,L"Probably due to flip-flop phaenomenon, the bisection method lost the correct interval", L"Bisection Method on Layer", MB_OK);
					}
				}
		
		xNew = 0.5*(xA+xB);
		fxNew = (*this.*f)(xNew);
		if ((abs(xA-xB)<1E-12) && (fxA*fxÂ<0)){
			returnFlag = true;	//exei kleidwsi praktika ti lisi
			break;
		}
	}


	xRes = xNew;
	if(insIter<=insMaxIter){
		return true;
	}
	else{
		return false;
	}
}
//---------------------------------------------------------------------------
Section::Section(void){
	angMCFT = 0.0;	//changes later
	nBars = 0;
	nFibers = 0;
	hasConv = false;
	hasConvWoV = false;
	hasConvOneMC = false;
}


//---------------------------------------------------------------------------
void Section::initRect(const double dInp,const double bInp,const int nIPInp, const int nFibersInp, const double* fAsInp, const double covInp, const integTyp iTypInp){ 

	secTyp = stRect;
	
	d = dInp;
	b = bInp;
	
	nIP = nIPInp;

	nFibers = nFibersInp;
	fibers = new Fiber[nFibers];

	intTyp = iTypInp; 

	//assigning fiber As
	for (int i = 0; i < nFibers ; i++){
		fibers[i].As = fAsInp[i];
	}
	cov = covInp;
	
	//common lines
	//resize nIP dependend variables
	layers = new Layer[nIP];
	yfib.resize(nIP);
	wfib.resize(nIP);
	// initialize section deformation and SVector
	e << -0.00001,  0.000001, 0.00001; 
}
//---------------------------------------------------------------------------
void Section::initCirc(const double dInp, const int nIPInp, const int nBarsInp, const double dbarInp, const double covInp, const integTyp iTypInp){ 
		
	secTyp = stCirc;
	d = dInp;
	nIP = nIPInp;
	nBars = nBarsInp;
	bars = new Bar[nBars];

	for (int iB=0 ; iB<nBars ; iB++){
		bars[iB].dBar = dbarInp;
	}
	cov = covInp;
	intTyp = iTypInp;

	//common lines
	//resize nIP dependend variables
	layers = new Layer[nIP];
	yfib.resize(nIP);
	wfib.resize(nIP);
	// initialize section deformation and SVector
	e << -0.00001,  0.000001, 0.00001; 
}
//---------------------------------------------------------------------------
double Section::Area(){
	switch (secTyp) {
		case stRect : 
			return (b*d);
		case stCirc : 
			return (0.25*M_PI*pow(d,2));
		default :
			MessageBox(NULL,L"Given Section Type not known", L"Section Type", MB_OK);
			return 0;
	}
}
//---------------------------------------------------------------------------
void Section::initLoads(const double* sInp){
		// specify applied axial force N, shear force V and Moment M
	for (int i = 0; i < 3 ; i++){	
		s(i) =	sInp[i]; //N		
	}

	//initial angle
	if (abs(s(0))<1E-15){ //mideniko axoniko
		angMCFT = 0.25*M_PI;
	}
	else{
		double Ar = Area();
		double Ash = (5.0/6.0)*Ar;
		double vxy = abs(s(2))/Ash;
		double sx = abs(s(0))/Ar;
		angMCFT = 0.5*atan((2*vxy/sx));
	}
}
//---------------------------------------------------------------------------
void Section::RectPatch2Layer(){

	/*RECTPATCH2LAYER integration points and weights for 1d-integration of rectangular patch 
	[YFIB,WFIB] = RECTPATCH2LAYER (PATCOOR,INTTYP,NLAYER)
	function determines locations in vector YFIB and integration weights in vector WFIB
	for 1d integration of a rectangular patch for the integration scheme
	in character array INTTYP and the number of integration points in NLAYER;
	the dimension of the rectangular patch is supplied by specifying the
	coordinates of opposite corners in array PATCOOR ([y1 z1 (top right);y2 z2 (bottom left)])
	(NOTE: right handed local coordinate system x-y-z!)
	INTTYP can be either 'Midpoint', 'Gauss', Lobatto' or 'Trap' */

	//stoixeia oloklirosis section
	/*Matrix2d patcoor;
	patcoor(0) = d/2;
	patcoor(1) = -b/2;
	patcoor(2) = -d/2;
	patcoor(3) = b/2; 
	Vector2d y  = patcoor.col(0), d/2, -d/2;
	Vector2d z  = patcoor.col(1);*/ //ygAssert

	double dy = d/2-(-d/2);         // section depth. in the matlab code they come from patcoor    
	double dz = b/2-(-b/2);         // section width

	VectorXd yIP(nIP); 
	VectorXd wIP(nIP);

	// call integration method and get weights and locations in interval -1<xi<1
	switch ( intTyp ) {
	case ITmidpoint : 
		MidpointRect(yIP, wIP, nIP);
		break;
	case ITlobatto : 
		Lobatto(yIP, wIP, nIP);
		break;
	default :
		MessageBox(NULL,L"Integration typ not known", L"Integration Type", MB_OK);
	}


	// transform to actual weights and locations
	double Jac = dy/2;
	wfib = (Jac*dz)*wIP;  

	yfib = (-d/2)*VectorXd::Ones(nIP) + (yIP+VectorXd::Ones(nIP))*Jac;		//matlab: yfib = y(2) + (yIP+1).*Jac; */
}

//-----------------------------------------------------------------
void Section::CircPatch2Layer(){

	/* CIRCPATCH2LAYER integration points and weights for 1d-integration of circular patch
	[YFIB,WFIB] = CIRCPATCH2LAYER (DIAM,INTTYP,NLAYER)
	function determines locations in vector YFIB and integration weights in vector WFIB
	for 1d integration of a circular patch for the integration scheme
	in character array INTTYP and the number of integration points in NLAYER;
	DIAM provides the diameter of the circular patch
	only midpoint integration is presently supported for INTTYP ('Midpoint')*/

	switch ( intTyp ) {
	case ITmidpoint : 
		MidpointCirc(yfib, wfib, nIP, d);
		break;
	default :
		MessageBox(NULL,L"Integration typ not known", L"Integration Type", MB_OK);
	}

}
//-----------------------------------------------------------------
void Section::CircLine2Fiber(){

	switch ( intTyp ) {
		case ITmidpoint :{
			double R = 0.5*d;
			double r = R- (cov + 0.5*bars[0].dBar); //afou akoma theorountai pantou idies
			double s = (2*M_PI*r)/nBars;		//	arc length between two successive bars
			double t = s/r;					//	angle between two successive bars

			bars[0].yBar = r;				// First Bar Coordinate y
			bars[0].zBar = 0;				// First Bar Coordinate z

			for (int k=1; k < nBars ; k++){
				bars[k].yBar= r*cos(t*k);
				bars[k].zBar= r*sin(t*k);
			}
			for (int k2=0; k2 < nBars ; k2++){
				bars[k2].ABar = M_PI*(pow(bars[k2].dBar,2))/4;
			}
		}
			break;
		default :
			MessageBox(NULL,L"Integration Type not known", L"Integration Type", MB_OK);
	}
}
//-----------------------------------------------------------------
double Section::gama(VectorXd yfib,int m){
	//function gxy = gama(e,yfib,d,m) e,d declared in section
	// Returns the shear strain of the fiber according to a parabolic diagramm
	double ea = e(0);
	double c = e(1);
	double b = ea;
	double etop = b + c*(d/2);
	double ebot = b - c*(d/2);
	double xcent, gxy;

	if (etop*ebot >0){
		if (etop <0){
			xcent = d/2;
		}	
		else{ 
			xcent = d/2;
		}  
	}
	else{
		if (etop<0){
			xcent = abs(etop/c);
		}
		else{
			xcent = abs(ebot/c);
		}
	}


	double xfib = yfib(m) + d/2; 

	if (xfib<=xcent){
		gxy = e(2)*(2*(xfib/xcent)-pow((xfib/xcent),2));
	}
	else{
		double yfibN = d - xfib;
		double ycent = d - xcent;
		gxy = e(2)*(2*(yfibN/ycent)-pow((yfibN/ycent),2));
	}

	return gxy;
}
//-----------------------------------------------------------------
double Section::angle(VectorXd yfib,int m){
	// function theta = angle(e , yfib, d, m,angMCFT)
	// Returns a tentantive value of the angle of principal stresses
	double ea = e(0);
	double c = e(1);
	double b = ea;
	double etop = b + c*(d/2);
	double ebot = b - c*(d/2);
	double theta, ycz;

	if (etop*ebot >0){
		if (etop <0){
			ycz = d;
			theta = angMCFT;
			return theta;
		}
		else{ 
			ycz = 0;
			theta = angMCFT ;
			return theta;
		}
	}
	else{
		if (etop<0){
			ycz = abs(etop/c);
		}	
		else{
			ycz = abs(ebot/c);
		}
	}


	double ytz = d-ycz;
	double xfib = yfib(m) + d/2;

	if (xfib <=ycz){
		theta = (M_PI/4)*(2*(xfib/ycz)-pow((xfib/ycz),2));
	}
	else{
		theta = (M_PI/4) + 3*(M_PI/4)*pow(((xfib-ycz)/ytz),4) - (M_PI/2)*pow(((xfib-ycz)/ytz),5);
	}
	return theta;
}
//-----------------------------------------------------------------
void Section::RC(bool no_eV){	
	//    enopoiimemes RCRect-RCCIRC
	// discretization of section, patcoor in constructor of section
	switch (secTyp) {
	case stRect : 
		RectPatch2Layer();
		break;
	case stCirc : 
		CircPatch2Layer();
		break;
	default :
		MessageBox(NULL,L"Given Section Type not known", L"Section Type", MB_OK);
	}

	// section state determination: force and stiffness for given deformation e
	sf.setZero();        //initialize before assembly
	sv.setZero();
	kf.setZero();
	kv.setZero();

	RowVector3d as;
	RowVector3d av; //declared but not used for no_eV

	

	//layers
	for (int m = 0; m < nIP; m++){ //loop over integration points
		//disp('no of concrete layer')
		//disp(m)
		
		as   << 1, -yfib(m), 0; 
		if(!no_eV){ 
			av   << 0,  0 , 1; 
		}
		
		layers[m].ecx = as*e;          // total strain in integration point m
		
		// initial angle section is angMCFT which is also passed to layers in some cases of the angle function

		if(!no_eV){ 
		layers[m].gxy = gama(yfib,m);
		layers[m].theta = angle(yfib, m);
		}

		// sig = fcx; tao = vxy; Em = Et; Gm =Gt;
		if(!no_eV){ 
		layers[m].concEval();
		}
		else{
			layers[m].concEvalwoV();
		}
		
		layers[m].sf = wfib(m)*(as.transpose()*(layers[m].sig)); 
		layers[m].kf = wfib(m)*(as.transpose()*layers[m].Em*as);
		if(!no_eV){
		layers[m].sv = wfib(m)*(av.transpose()*layers[m].tao);
		layers[m].kv = wfib(m)*(av.transpose()*layers[m].Gm*av);
		}

		sf   = sf + layers[m].sf; 
		kf   = kf + layers[m].kf;
		if(!no_eV){
		sv   = sv + layers[m].sv;
		kv   = kv + layers[m].kv;
		}
	}

	//fibers
	switch (secTyp) {
		case stRect :{		
			for (int j = 0; j < nFibers; j++){ //loop over fibers		
				as << 1, (-(0.5*d-cov)+(d-2*cov)*j/(nFibers-1)), 0; 
				fibers[j].epsi = as*e;
				fibers[j].steelEval();
				fibers[j].sf = fibers[j].As*(as.transpose()*fibers[j].sig);
				fibers[j].kf = fibers[j].As*(as.transpose()*fibers[j].Em*as);

				sf = sf + fibers[j].sf;
				kf = kf + fibers[j].kf;
			}
			}
			break;
		case stCirc :{
			CircLine2Fiber(); 
			for (int j = 0; j < nBars; j++){ //loop over integration points		
				as << 1, -bars[j].yBar, 0; 
				bars[j].epsi = as*e;
				bars[j].steelEval();
				sf   = sf + bars[j].ABar*(as.transpose()*bars[j].sig);
				kf   = kf + bars[j].ABar*(as.transpose()*bars[j].Em*as);
			}
			}
			break;		
		default:
			MessageBox(NULL,L"Given Section Type not known", L"Section Type", MB_OK);
	}

	sr = sf + sv;
	ks = kf + kv;	

}
//-----------------------------------------------------------------
void Section::RCÉter(Algorithm &alg){
	
	int nConvDecimalsMin = 2;
	int nConvDecimalsMax = 3;

	for (int iNCD=nConvDecimalsMax; iNCD>=nConvDecimalsMin; iNCD--){
		//reset algorithm counter
		alg.iter = 0;

		//reset initial e
		e << -0.00001,  0.000001, 0.00001; 

		// initialization before first loop
		RC();

		// determine section force unbalance
		su = s-sr;	

		// determine section deformation increment	
		De = RightDivideMV3(ks,su);

		// update section deformation
		e  = e + De;

		MatrixXd DeHist = MatrixXd::Zero(alg.maxIter,3);

		double precision = 1/(pow(10.0,iNCD));

		while (((abs(su(0)/s(0))>precision)||(abs(su(1)/s(1))>precision)||(abs(su(2)/s(2))>precision)) && (alg.iter<alg.maxIter) ){
			RC(); //this changes ks, sr
			
			su = s-sr;

			double ratio0ov1 = abs((su(0)/s(0))/(su(1)/s(1)));
			double ratio0ov2 = abs((su(0)/s(0))/(su(2)/s(2)));
			double ratio1ov2 = abs((su(1)/s(1))/(su(2)/s(2)));

			if (((ratio0ov1<1E-3)||(ratio0ov2<1E-3))||((ratio1ov2>1E3)||(ratio0ov2>1E3))||((ratio1ov2<1E-3)||(ratio0ov1>1E3))){			
					
					//sinistosa temnousas
					double SuVInt = s(2) - sr(2);
					double KvInt = ks(2,2);
					double DeVInt = RightDivide(KvInt,SuVInt);

					//sinistoses axonikis - ropis
					//den eginan me matrix giati yparxei provlima sto compilation epeidi einai managed (to vector2d)
					double KnmInt[4];  // compilation problem, due to managed code, i have to pass an array
					for (int i = 0; i < 2 ; i++){
						for (int j=0; j < 2; j++){
							KnmInt[i*2+j] = ks(i,j);	
						}
					}
								
					double SuNmInt[2];
					SuNmInt[0] = s(0) - sr(0);
					SuNmInt[1] = s(1) - sr(1); 
					
					double DeNmInt[2];
					RightDivideMV2(KnmInt, SuNmInt, DeNmInt);
					

					De << DeNmInt[0], DeNmInt[1], DeVInt;	

					if ((ratio0ov1<1E-3)||(ratio0ov2<1E-3)){
						De(0)=0;
					}
					else if((ratio1ov2>1E3)||(ratio0ov2>1E3)){
						De(2)=0;
					}
					else if((ratio1ov2<1E-3)||(ratio0ov1>1E3)){
						De(1)=0;
					}   
			}
			else{
				De =  RightDivideMV3(ks,su);
			}


			for (int iDe=0; iDe<3; iDe++){
				if ((myIsinf(De(iDe)))||(myIsnan(De(iDe)))){
					if(alg.iter>0){
						De(iDe)=0.001*DeHist(alg.iter-1,iDe);
					}
					else{
						De(iDe)=1E-6; //never enters, just in case
					}
				}
			}

			DeHist.row(alg.iter)=De.transpose(); //kept for next possible inf or nan
			e = e + De;
			alg.iter = alg.iter + 1;
		}
		
		if (alg.iter<alg.maxIter){//exei sygklinei, den kanoyme epomeni loypa me ligotera dekadika sygklisis
			hasConv = true;
			return;
		}	
	}

	
	if(abs(s(1))<1E-13){ //elegxos apousias kamsis
		zeroM_MCStep();
	}
	else{
		RCÉterwoV(alg);//call RC without V
	}
	
}
//-----------------------------------------------------------------
void Section::RCÉterwoV(Algorithm &alg){
	
	int nConvDecimalsMin = 2;
	int nConvDecimalsMax = 3;
	sr(2) = s(2); su(2) = 0;
	double DeNM[2];
	double SuNM[2];
	double KNM[4];

	for (int iNCD = nConvDecimalsMax; iNCD>=nConvDecimalsMin; iNCD--){
		//reset algorithm counter
		alg.iter = 0;

		//reset initial e
		e << 0,  0, 0; //e(2) , shear deformation equal to zero
		double precision = 1/(pow(10.0,iNCD));
		MatrixXd DeHist = MatrixXd::Zero(alg.maxIter,3);

		while ((((abs(su(0)/s(0))>precision)||(abs(su(1)/s(1))>precision)) && (alg.iter<alg.maxIter))||(alg.iter == 0)){ //na trexei toulaxiston mia epanalipsi giati yparxei mia mikri pithanotita na fygei mono tou

			// initialization before first loop
			RC(true);

			SuNM[0] = s(0) - sr(0); su(0) = s(0) - sr(0);
			SuNM[1] = s(1) - sr(1); su(1) = s(1) - sr(1); 
			//sinistoses axonikis - ropis
			for (int i = 0; i < 2 ; i++){
				for (int j=0; j < 2; j++){
					KNM[i*2+j] = ks(i,j);	
				}
			}
								
			RightDivideMV2(KNM, SuNM, DeNM);

			De << DeNM[0], DeNM[1], 0;

			double ratio0ov1 = abs((su(0)/s(0))/(su(1)/s(1))); //hold back 
			if (ratio0ov1<1E-3){
				De(0)=0;
			}
			else if(ratio0ov1>1E3){
				De(1)=0;
			}   

			for (int iDe=0; iDe<2; iDe++){
				if ((myIsinf(De(iDe)))||(myIsnan(De(iDe)))){
					if(alg.iter>0){
						De(iDe)=0.001*DeHist(alg.iter-1,iDe);
					}
					else{
						De(iDe)=1E-6; //never enters, just in case
					}
				}
			}

			DeHist.row(alg.iter) = De.transpose(); //kept for next possible inf or nan
			e = e + De;
			alg.iter = alg.iter + 1;
		}
		
		if (alg.iter<alg.maxIter){//exei sygklinei, den kanoyme epomeni loypa me ligotera dekadika sygklisis
			hasConvWoV = true;
			sr(2) = s(2);
			return;
		}	
	}	
}
//-----------------------------------------------------------------
void Section::zeroM_MCStep(){	

// one step moment-curvature analysis of a section 
	
	// set the curvature increment to zero for the first load step (apply axial force only!)
	double Dkap = 0;
	double tol =1e-6;
	
	// initialize section deformation vector
	e << -0.00001, 0.0, 0.0; 
	
	// determine resisting force and current section stiffness
	RC();

	// determine axial force unbalance for given axial force, curvature and shear strain increment
	double dNdkap = ks(0,1);
	double Nu = s(0) - sr(0) - dNdkap*Dkap;
	   
	// determine axial strain increment
	double Deps_a = RightDivide(ks(0,0),Nu);

	// update section deformations with axial strain correction and imposed curvature and shear strain increment
	Vector3d deMU(Deps_a,0,0);
	e  = e + deMU;
	   
	// start equilibrium iterations at constant axial load: set iteration counter to zero
	int mcIter = 0;
	   
	while ( (abs(Deps_a)>tol || abs(Nu*Deps_a)>tol) && (mcIter<1000)){
		// update iteration counter
		mcIter = mcIter + 1;
			
		// section state determination for new state	
		RC();
		// determine axial force unbalance
		Nu = s(0) - sr(0);
		// determine axial strain increment
		Deps_a = RightDivide(ks(0,0),Nu);
		// update axial strain only (curvature and shear strain is held constant during iterations)
		e(0)   = e(0) + Deps_a;
	}

	if (mcIter<1000){// if process converges, update final section state	
		RC(); 
		hasConvOneMC = true;
	}
	else{
		if(debugMsg){
			MessageBox(NULL,L"Solution not found", L"Section withoutM", MB_OK);
			return;
		}
	}

	sr(2) = s(2);	//balancing V 
	double Ec = (2*myConcrete.fc)/myConcrete.epc0; 
	double Gc = Ec / (2*(1+0.2));
	double Ash = (5.0/6.0)*Area(); 
	e(2) =  s(2)/(Gc*Ash); //gxy
	e(1) = 0.0;
	sr(1) = 0.0;
}
//---------------------------------------------------------------------------
double Section::getEpscAnch(){	
	//epsc: áðü ôçí áêñáßá èëéâüìåíç öÝôá 
	double epscWanted = 0;
	if (layers[nIP-1].ecx*layers[0].ecx>=0){ //omosima epistrefoun miden
		return 0;
	}
	else if (layers[0].ecx<0){ //katw ina, sinithos akraia thlivomeni logw fortioy pros ta katw ston provolo
		return abs(layers[0].ecx);
	}
	else if (layers[nIP-1].ecx<0){
		return abs(layers[nIP-1].ecx);
	}
}

//-----------------------------------------------------------------
double Section::getEpsbAnch(){
	//apo tin akraia efelkyomeni ina oplismou
	switch (secTyp) {
		case stRect :{		
				if (fibers[0].epsi*fibers[nFibers-1].epsi>=0){ //omosima
					return 0;
				}
				else if (fibers[0].epsi>0){
					 return fibers[0].epsi;
				}
				else if (fibers[nFibers-1].epsi>0){
					return fibers[nFibers-1].epsi;
				}
			}
			break;
		case stCirc :{
				double epsbRes = 0;
				bool compExists = false; //compression exists
				for (int j = 0; j < nBars; j++){ //loop over integration points		
					if (epsbRes < bars[j].epsi){
						epsbRes = bars[j].epsi;
					}
					if (!compExists){
						if(bars[j].epsi<0){
							compExists = true;
						}
					}
				}
				if (compExists){
					return epsbRes;
				}
				else{
					return 0;
				}
			}
			break;		
		default:
			MessageBox(NULL,L"Given Section Type not known", L"Section Type", MB_OK);
			return 0;
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
bool Section::MCStep(Vector3d eInit,double Dkap,double Dgam){
	
	//eInit is actually the e of the previous step

	//algorithm standards
	double tol =1e-6;
	int maxiter = 100;

		// initialize section deformation vector 
		e = eInit; 
		// determine resisting force and current section stiffness
		RC();

		// determine axial force unbalance for given axial force, curvature and shear strain increment
		double dNdkap = ks(0,1);
		double Nu = secNaxial - sr(0) - dNdkap*Dkap;
	   
		// determine axial strain increment
		double Deps_a = RightDivide(ks(0,0),Nu);

		// update section deformations with axial strain correction and imposed curvature and shear strain increment
		Vector3d deMU(Deps_a,Dkap,Dgam);
		e  = e + deMU;
	   
		// start equilibrium iterations at constant axial load: set iteration counter to zero
		int mcIter = 0;
	   
		while ( (abs(Deps_a)>tol || abs(Nu*Deps_a)>tol) && (mcIter<maxiter)){
			// update iteration counter
			mcIter = mcIter + 1;
			
			// section state determination for new state	
			RC();
			// determine axial force unbalance
			Nu = secNaxial - sr(0);
			// determine axial strain increment
			Deps_a = RightDivide(ks(0,0),Nu);
			// update axial strain only (curvature and shear strain is held constant during iterations)
			e(0)   = e(0) + Deps_a;
		}

		if (mcIter<maxiter){
			// if process converges, update final section state
			RC(); 
			hasConv = true;
		}
		else{
			hasConv = false;
		}

		return hasConv;
}
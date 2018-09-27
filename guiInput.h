#ifndef guiInputH
#define guiInputH


class  guiInput{
	
	private:
	
	public:
		//geometrical input guo
		bool isRect;	 
		double dInp; //is used both for h of rectangular and for d of circular	
		double bInp;
		
		//reinforcement input (the ones that are not assigned to mySteel or myConcrete)
		//longitudinal
		int nFibersInp; //rectangular
		int nFibersPrev;
		double *fAsInp;	
		int nBarsInp; //circular
		double dBarInp;	
		double covInp; //coverage

		//transversal
		double stirrSpInp; //stirrup Spacing
		double nTransSBInp;		
		double AswInp;	//Area of transverse reinforcement bar(d is actually given)
			
		//analysis
		//common
		double nAxInp; // sign is given directly when loaded
		int nIPInp;
		//type of integration always midpoint, so not given here

		//pushover
		double LsInp;
		int nStepPOInp;
		double VStepInp;
		int nSPInp; 
		//integration of sections always lobatto, so n input
		bool anExistsInp;
		double anfcInp; //themeliou                               
		double anDbInp;     
		double anLbInp;

		//moment-curvature
		double dKappaInp; 
		double dGammaInp;
		int nStepsMCInp;

		//functions
		guiInput(){
			//here an initial value is given so that the mask can start
			fAsClear();
			/* old initial values
			fAsInp[0] = (3*M_PI*pow(28.7,2))/4;
			fAsInp[1] = (2*M_PI*pow(28.7,2))/4;
			fAsInp[2] = (3*M_PI*pow(28.7,2))/4;*/
		}; 

		~guiInput(){
			/*if(nFibersInp>0){
				delete[] fAsInp; 
				nFibersInp = -1;
			}*/
		};

		void fAsClear(){
			nFibersInp = 2;
			nFibersPrev = 2;
			fAsInp = new double[nFibersInp];
			fAsInp[0] = 0;
			fAsInp[1] = 0;
		}

};


#endif
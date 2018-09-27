//---------------------------------------------------------------------------

#ifndef ElementH
#define ElementH

#include "stdafx.h"
#include "Section.h"
#include "guiInput.h"
#include "F_SolvProgress.h"

using namespace std;
using namespace Eigen;

class Element;

class Anchorage{
	private:
		Element* parentCant;

		//data
		double fc;	// concrete strength of the foundation, input, may be different than the general concrete
		double Lb;	// equivalent straight anchorage length. καντην floor

		
		//afta tha ta pairnoume apo tin akrotati section kai ton provolo otan eimaste etoimoi
		double epsb;	// tensile strain of the extreme longitudinal reinforcing bar at the support
		double Curv;	// curvature of the section at the support of the cantilever column
		double epsc;    // compressive strain of the extreme section compressive fiber at the support ακραία θλιπτική 
		double Db;		// bar diameter of longitudinal reinforcement.
		double dEff;	// effective depth of the section at the support of the cantilever column


		//data endiamesa ypologismwn
		double sy;
		double w;
		double fbmax;
		double fbres;
		double lr;

		//output ypologismwn
		double DeltaPO;
		VectorXi x;	//ta 4 vectors orizontai me vasi to Lb
		VectorXd Slip;
		VectorXd Bond;
		VectorXd StrAnch;  

		//synartiseis
		void lpaElBal(double &dep, double &epeln, double lpa);
		void lpaPlBal(double &dep, double &epeln, double lpa);
		bool lpaEval(double &lpa, double &epel, bool elastic);

	public:
		Anchorage(){};
		~Anchorage(){};
		void init(const double fcInp, const double DbInp,  const double dEffInp, const double LbInp, Element* ptElFath);
		void paramInp(const double epsbInp, const double CurvInp, const double epscInp);
		double eval();
	
	friend class Element;
};

class stepPO{
	
	private:
		double deltaFl;
		double deltaSh;
		double deltaPOn;
		double delta;
		bool bYield;

	public:
		Element* parElem;
		// ta lobatto section points, to Naxial, to anchorageExists, ta xIP, wIP ta pairnei apo to parentCant;
		int idStep; //step identity

		double Vend;		
		Section* SectionsPO; //photos of the sections
		Anchorage myAnch;	//photos of anchorage
		bool conv;
		bool convWoV;
		bool anchRes;
		
		//functions
		stepPO(){
			deltaFl = 0;
			deltaSh = 0;
			deltaPOn = 0;
			delta = 0;
			bYield = false;
			anchRes = false;
		}; 
		~stepPO(){
			delete[] SectionsPO;
		};
		void eval(Phaethon::F_SolvProgress ^fProg); //step evaluation

		friend class Element;
};

class Element{
	private:
		//stoixeia input provolou. orismena apo ayta tha epanypologistoyn sti vasi twn stoixeiwn toy input
		sectionTyp eSecTyp; //type of element cross-section

		//edw tha mpoyn sections klp
		// stoixeia sxetizomena me tis ypologizomenes diatomes
		int nSecPoints; //o arithmos twn section points gia ti lobatto procedure
		double *wSP;
		double *xSP;  
		
		// stoixeia sxetizomena me ta ypologizomena vimata
		int nStepsPO; //o arithmos twn pushover steps
		stepPO *poSteps; //ta pushoverSteps
		
		double	Naxial; //axial load steady
		double	Vstep; //shear load step
		bool	anchExists; //if anchorage Exists
		
		bool inized;
		//synartiseis
		void init(guiInput myGI); //basic initializations
		void clear();
		int befYieldStep;
		int lastConvStep;

		// gia to final drift
		double nTransSB; //tmiseis katheta
		double stirrSp; //stirrup Spacing
		double Asw;	//Area of transverse reinforcement bar
		double hw; //ypsos diatomis
		double cov;
		double fyStirr;
		double eDrift; //teleftaia metatopisi, fthinon klados
		double vDrift; // fortio sto drift
		double deltaDrift;
		double evalDesc();
		
	public:
		Element(){
			inized = false;
			befYieldStep = -1;	
			lastConvStep = -1;
		}; 
		~Element(){	clear(); };	
		void evalPO(guiInput myGI, System::Windows::Forms::DataVisualization::Charting::Chart^  chartPOGen
								, System::Windows::Forms::DataVisualization::Charting::Chart^  chartPOContr);
		double Ls;		// shear span of the cantilever beam.
		bool printResults(const wchar_t *resFilename);
		bool printAnchResults(const wchar_t *resFilename,int iStep);
		int showAnchResults(System::Windows::Forms::DataVisualization::Charting::Chart^  chartAnch,	System::Windows::Forms::ComboBox^  cmbChartAnch,	int stepId=-1);
		bool isInized(){return inized;};

	friend class stepPO;
};



#endif

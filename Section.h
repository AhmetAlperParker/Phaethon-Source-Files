//---------------------------------------------------------------------------

#ifndef SectionH
#define SectionH
//---------------------------------------------------------------------------

#include <string>
#include "Algorithm.h"
#include "mathUtils.h"
#include "global_flags.h"

using namespace std;
using namespace Eigen;

enum	sectionTyp{
	stRect, stCirc
};

enum	integTyp{
	ITmidpoint, ITlobatto
};

class Material{
protected:
	string name;
public:
	Material(){};
	virtual ~Material(){};
	//virtual void eval() = 0;
};

class Concrete : public Material{
	public:
		double fc;           // maximum compressive stress observed in a cylinder test (negative quantity)
		double epc0;         // strain in concrete cylinder at peak stress fc (negative quantity)
		double fcr;          // stress in concrete at cracking (positive quantity)
		double ecr;       	 // strain in concrete at cracking (positive quantity)
		double Es;           // Young modulus for steel  
		double rsy;          // rsy : reinforcement ratio for stirrups
		double fyy;          // yield strength of stirrups
		double fyx;          // yield strength of longitudinal reinforcement;

		Concrete(){};
		~Concrete(){};
		//void eval();
};

class Steel : public Material{
	public:
		double Es;    		// Young modulus
		double fy;          // yield strength
		double Eh;			

		Steel(){
			Eh  = 0; // starting with no plastic
		};
		~Steel(){};
		void eval(double epsi, double &sig, double &Em);
};

class Layer{
	private:
		double angIt;
		double fc1;
		double fc2;
		double fcy;
		double fsy;
		double e1;
		double e2;
		double ex;
		double ey;

		bool sigcEnd; //checker for end of material law
	
	public:
		double sig; //sig = fcx  
		double Em; //Em = Et	
		double ecx;	
		double gxy;
		double theta;

		double tao; //tao = vxy
		double Gm; //Gm =Gt
		
		
		// force and stiffness matrix for given deformation
		Vector3d sf;
		Vector3d sv;
		Matrix3d kf;
		Matrix3d kv;


		//synartiseis
		Layer(){
			sigcEnd = false;
		};
		~Layer(){};

		//paroti ta ylika einai global sto section.cpp, ta exoyme kai ws input an xreiastei na allaxei o xeirismos kai dinontai mesa stin RCRect
		void steelEval();
		bool concEval();
		bool concEvalwoV();
		double compEmTan(double eInt, double Ec, double eyx);
		bool RegularFalsiLayer(double (Layer::*f)(double), double xA, double xB, double tol, int insMaxIter, double& xRes, bool& returnFlag);
		bool BisectionLayer(double (Layer::*f)(double), double xA, double xB, double tol, int insMaxIter, double& xRes, bool& returnFlag);
		double MCFTlayer(double thIn);
		double MCFTlayerCon(double eInt, double Ec, double eyx, int eRedID, bool materialLaw = false);
};

class Fiber{	//αναφέρεται σε στρώσεις οπλισμού
	public:
		double sig; //sig = fcx  
		double Em; //Em = Et	
		double epsi;
		double As;

		// force and stiffness matrix for given deformation
		Vector3d sf;
		Matrix3d kf;

		//synartiseis
		Fiber(){};
		~Fiber(){};

		//paroti ta ylika einai global sto section.cpp, ta exoyme kai ws input an xreiastei na allaxei o xeirismos kai dinontai mesa stin RCRect
		void steelEval();
};

class Bar{	//αναφέρεται σε μεμονωμένη ράβδο οπλισμού (κυκλική διατομή)
	public:
		double sig; //sig = fcx  
		double Em; //Em = Et	
		double epsi;

		// force and stiffness matrix for given deformation
		Vector3d sf;
		Matrix3d kf;

		double dBar;	//Diameter of each longitudinal bar		
		double yBar;	//y bar coordinates
		double zBar;	//z bar coordinates
		double ABar;	//Cross-Section of each longitudinal bar

		//synartiseis
		Bar(){};
		~Bar(){};

		//paroti ta ylika einai global sto section.cpp, ta exoyme kai ws input an xreiastei na allaxei o xeirismos kai dinontai mesa stin RCRect
		void steelEval();
};


class Section{
	private:
		sectionTyp  secTyp;

		Layer* layers; //layer beton, nIP dependend size
		Fiber* fibers; //steel fiber-layers
		Bar*   bars;

		int nIP;      // no of integration points, equal to layers
		int nFibers;		  // nymber of fiber layers of steel	
		int nBars;		// number of total steel bars (for circular)
		
		double d;       // section depth or diameter for circular
		double b;       // section width
		integTyp  intTyp;    	  // integration type	
		double cov;           // cover of reinforcing steel

		double angMCFT;//i arxiki ektimisi gia th gwnia, prokyptei apo ti fortisi. oi epi merous ypologizontai mes sta layer 

		//paramorfwseis, dynameis klp 
		Vector3d s; //to dianysma twn dynamewn s[0]=N, s[1]=M, s[2]=V
		Vector3d e; //paramorfosi
		

		// force and stiffness matrix for given deformation
		Vector3d sf;
		Vector3d sv;
		Matrix3d kf;
		Matrix3d kv;

		//Matrices for the iterations and storage at the end
		Vector3d sr;	//resisting force
		Matrix3d ks;	//current section stiffness
		Vector3d De;	//section deformation increment
		Vector3d su;	//section force unbalance

		VectorXd yfib; //nIP dependend size
		VectorXd wfib; //nIP dependend size 
		
		double secNaxial; //input axial force for moment curvature

		bool hasConv;// has converged after the iterative procedure
		bool hasConvWoV;// has converged after the iterative procedure without V
		bool hasConvOneMC; // has converged with the one mc step
		double getEpscAnch();
		double getEpsbAnch();
		double Area();
		bool MCStep(Vector3d eInit,double Dkap,double Dgam);

	public:
		//synartiseis
		Section(void);
		~Section(){
			delete[] layers;
			if (nFibers){
				delete[] fibers;
			}
			if (nBars){
				delete[] bars;
			}
		};

		void initRect(const double dInp,const double bInp,const int nIPInp, const int nFibersInp, const double* fAsInp, const double covInp, const integTyp iTypInp = ITmidpoint);
		void initCirc(const double dInp, const int nIPInp, const int nBarsInp, const double dbarInp, const double covInp, const integTyp iTypInp = ITmidpoint);
		void initLoads(const double* sInp);

		// ypologismwn varwn klp
		double gama(VectorXd yfib,int m);
		double angle(VectorXd yfib,int m);
		void RC(bool no_eV = false);
		void RectPatch2Layer();
		void CircPatch2Layer();
		void CircLine2Fiber();
		void RCΙter(Algorithm &alg);
		void RCΙterwoV(Algorithm &alg);
		void zeroM_MCStep();

		friend class Element;
		friend class stepPO;
		friend class mcContainer;
};


#endif

#ifndef mcContainerH
#define mcContainerH
//-----------------
#include "Section.h"
#include "guiInput.h"
#include "F_SolvProgress.h"

class mcContainer{
	private:
		double dKappa;
		double dGamma;
		int nSteps; 
		double Naxial;
		sectionTyp mcSecTyp;

		Section* SectionsMC; //photos of the sections
		MatrixXd eResults; 
		MatrixXd sResults; 
		MatrixXd ePlot; 
		MatrixXd ePlotGaussian;
		MatrixXd sPlot;
		MatrixXd sPlotGaussian;
		
		bool inized;		
		int nConvergCount;

		void clear(); //clear and delete
		void init(guiInput myGI); //initialize from gui
	public:
		mcContainer(){
			inized = false;	//not initialized at first
			nConvergCount = 0;
		}; 
		~mcContainer(){
			clear();
		};	

		void evalMC(guiInput myGI, System::Windows::Forms::DataVisualization::Charting::Chart^  chartMC1, System::Windows::Forms::DataVisualization::Charting::Chart^  chartFS);		
		bool printMCResults(const wchar_t *resFilename);
		bool isInized(){return inized;};
};
#endif
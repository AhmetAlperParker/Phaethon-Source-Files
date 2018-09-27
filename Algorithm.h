//---------------------------------------------------------------------------

#ifndef AlgorithmH
#define AlgorithmH
//---------------------------------------------------------------------------
class Algorithm{
	public:
		double tol;           // maximum compressive stress observed in a cylinder test (negative quantity)
		int maxIter;         // strain in concrete cylinder at peak stress fc (negative quantity)
		int iter;
		Algorithm(){
			iter = 0;
		};
		~Algorithm(){};
		// specify convergence tolerance and maximum number of iterations
		void init();
};
#endif

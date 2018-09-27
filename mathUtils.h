//---------------------------------------------------------------------------
#ifndef mathUtilsH
#define mathUtilsH
#include "global_flags.h"
using namespace std;
using namespace Eigen;

int sgn(double x);
int sgn(int x);
void MidpointRect(VectorXd &xIP, VectorXd &weight, int nIP);
void MidpointCirc(VectorXd &yfib, VectorXd &wfib, int nLayers, double d);
void Lobatto(VectorXd &xIP, VectorXd &weight, int nIP);
double RightDivide(double K, double S);
void RightDivideMV2(const double* ks,  const double* S,  double* De);
Vector3d RightDivideMV3(const Matrix3d K, const Vector3d S);
void mDebug(Vector3d vec3, double* v3d);
void m3Debug(Matrix3d mat3, double** m3d);
bool myIsnan(double x);
bool myIsinf(double x);
VectorXd GaussianSmooth(const VectorXd input, int filterN = 5, bool firstZero = false);
wstring SystemStringToWstring(System::String^ input);
void assignKeyValue(const char *p, char keyword[64], char *value);
double intervalChoice( double minValue, double maxValue, int intervalNum, bool intsOnly=false);

#endif
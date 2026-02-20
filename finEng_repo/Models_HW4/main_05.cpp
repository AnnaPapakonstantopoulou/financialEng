
#include "PathDependentOption03.h"
#include <iostream>

using namespace std;

int main()
{
	double S0 = 100.0;
	double r = 0.03;
	double sigma = 0.2;

	BSModel model(S0, r, sigma);

	int m = 30; //1m observations m
	double T = 1.0 / 12.0;  //expiry = 1m.
	double K = 100.0;
	long N = 30000;
	double epsilon = 0.002;


	ArithmeticAsianCall ArithAsianCallOption(T, K, m);
	
	//price and greeks
	cout << "Asian Call Price = " << ArithAsianCallOption.PriceByMC(model, N, epsilon) << endl;
	cout << "Gamma = " << ArithAsianCallOption.gamma << endl;
	cout << "Vega = " << ArithAsianCallOption.vega << endl;
	cout << "Theta = " << ArithAsianCallOption.theta << endl;
	cout << "Rho = " << ArithAsianCallOption.rho << endl;

	return 0;
}

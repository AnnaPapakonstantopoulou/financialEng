
#include "PathDependentOption01.h"
#include <iostream>


using namespace std;

int main() {
    double S0 = 100.0;
    double r = 0.03;
    double sigma = 0.2;

    BSModel model(S0, r, sigma);

    int m = 30; //1m observations m
    double T = 1.0 / 12.0;  //expiry = 1m.
    double K = 100.0;
    long N = 300;
    

    ArithmeticAsianCall ArithAsianCallOption(T, K, m);
    cout << "Asian Call Price = " << ArithAsianCallOption.PriceByMC(model, N) << endl;

    EuropeanCall EuroCallOption(T, K, m);
    cout << "European Call Price = " << EuroCallOption.PriceByMC(model, N) << endl;

    EuropeanPut EuroPutOption(T, K, m);
    cout << "European Put Price = " << EuroPutOption.PriceByMC(model, N) << endl;

    return 0;
}

#include "BinModel01.h"
#include "Options03.h"
#include <iostream>
#include <cmath>
using namespace std;

//Calculate U and D
void calculateUandD(double sigma, double& U, double& D)
{
    //1 dT 
    double deltaT = 1.0;
    U = exp(sigma * sqrt(deltaT));
    D = exp(-sigma * sqrt(deltaT));
};

int main() {
    double S0, U, D, R, K;
    int N;

    //User Inputs
    getInputData(&S0, &U, &D, &R);

    cout << "Enter N: ";
    cin >> N;
    cout << "Enter K: ";
    cin >> K;


    //OPt price with bin tree method
    double binomialPrice = PriceByCRR(S0, U, D, R, N, K, CallPayoff);

    //Opt price with Analytic CRR
    double analyticPrice = PriceAnalyticCRR(S0, U, D, R, N, K, CallPayoff);

    //Print results
    std::cout << "Binomial Tree Price: " << binomialPrice << std::endl;
    std::cout << "Analytic CRR Price: " << analyticPrice << std::endl;

    return 0;
}

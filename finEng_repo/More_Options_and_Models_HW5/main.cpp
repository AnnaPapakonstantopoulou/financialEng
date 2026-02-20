
#include "PathDependentOption04.h"
#include "GeometricAsianOption.h"
#include "EuropeanCallOption.h"
#include "BarrierCallOption01.h"
#include <iostream>

using namespace std;


int main() {
    double S0 = 100.0, r = 0.03, sigma = 0.2;
    BSModel model(S0, r, sigma);
    double T = 1.0 / 12.0, K = 100.0;
    int m = 30;
    long N = 30000;

    ArithmeticAsianCall option(T, K, m);
    GeometricAsianCall cvOption(T, K, m);

    option.PriceByVarianceReductionMC(model, N, cvOption);
    cout << "Arithmetic call price = " << option.Price << endl
        << "Error = " << option.PricingError << endl;

    option.PriceByMC(model, N);
    cout << "Price by direct MC = " << option.Price << endl
        << "MC Error = " << option.PricingError << endl;

    double L = 105.0; // Define the barrier level
    BarrierCallOption barrierOption(T, K, L, m);
    barrierOption.CalculateEuropeanCallPrice(model); 

    barrierOption.PriceByMC(model, N);
    cout << "Barrier Call Option price = " << barrierOption.Price << endl
        << "Error = " << barrierOption.PricingError << endl;

    return 0;
}
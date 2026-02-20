#include "GeometricAsianOption.h"
#include "EuropeanCallOption.h"
#include <cmath>


double GeometricAsianCall::Payoff(SamplePath& S) 
{
    double Prod = 1.0;
    for (int i = 0; i < m; i++)
        Prod *= S[i];
    if (pow(Prod, 1.0 / m) < K) return 0.0;
    return pow(Prod, 1.0 / m) - K;
}

double GeometricAsianCall::PriceByBSFormula(BSModel model) 
{
    double a = exp(-model.r * T) * model.S0 * exp((m + 1.0) * T / (2.0 * m) * (model.r + model.sigma * model.sigma * ((2.0 * m + 1.0) / (3.0 * m) - 1.0) / 2.0));
    double b = model.sigma * sqrt((m + 1.0) * (2.0 * m + 1.0) / (6.0 * m * m));
    EuropeanCall G(T, K);
    Price = G.PriceByBSFormula(a, b, model.r);
    return Price;
}
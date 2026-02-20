
#include "EuropeanCallOPtion.h"

double N(double x) 
{
    double gamma = 0.2316482;
    double a1 = 0.463381530;
    double a2 = -0.256543787;
    double a3 = 1.792147795;
    double a4 = -1.821256083;
    double a5 = 1.310274326;
    double pi = 4.0 * atan(1.0);
    double k = 1.0 / (1.0 + gamma * x);

    if (x >= 0.0) 
    {
        return 1.0 - (((((a5 * k + a4) * k + a3) * k + a2) * k + a1) * k * exp(-x * x / 2.0) / sqrt(2.0 * pi));
    }
    else 
    {
        return 1.0 - N(-x);
    }
}

double EuropeanCall::dplus(double S0, double sigma, double r) 
{
    return (log(S0 / K) + (r + 0.5 * pow(sigma, 2.0)) * T) / (sigma * sqrt(T));
}

double EuropeanCall::dminus(double S0, double sigma, double r) 
{
    return dplus(S0, sigma, r) - sigma * sqrt(T);
}

double EuropeanCall::PriceByBSFormula(double S0, double sigma, double r) 
{
    return S0 * N(dplus(S0, sigma, r)) - K * exp(-r * T) * N(dminus(S0, sigma, r));
}

double EuropeanCall::VegaByBSFormula(double S0, double sigma, double r) 
{
    double pi = 4.0 * atan(1.0);
    return S0 * exp(-dplus(S0, sigma, r) * dplus(S0, sigma, r) / 2) * sqrt(T) / sqrt(2.0 * pi);
}
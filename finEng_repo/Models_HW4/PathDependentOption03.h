#pragma once

#ifndef PathDepOpt03
#define PathDepOpt03

#include "Model.h"
#include <algorithm>

//
//with calculation of greeks using finite differences
//
class PathDependentOption {
public:
    double T, Price, PricingError, delta, gamma, vega, theta, rho;
    int m;
    virtual double Payoff(SamplePath& S) = 0;
    double PriceByMC(BSModel Model, long N, double epsilon);
};

class ArithmeticAsianCall : public PathDependentOption {
public:
    double K;
    ArithmeticAsianCall(double T, double K, int m) { this->T = T; this->K = K; this->m = m; }
    double Payoff(SamplePath& S);
};
#endif
#pragma once
#ifndef EurCall01
#define EurCall01

#include <cmath>

class EuropeanCall {
public:
    double T, K;
    EuropeanCall(double T_, double K_) { T = T_; K = K_; }
    double dplus(double S0, double sigma, double r);
    double dminus(double S0, double sigma, double r);
    double PriceByBSFormula(double S0, double sigma, double r);
    double VegaByBSFormula(double S0, double sigma, double r);
};
#endif

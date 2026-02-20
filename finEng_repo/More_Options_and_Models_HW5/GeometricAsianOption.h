#pragma once
#ifndef GeometricAsianCall01
#define GeometricAsianCall01


#include "PathDependentOption04.h"

class GeometricAsianCall : public PathDependentOption {
public:
    double K;
    GeometricAsianCall(double T_, double K_, int m_) { T = T_; K = K_; m = m_; }
    double Payoff(SamplePath& S);
    double PriceByBSFormula(BSModel Model);
};
#endif


#pragma once

#ifndef PathDependentOption04
#define PathDependentOption04

#include "BSModel01.h"

class PathDependentOption {
public:
    double T, Price, PricingError;
    int m;
    virtual double Payoff(SamplePath& S) = 0;
    double PriceByMC(BSModel Model, long N);
    double PriceByVarianceReductionMC(BSModel model, long N, PathDependentOption& cvOption);
    virtual double PriceByBSFormula(BSModel model) { return 0.0; }
};

class DifferenceOfOptions : public PathDependentOption {
public:
    PathDependentOption* ptr1;
    PathDependentOption* ptr2;
    DifferenceOfOptions(double T, int m, PathDependentOption* ptr1, PathDependentOption* ptr2)
    {
        this->T = T; this->m = m; this->ptr1 = ptr1; this->ptr2 = ptr2;
    }
    double Payoff(SamplePath& S)
    {
        return ptr1->Payoff(S) - ptr2->Payoff(S);
    }
};

class ArithmeticAsianCall : public PathDependentOption
{
public:
    double K;
    ArithmeticAsianCall(double T, double K, int m)
    {
        this->T = T; this->K = K; this->m = m;
    }
    double Payoff(SamplePath& S);
};


#endif

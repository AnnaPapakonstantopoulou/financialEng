#pragma once

#ifndef PathDepOpt01
#define PathDepOpt01

#include "Model.h"
#include <algorithm>

class PathDependentOption
{
public:
    double T;
    int m;

    double PriceByMC(BSModel model, long N);
    virtual double Payoff(SamplePath& S) = 0;

};

class ArithmeticAsianCall : public PathDependentOption
{
public:
    double K;

    ArithmeticAsianCall(double T, double K, int m)
    {
        this->T = T;
        this->K = K;
        this->m = m;
    }

    double Payoff(SamplePath& S);
};

class EuropeanCall : public PathDependentOption
{
public:
    double K;
    EuropeanCall(double T, double K, int m)
    {
        this->T = T;
        this->K = K;
        this->m = m;
    }
    virtual double Payoff(SamplePath& S);
};

class EuropeanPut : public PathDependentOption
{
public:
    double K; //strike
    EuropeanPut(double T, double K, int m)
    {
        this->T = T;
        this->K = K;
        this->m = m;
    }
    virtual double Payoff(SamplePath& S);
};

#endif

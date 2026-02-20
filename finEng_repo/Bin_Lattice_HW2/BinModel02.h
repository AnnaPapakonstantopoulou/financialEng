#pragma once
#ifndef BinModel02
#define BinModel02

class BinModel
{
private:
    double S0;
    double U;
    double D;
    double R;

public:
    double RiskNeutralProbability();
    double S(int n, int i);
    int GetInputData();
    double GetR();
};
#endif 

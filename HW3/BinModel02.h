#pragma once
#ifndef BinModel02
#define BinModel02

class BinModel
{
public:

	int GetInputData();

	int GetExtraInputData();

	double RiskNeutralProb();

	double S(int n, int i);

	double GetR();

	double GetN();

	double GetK();

private:

	double S0;
	double U;
	double D;
	double R;
	int N;
	double K;

};

#endif
#pragma once

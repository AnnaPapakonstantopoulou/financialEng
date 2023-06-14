#pragma once
#ifndef Options03
#define Options03


int GetExtraInputData(int& N, double& K);

void Interchange(double& a, double& b);

void Bubblesort(double a[], int N);

double RiskNeutralProb(double U, double D, double R);

double CallPayoff(double z, double K);

double PutPayoff(double z, double K);

double CRR(double S0, double U, double D, double R, int N, double K);

double NewtonSymb(int N, int n);

#endif
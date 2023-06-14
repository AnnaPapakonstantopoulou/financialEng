#pragma once
#ifndef Options04
#define Options04

#include "BinModel02.h"


int GetExtraInputData(int& N, double& K);

double CallPayoff(double z, double K);

double PutPayoff(double z, double K);

double Digipayoff(double z, double K1, double K2);

double CRR(BinModel Model, double (*PayOff)(double z, double K));

double NewtonSymb(int N, int n);

#endif
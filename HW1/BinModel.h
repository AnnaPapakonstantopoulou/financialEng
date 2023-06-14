#pragma once
#ifndef BinModel
#define BinModel


int GetInputData(double& S0, double& U, double& D, double& R);

double RiskNeutralProb(double U, double D, double R);

double S(double S0, double U, double D, int n, double i);

#endif

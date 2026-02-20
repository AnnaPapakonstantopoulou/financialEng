#ifndef Options03
#define Options03

double PriceByCRR(double S0, double U, double D, double R, int N, double K, double(*Payoff)(double z, double K));
double CallPayoff(double z, double K);
double PutPayoff(double z, double K);
double NewtonSymb(int N, int i);
double PriceAnalyticCRR(double S0, double U, double D, double R, int N, double K, double(*Payoff)(double z, double K));

#endif /* Options03 */
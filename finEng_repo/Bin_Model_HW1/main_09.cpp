#include <iostream>
#include <cmath>

using namespace std;

//Calculate U and D
void calculateUandD(double sigma, double& U, double& D)
{
    //1 dT 
    double dT = 1.0;
    U = exp(sigma * sqrt(dT));
    D = exp(-sigma * sqrt(dT));
};

double calculateRiskNeutralProbability(double U, double D, double R, double deltaT) {
    return (exp(R * deltaT) - D) / (U - D);
}

//Call Opt price for dT = 1 period bin model
double callOptionPrice(double S0, double K, double R, double U, double D, double q) {
    double dT = 1.0; 
    double Cu = max(0.0, S0 * U - K); //payoff if UP
    double Cd = max(0.0, S0 * D - K); //payoff if DOWN
    double dF = exp(-R * dT); //discount factor

    double result = dF * (q * Cu + (1 - q) * Cd); //expected val of payoffs disc to T

    return result;
}

int main_09() {
    double sigma = 0.20; //vol
    double S0 = 100; //current stock price
    double K = 100; //strike price
    double R = 0.05; //rfr
    double dT = 1.0;

    double U, D;
    calculateUandD(sigma, U, D);


    double q = calculateRiskNeutralProbability(U, D, R, dT);
    double optionPrice = callOptionPrice(S0, K, R, U, D, q);

    cout << "Option Price: " << optionPrice << endl;

    return 0;
}
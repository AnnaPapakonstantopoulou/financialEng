#include <iostream>
#include <cmath>
#include "BinModel.h"
using namespace std;

// User Input
int GetInputData(double& S0, double& U, double& D, double& R) {

    cout << "Enter S0: ";
    cin >> S0; // 100
    cout << "Enter U: ";
    cin >> U; // 0.05
    cout << "Enter D: ";
    cin >> D; // -0.05
    cout << "Enter R: "; //rfr
    cin >> R; // 0

    // data range check
    if (S0 <= 0 || U <= -1.0 || D <= -1.0 || R <= -1.0 || U <= D) {
        cout << "Illegal data ranges" << endl;
        cout << "Terminating programme" << endl;
        return 1;
    }

    // arbitrage check - true only :
    if (R <= D || R >= U) {

        cout << "There is arbitrage" << endl;
        cout << "Terminating programme" << endl;
        return 1;
    }
    cout << "Input data check done" << endl;
    cout << "There is no arbitrage" << endl;

    return 0;
}

// calculate risk neutral probability
double RiskNeutralProb(double U, double D, double R)
{
    return (R - D) / (U - D);
}

//BinPrice
double S(double S0, double U, double D, int n, double i)
{
    return S0 * pow(1 + U, i) * pow(1 + D, n - i);  //return S0 * pow(1 + U, n - i) * pow(1 - D, i);
}
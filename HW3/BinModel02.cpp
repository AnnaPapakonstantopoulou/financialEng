#include <iostream>
#include <cmath>
#include "BinModel02.h"
using namespace std;

// User Input
int BinModel::GetInputData() {

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

int BinModel::GetExtraInputData()
{
    cout << "Enter steps to expiry N:"; cin >> N;
    cout << "Enter strike price K:"; cin >> K;
    cout << endl;
    return 0;
}


// calculate risk neutral probability
double BinModel::RiskNeutralProb()
{
    return (R - D) / (U - D);
}

//BinPrice
double BinModel::S(int n, int i)
{
    return S0 * pow(1 + U, i) * pow(1 + D, n - i);  //return S0 * pow(1 + U, n - i) * pow(1 - D, i);
}

double BinModel::GetR()
{
    return R;
}

double BinModel::GetN()
{
    return N;
}

double BinModel::GetK()
{
    return K;
}

#include "BinModel01.h"
#include <iostream>
#include <cmath>
using namespace std;

// computing risk-neutral probability
double riskNeutralProbability(double U, double D, double R)
{
	double q = (R - D) / (U - D);
	return q;
}


// computing the stock price at node (n,i)
double S(double S0, double U, double D, int n, int i)
{
	return S0 * pow(1 + U, i) * pow(1 + D, n - i);
}



//user data (incl. checks)
int getInputData(double* S0, double* U, double* D, double* R)
{
    // user inpurs
    cout << "Enter S0: ";
    cin >> *S0;
    cout << "Enter U: ";
    cin >> *U;
    cout << "Enter D: ";
    cin >> *D;
    cout << "Enter R: ";
    cin >> *R;
    //Check S0>0, (1+U)>0, (1+D)>0, (1+R)>0, U<D, else interchange U<->D
    if (*S0 <= 0 || *U <= -1.0 || *D <= -1.0 || *R <= -1.0 || *U <= *D) {
        cout << "Illegal data range" << endl;
        cout << "Terminating" << endl;
        return 1;
    }
    //Checking for arbitrage D < R < U; q > 1, or q < 0; q = (R -D) / (U - D)
    if (*R <= *D || *R >= *U) {
        cout << "Arbitrage exists" << endl;
        cout << "Terminating" << endl;
        return 1;
    }
    cout << "Input data checks done" << endl;
    cout << "There is no Arbitrage" << endl;
    return 0;
}


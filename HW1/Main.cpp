#include <iostream>
#include <cmath>
#include "BinModel.h"
#include "Options03.h"

using namespace std;

int main() {

    // Define the input variables
    double S0, U, D, R, K;
    int N;

    // Input data Initial price , Up and Down factors, IR
    if (GetInputData(S0, U, D, R) == 1) return 1;

    cout << "Call option data: " << endl;
    GetExtraInputData(N, K);


    //Risk neutral probability
    double q = RiskNeutralProb(U, D, R);
    cout << "Risk - neutral probability q = " << q << endl;

    double PriceByCRR = CRR(S0, U, D, R, N, K);
    cout << "Price by CRR = " << PriceByCRR << endl;

}
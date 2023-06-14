#include <iostream>
#include <cmath>
#include "BinModel02.h"
#include "Options04.h"

using namespace std;

int main()
{

    BinModel model;

    //Parse and validate input data
    if (model.GetInputData() == 1) return 1;

    
    cout << "Enter call option data:" << endl;

    model.GetInputData();
    cout << "European call option price=" << CRR(model, CallPayoff) << endl << endl;


    cout << "Enter put option data:" << endl;

    model.GetInputData();
    cout << "European put option price=" << CRR(model, PutPayoff) << endl << endl;
    
    
    return 0;

}
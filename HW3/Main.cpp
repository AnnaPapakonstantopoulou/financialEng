#include <iostream>
#include <cmath>
#include "BinModel02.h"
#include "Options06.h"

using namespace std;

int main()
{

    BinModel Model;
    Call CallOption;
    Put PutOption;
    Digi DigiOption;

    //Parse and validate input data
    if (Model.GetInputData() == 1) return 1;


    cout << "Enter call option data:" << endl;

    CallOption.GetInputData();
    cout << "European call option price=" << CallOption.CRR(Model) << endl << endl;


    cout << "Enter put option data:" << endl;

    PutOption.GetInputData();
    cout << "European put option price=" << PutOption.CRR(Model) << endl << endl;

    
    cout << "Enter digital option data:" << endl;

    DigiOption.GetInputData();
    cout << "European put option price=" << DigiOption.CRR(Model) << endl << endl;


    return 0;

}
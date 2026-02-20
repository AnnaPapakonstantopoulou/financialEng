#include "BinModel02.h"
#include "Options06.h"
#include <iostream>

using namespace std;

int main()
{
    BinModel model;


    if (model.GetInputData() == 1)
        return 1;

    CallBinModel callOpt;
    callOpt.GetInputData();

    std::cout << "European call option price:"
        << callOpt.PriceByCRR(model)
        << std::endl << std::endl;

    PutBinModel putOpt;
    putOpt.GetInputData();

    std::cout << "European put option price:"
        << putOpt.PriceByCRR(model)
        << std::endl << std::endl;

    DigiDouble doubleDigiOpt;
    doubleDigiOpt.GetInputData();

    std::cout << "Double Digital option price:"
        << doubleDigiOpt.PriceByCRR(model)
        << std::endl << std::endl;

    return 0;
}
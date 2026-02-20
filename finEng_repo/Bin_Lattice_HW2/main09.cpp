#include "BinLattice02.h"
#include "BinModel02.h"
#include "Options06.h"
#include <iostream>


//    double S0 = 100;
//    double K = 100
//    double R = 0.00;
//    double U = 0.03;
//    double D = -0.03;
//    double N = 4


using namespace std;

int main() {
    BinModel model;
    if (model.GetInputData() == 1)
        return 1;

    Call callOpt;
    callOpt.GetInputData();

    Put putOpt;
    putOpt.GetInputData();

    KO_Call KOCallOpt;
    KOCallOpt.GetInputData();

    KO_Put KOPutOpt;
    KOPutOpt.GetInputData();

    KI_Call KICallOpt;
    KICallOpt.GetInputData();

    KI_Put KIPutOpt;
    KIPutOpt.GetInputData();

    BinLattice<double> callOptionPriceTree;
    BinLattice<bool> callOptionStopTree;
    BinLattice<double> callOptionDeltaTree;
    BinLattice<double> callOptionCashTree;

    BinLattice<double> putOptionPriceTree;
    BinLattice<bool> putOptionStopTree;
    BinLattice<double> putOptionDeltaTree;
    BinLattice<double> putOptionCashTree;

    BinLattice<double> KOCallPriceTree;
    BinLattice<bool> KOCallStopTree;
    BinLattice<double> KOCallDeltaTree;
    BinLattice<double> KOCallCashTree;

    BinLattice<double> KICallPriceTree;
    BinLattice<bool> KICallStopTree;
    BinLattice<double> KICallDeltaTree;
    BinLattice<double> KICallCashTree;

    BinLattice<double> KOPutPriceTree;
    BinLattice<bool> KOPutStopTree;
    BinLattice<double> KOPutDeltaTree;
    BinLattice<double> KOPutCashTree;

    BinLattice<double> KIPutPriceTree;
    BinLattice<bool> KIPutStopTree;
    BinLattice<double> KIPutDeltaTree;
    BinLattice<double> KIPutCashTree;

    double europeanCallOptionPrice = callOpt.PriceByCRRBinLattice(model, callOptionDeltaTree, callOptionCashTree);
    double europeanPutOptionPrice = putOpt.PriceByCRRBinLattice(model, putOptionDeltaTree, putOptionCashTree);

    double americanCallOptionPrice = callOpt.PriceBySnell(model, callOptionPriceTree, callOptionStopTree);
    double americanPutOptionPrice = putOpt.PriceBySnell(model, putOptionPriceTree, putOptionStopTree);

    double KOCallPrice = KOCallOpt.PriceByCRRBinLattice(model, callOptionDeltaTree, callOptionCashTree);
    double KOPutPrice = KOPutOpt.PriceByCRRBinLattice(model, putOptionDeltaTree, putOptionCashTree);
    double KICallPrice = KICallOpt.PriceByCRRBinLattice(model, callOptionDeltaTree, callOptionCashTree);
    double KIPutPrice = KIPutOpt.PriceByCRRBinLattice(model, putOptionDeltaTree, putOptionCashTree);

    double americanKOCallOptionPrice = KOCallOpt.PriceBySnell(model, KOCallPriceTree, KOCallStopTree);
    double americanKOPutOptionPrice = KOPutOpt.PriceBySnell(model, KOPutPriceTree, KOPutStopTree);
    double americanKICallOptionPrice = KICallOpt.PriceBySnell(model, KICallPriceTree, KICallStopTree);
    double americanKIPutOptionPrice = KIPutOpt.PriceBySnell(model, KIPutPriceTree, KIPutStopTree);

    //Display   
    cout << "European Call price" << europeanCallOptionPrice << endl;
    cout << "European Put price" << europeanPutOptionPrice << endl;

    cout << "American Call Option price" << americanCallOptionPrice << endl;
    cout << "American Put Option price" << americanPutOptionPrice << endl;

    cout << "European Call KO price" << KOCallPrice << endl;
    cout << "European Put KO price" << KOPutPrice << endl;
    cout << "European Call KI price" << KICallPrice << endl;
    cout << "European Put KI price" << KIPutPrice << endl;

    cout << "American Call KO price" << americanKOCallOptionPrice << endl;
    cout << "American Put KO price" << americanKOPutOptionPrice << endl;
    cout << "American Call KI price" << americanKICallOptionPrice << endl;
    cout << "American Put KI price" << americanKIPutOptionPrice << endl;

    return 0;
}
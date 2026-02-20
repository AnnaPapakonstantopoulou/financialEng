
#include "Options06.h"
#include "BinModel02.h"
#include "BinLattice02.h"
#include <iostream>
#include <vector>

double EuropeanOption::PriceByCRR(BinModel model)
{
    double q = model.RiskNeutralProbability();
    std::vector<double> price(N + 1);

    for (int i = 0; i <= N; i++)
    {
        price[i] = Payoff(model.S(N, i));
    }

    for (int n = N - 1; n >= 0; n--)
    {
        for (int i = 0; i <= n; i++)
        {
            price[i] = (q * price[i + 1] + (1 - q) * price[i]) / (1 + model.GetR());
        }
    }
    return price[0];
}
double EurOptionBinLattice::PriceByCRRBinLattice(BinModel model, BinLattice<double>& deltaLatticeTree, BinLattice<double>& cashLatticeTree) {
    double q = model.RiskNeutralProbability();
    int N = GetN();
    deltaLatticeTree.SetN(N);
    cashLatticeTree.SetN(N);
    BinLattice<double> priceTree;
    priceTree.SetN(N);

    // Compute option prices at maturity and store them in PriceTree
    for (int i = 0; i <= N; i++) {
        priceTree.SetNode(N, i, Payoff(model.S(N, i)));
    }
    for (int n = N - 1; n >= 0; n--) {
        for (int i = 0; i <= n; i++) {
            double ContVal = (q * priceTree.GetNode(n + 1, i + 1) + (1 - q) * priceTree.GetNode(n + 1, i)) / (1 + model.GetR());
            priceTree.SetNode(n, i, ContVal);
        }
    }

    for (int n = N; n >= 0; n--) {
        for (int i = 0; i <= n; i++) {
            if (n < N) {
                double delta;
                delta = (priceTree.GetNode(n + 1, i + 1) - priceTree.GetNode(n + 1, i)) / (model.S(n + 1, i + 1) - model.S(n + 1, i));
                deltaLatticeTree.SetNode(n, i, delta);
                double cash = (priceTree.GetNode(n + 1, i) - deltaLatticeTree.GetNode(n, i) * model.S(n + 1, i)) / (1 + model.GetR());
                cashLatticeTree.SetNode(n, i, cash);
            }
            else {
                if (priceTree.GetNode(n, i) > 0) {
                    deltaLatticeTree.SetNode(n, i, 1.0);
                }
            }
        }
    }
    return priceTree.GetNode(0, 0);
}

double AmericanOption::PriceBySnell(BinModel model,
    BinLattice<double>& priceTree,
    BinLattice<bool>& stopTree)
{
    double q = model.RiskNeutralProbability();
    int N = GetN();
    priceTree.SetN(N);
    stopTree.SetN(N);
    double val;
    for (int i = 0; i <= N; i++)
    {
        priceTree.SetNode(N, i, Payoff(model.S(N, i)));
        stopTree.SetNode(N, i, 1);
    }
    for (int n = N - 1; n >= 0; n--) {
        for (int i = 0; i <= n; i++)
        {
            val = (q * priceTree.GetNode(n + 1, i + 1)
                + (1 - q) * priceTree.GetNode(n + 1, i))
                / (1 + model.GetR());

            priceTree.SetNode(n, i, Payoff(model.S(n, i)));

            stopTree.SetNode(n, i, 1);

            double dp = 0.01; //decimal places
            // If val is greater than priceTree.GetNode(n, i) 
            if (round(val * 100) / 100 > round(priceTree.GetNode(n, i) * 100) / 100 + dp)
            {
                priceTree.SetNode(n, i, val);
                stopTree.SetNode(n, i, 0);
            }
            else if (priceTree.GetNode(n, i) == 0.0)
            {
                stopTree.SetNode(n, i, 0);
            }
        }
    }
    return priceTree.GetNode(0, 0);
}


int CallBinModel::GetInputData()
{
    std::cout << "Input call option data" << std::endl;
    int N;
    std::cout << "Input steps to expiry N";
    std::cin >> N;
    SetN(N);
    std::cout << "Input strike price K";
    std::cin >> K;
    std::cout << std::endl;
    return 0;
}

double CallBinModel::Payoff(double z)
{
    if (z > K)
        return z - K;
    return 0.0;
}

int PutBinModel::GetInputData()
{
    std::cout << "Input put option data" << std::endl;
    int N;
    std::cout << "Input steps to expiry N";
    std::cin >> N;
    SetN(N);
    std::cout << "Input strike price K";
    std::cin >> K;
    std::cout << std::endl;
    return 0;
}

double PutBinModel::Payoff(double z)
{
    if (z < K)
        return K - z;
    return 0.0;
}


int DigiDouble::GetInputData()
{
    std::cout << "Input double digital option data" << std::endl;
    int N;
    std::cout << "Input steps to expiry N";
    std::cin >> N;
    SetN(N);
    std::cout << "Input lower strike price K1";
    std::cin >> K1;
    std::cout << "Input upper strike price K2";
    std::cin >> K2;
    std::cout << std::endl;
    return 0;
}

double DigiDouble::Payoff(double z) {
    if (z > K1 && z < K2)
        return 1.0;
    return 0.0;
}

//Barriers

int KO_Call::GetInputData() {
    cout << "Enter knock-out call option data" << endl;
    int N;
    cout << "Enter steps to expiry N";
    cin >> N;
    SetN(N);
    cout << "Enter strike price K";
    cin >> K;
    cout << "Enter barrier price";
    cin >> Barrier;
    cout << endl;
    return 0;
}



int KO_Put::GetInputData() {
    cout << "Enter knock out put option data" << endl;
    int N;
    cout << "Enter steps to expiry N";
    cin >> N;
    SetN(N);
    cout << "Enter strike price K";
    cin >> K;
    cout << "Enter barrier price";
    cin >> Barrier;
    cout << endl;
    return 0;
}



int KI_Call::GetInputData() {
    cout << "Enter knock in call option data" << endl;
    int N;
    cout << "Enter steps to expiry N";
    cin >> N;
    SetN(N);
    cout << "Enter strike price K";
    cin >> K;
    cout << "Enter barrier price";
    cin >> Barrier;
    cout << endl;
    return 0;
}

int KI_Put::GetInputData() {
    cout << "Enter knock in put option data" << endl;
    int N;
    cout << "Enter steps to expiry N";
    cin >> N;
    SetN(N);
    cout << "Enter strike price K";
    cin >> K;
    cout << "Enter barrier price";
    cin >> Barrier;
    cout << endl;
    return 0;
}

double KO_Put::Payoff(double z) {
    if (z < Barrier) // knocked-out
        return 0.0;
    if (z < K) // ITM
        return K - z;
    return 0.0; // OTM
}

double KO_Call::Payoff(double z) {
    if (z > Barrier) // knocked-out
        return 0.0;
    if (z > K) // ITM
        return z - K;
    return 0.0; // OTM
}

double KI_Call::Payoff(double z) {
    if (z > Barrier) // knocked-in
        return z - K;
    return 0.0; // OTM
}


double KI_Put::Payoff(double z) {
    if (z < Barrier) // knocked-in
        return K - z;
    return 0.0; // OTM
}


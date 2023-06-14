#include <iostream>
#include <cmath>
#include <vector>
#include "BinModel02.h"
#include "Options06.h"
using namespace std;

// european call option price
double EuropeanOption::CRR(BinModel Model)
{
    int K = Model.GetK();
    double N = Model.GetN();
    double q = Model.RiskNeutralProb();

    std::vector<double> Price(N + 1);

    // call option payoff calc
    for (int i = 0; i <= N; i++)
    {
        Price[i] = Payoff(Model.S(N, i));
    }

    // option price calc - backward step
    for (int n = N - 1; n >= 0; n--)
    {
        for (int i = 0; i <= n; i++)
        {
            Price[i] = (q * Price[i + 1] + (1 - q) * Price[i]) / (1 + Model.GetR());
        }
    }

    return Price[0]; // Return Si
}


// payoff of a call option
double Call::Payoff(double z)
{
    if (z > K) return (z - K);
    return 0.0;
}

// payoff of a put option
double Put::Payoff(double z)
{
    if (z < K) return (K - z);
    return 0.0;
}

// payoff of a digital option
double Digi::Payoff(double z)
{
    if (K1 <= z <= K2) return z;
    return 0.0;
}

int Call::GetInputData()
{
    //model.GetExtraInputData();
    cout << "Enter call option data :" << endl;
    int N;
    cout << "Enter steps to expiry, N: "; cin >> N;
    setN(N);
    cout << "Enter strike price, K: "; cin >> K;
    cout << endl;

    return 0;
}

int Put::GetInputData()
{
    cout << "Enter put option data :" << endl;
    int N;
    cout << "Enter steps to expiry, N: "; cin >> N;
    setN(N);
    cout << "Enter strike price, K: "; cin >> K;
    cout << endl;

    return 0;

}

int Digi::GetInputData()
{
    cout << "Enter put option data :" << endl;
    int N;
    cout << "Enter steps to expiry, N: "; cin >> N;
    setN(N);
    cout << "Enter strike price 1, K1: "; cin >> K1;
    cout << "Enter strike price 2, K2: "; cin >> K2;
    cout << endl;

    return 0;

}
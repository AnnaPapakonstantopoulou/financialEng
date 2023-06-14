#include <iostream>
#include <cmath>
#include <vector>
#include "BinModel02.h"
#include "Options04.h"

using namespace std;


int GetExtraInputData(int& N, double& K) {
    cout << "Enter steps to expiry, N: ";
    cin >> N;
    cout << "Enter strike price, K: ";
    cin >> K;
    cout << endl;

    return 0;
}


// payoff of a call option
double CallPayoff(double z, double K)
{
    if (z > K) return (z - K);
    return 0.0;
}

// payoff of a put option
double PutPayoff(double z, double K)
{
    if (z < K) return (K - z);
    return 0.0;
}

// payoff of a digital option
double Digipayoff(double z, double K1, double K2)
{
    if (K1 <= z <= K2) return z;
    return 0.0;
}

// european call option price
double CRR(BinModel Model, double (*PayOff)(double z, double K))
{
    int K = Model.GetK();
    double N = Model.GetN();
    double q = Model.RiskNeutralProb();

    std::vector<double> Price(N + 1);

    // call option payoff calc
    for (int i = 0; i <= N; i++)
    {
        Price[i] = CallPayoff(Model.S(N, i), K);
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


double NewtonSymb(int N, int n)
{
    if (n < 0 || n > N)
    {
        return 0;
    }
    double result = 1;
    for (int i = 1; i <= n; i++)
    {
        result = result * (N - n + i) / i;
    }
    return result;
}
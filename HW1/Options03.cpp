#include <iostream>
#include <cmath>
#include <ranges>
#include <vector>
#include <algorithm>
#include "BinModel.h"
#include "Options03.h"

using namespace std;

void Interchange(double& a, double& b)
{
    double c = a;
    a = b;
    b = c;
}

void Bubblesort(double a[], int N)
{
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j <= N - i; j++)
        {
            if (a[j - 1] > a[j]) Interchange(a[j - 1], a[j]);
        }
    }
}


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

// european call option price
double CRR(double S0, double U, double D, double R, int N, double K)
{
    double q = RiskNeutralProb(U, D, R);

    std::vector<double> Price(N + 1);

    // call option payoff calc
    for (int i = 0; i <= N; i++)
    {
        Price[i] = CallPayoff(S(S0, U, D, N, i), K);
    }

    // option price calc - backward step
    for (int n = N - 1; n >= 0; n--)
    {
        for (int i = 0; i <= n; i++)
        {
            Price[i] = (q * Price[i + 1] + (1 - q) * Price[i]) / (1 + R);
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
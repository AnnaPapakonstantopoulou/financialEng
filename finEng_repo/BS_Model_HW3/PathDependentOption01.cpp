
#include "PathDependentOption01.h"
#include <cmath>

double PathDependentOption::PriceByMC(BSModel model, long N) {
    double sumOfPayoffs = 0.0; //for all simulated paths
    SamplePath S(m); //size of vector

    for (long i = 0; i < N; i++)
    {
        model.GenSamplePath(T, m, S);
        sumOfPayoffs += Payoff(S);
    }

    return exp(-model.r * T) * sumOfPayoffs / N;
}

double ArithmeticAsianCall::Payoff(SamplePath& S) {
    double arithAvg = 0.0;
    for (int k = 0; k < m; k++)
        arithAvg = (k * arithAvg + S[k]) / (k + 1.0);
    if (arithAvg < K)
        return 0.0;
    return arithAvg - K;
}

double EuropeanCall::Payoff(SamplePath& S) {
    double ST = S.back(); //last price from path
    return std::max(0.0, ST - K); //+ive bcs call opt
}

double EuropeanPut::Payoff(SamplePath& S) {
    double ST = S.back();
    return std::max(0.0, K - ST); //put opt
}


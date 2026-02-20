
#include "PathDependentOption03.h"
#include <algorithm>
#include <cmath>

double ArithmeticAsianCall::Payoff(SamplePath& S) {
    double arithAvg = 0.0;
    for (int k = 0; k < m; k++)
        arithAvg = (k * arithAvg + S[k]) / (k + 1.0);
    if (arithAvg < K)
        return 0.0;
    return arithAvg - K;
}

void Rescale(SamplePath& S, double x) {
    int m = S.size();
    for (int i = 0; i < m; i++)
        S[i] = x * S[i];
}

double PathDependentOption::PriceByMC(BSModel model, long N, double epsilon) {
    double avg = 0.0; //running average of payoff for base path
    double avgSquared = 0.0; //same but squared - for error
    SamplePath S(m);
    double avgEpsilonPlus = 0.0, avgEpsilonMinus = 0.0, avgVega = 0.0, avgTheta = 0.0, avgRho = 0.0;
    for (long i = 0; i < N; i++) {
        model.GenSamplePath(T, m, S);
        // Standard calculations for avg and avgSq
        avg = (i * avg + Payoff(S)) / (i + 1.0);
        avgSquared = (i * avgSquared + pow(Payoff(S), 2.0)) / (i + 1.0);

        // Calculations for Gamma
        Rescale(S, 1.0 + epsilon); //scaled up
        avgEpsilonPlus = (i * avgEpsilonPlus + Payoff(S)) / (i + 1.0);
        Rescale(S, (1.0 - epsilon) / (1.0 + epsilon)); //scaled down then adj
        avgEpsilonMinus = (i * avgEpsilonMinus + Payoff(S)) / (i + 1.0);
        Rescale(S, 1.0 / (1.0 - epsilon)); //reset S

        // For Vega: Increase sigma
        double originalSigma = model.sigma;
        model.sigma += epsilon;
        model.GenSamplePath(T, m, S);
        avgVega = (i * avgVega + Payoff(S)) / (i + 1.0);
        model.sigma = originalSigma; //reset sigma

        // For Theta: Decrease T
        double originalT = T;
        T -= epsilon;
        if (T < 0) T = epsilon; //T>0
        model.GenSamplePath(T, m, S);
        avgTheta = (i * avgTheta + Payoff(S)) / (i + 1.0);
        T = originalT; //reset T

        // For Rho: Increase r
        double originalR = model.r;
        model.r += epsilon;
        model.GenSamplePath(T, m, S);
        avgRho = (i * avgRho + Payoff(S)) / (i + 1.0);
        model.r = originalR; //reset r
    }

    double disc = exp(-model.r * T);
    double price = disc * avg;
    double pricingError = disc * sqrt(avgSquared - avg * avg) / sqrt(N - 1.0);
    delta = disc * (avgEpsilonPlus - avg) / (model.S0 * epsilon);
    gamma = disc * (avgEpsilonPlus - 2 * avg + avgEpsilonMinus) / (model.S0 * model.S0 * epsilon * epsilon);
    vega = disc * (avgVega - avg) / epsilon; //sensitivity to sigma
    theta = disc * (avg - avgTheta) / epsilon; //sensitivity to T
    rho = disc * (avgRho - avg) / epsilon; //sensitivity to r

    return price;
}


#include "PathDependentOption04.h"
#include <cmath>

double PathDependentOption::PriceByMC(BSModel model, long N) {
    double H = 0.0, Hsq = 0.0;
    SamplePath S(m);
    for (long i = 0; i < N; i++) {
        model.GenSamplePath(T, m, S);
        H = (i * H + Payoff(S)) / (i + 1.0);
        Hsq = (i * Hsq + pow(Payoff(S), 2.0)) / (i + 1.0);
    }
    Price = exp(-model.r * T) * H;
    PricingError = exp(-model.r * T) * sqrt(Hsq - H * H) / sqrt(N - 1.0);
    return Price;
}

double PathDependentOption::PriceByVarianceReductionMC(BSModel model, long N, PathDependentOption& cvOption)
{
    DifferenceOfOptions VarRedOpt(T, m, this, &cvOption);
    Price = VarRedOpt.PriceByMC(model, N) + cvOption.PriceByBSFormula(model);
    PricingError = VarRedOpt.PricingError;
    return Price;
}

double ArithmeticAsianCall::Payoff(SamplePath& S) {
    double arithAvg = 0.0;
    for (int k = 0; k < m; k++)
        arithAvg = (k * arithAvg + S[k]) / (k + 1.0);
    if (arithAvg < K)
        return 0.0;
    return arithAvg - K;
}
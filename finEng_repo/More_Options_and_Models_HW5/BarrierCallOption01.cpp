#include "BarrierCallOption01.h"

void BarrierCallOption::CalculateEuropeanCallPrice(const BSModel& model) {
    eurCall = new EuropeanCall(T, K);
    eurCallPrice = eurCall->PriceByBSFormula(model.S0, model.sigma, model.r);
}

double BarrierCallOption::Payoff(SamplePath& S) {
    double payoff = 0.0;
    double MaxS = *std::max_element(S.begin(), S.end());
    if (MaxS <= L) {
        double finalPrice = S.back();
        payoff = std::max(finalPrice - K, 0.0); //barrier option payoff
    }

    //for same path:
    double eurCallPayoff = std::max(S.back() - K, 0.0);

    //adjust barrier option payoff using the control variate technique with the European Call price
    payoff += (eurCallPrice - eurCallPayoff); //use the member variable

    return payoff;
}
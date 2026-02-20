#ifndef BarrierCallOption01
#define BarrierCallOption01

#include "PathDependentOption04.h"
#include <algorithm> // For max_element
#include "EuropeanCallOption.h"

class BarrierCallOption : public PathDependentOption {
public:
    double K, L;
    EuropeanCall* eurCall; // Dynamically allocated to adjust for different market conditions
    double eurCallPrice; // To store calculated European Call price internally

    BarrierCallOption(double T_, double K_, double L_, int m_)
        : PathDependentOption(), K(K_), L(L_), eurCall(nullptr), eurCallPrice(0.0) {
        T = T_;
        m = m_;
    }

    ~BarrierCallOption() {
        if (eurCall) delete eurCall;
    }

    void CalculateEuropeanCallPrice(const BSModel& model);

    double Payoff(SamplePath& S) override;
};


#endif //QUANT_HOMEWORK_BARRIERCALLOPTION_H

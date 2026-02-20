
#define _USE_MATH_DEFINES

#include "BSModel01.h"
#include <cmath>

double Gauss()
{
    double U1 = (rand() + 1.0) / (RAND_MAX + 1.0);
    double U2 = (rand() + 1.0) / (RAND_MAX + 1.0);

    return sqrt(-2.0 * log(U1)) * cos(2.0 * M_PI * U2);
}

void BSModel::GenSamplePath(double T, int m, SamplePath& S)
{
    double St = S0;
    for (int k = 0; k < m; k++) {
        S[k] = St * exp((r - sigma * sigma * 0.5) * (T / m) + sigma * sqrt(T / m) * Gauss());
        St = S[k];
    }
}

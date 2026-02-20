
#define _USE_MATH_DEFINES

#include "Model.h"
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
    double dt = T / m;
    for (int k = 0; k < m; k++) {
        S[k] = St * exp((r - sigma * sigma * 0.5) * dt
            + sigma * sqrt(T / m) * Gauss());
        St = S[k];
    }
}

void VasicekModel::GenSamplePath(double T, int m, vector<double>& r)
{
    r.resize(m + 1);
    r[0] = r0;
    double dt = T / m;
    for (int k = 0; k < m; k++) 
    {
        r[k + 1] = r[k] + alpha * (beta - r[k]) * dt + sigma * sqrt(dt) * Gauss();
    }
}

void HullWhiteModel::GenSamplePath(double T, int m, vector<double>& r)
{
    r.resize(m + 1);
    r[0] = r0;
    double dt = T / m;
    for (int k = 0; k < m; k++) 
    {
        r[k + 1] = r[k] + alpha * (0.0 - r[k]) * dt + sigma * sqrt(dt) * Gauss();
    }
}
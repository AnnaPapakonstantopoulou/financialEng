#pragma once
#ifndef BSModel01
#define BSModel01
#include <vector>
#include <ctime>

using namespace std;

typedef vector<double> SamplePath;


class BSModel
{
public:
    double S0;
    double r;
    double sigma;
    BSModel(double S0, double r, double sigma) : S0(S0), r(r), sigma(sigma)
    {
        srand(time(NULL));
    }

    void GenSamplePath(double T, int m, SamplePath& S);

};
#endif
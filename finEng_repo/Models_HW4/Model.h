#pragma once
#ifndef Model
#define Model

#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef vector<double> SamplePath;


class BSModel
{
public:
    double S0;
    double r;
    double sigma;
    BSModel(double S0, double r, double sigma)
        : S0(S0), 
        r(r), 
        sigma(sigma)
    {
        srand(time(NULL));
    }

    void GenSamplePath(double T, int m, vector<double>& S);

};

class VasicekModel
{
private:
    double r0;
    double alpha;
    double beta;
    double sigma;


public:
    VasicekModel(double r0, double alpha, double beta, double sigma) 
        : r0(r0), 
        alpha(alpha), 
        beta(beta), 
        sigma(sigma)
    {
        srand(time(NULL));
    };
    void GenSamplePath(double T, int m, vector<double>& r);
};


class HullWhiteModel
{
public:
    double r0;
    double alpha;
    double sigma;

public:
    HullWhiteModel(double r0, double alpha, double sigma)
        : r0(r0), 
        alpha(alpha), 
        sigma(sigma)
    {
        srand(time(NULL));
    };

    void GenSamplePath(double T, int m, vector<double>& r);
};
#endif
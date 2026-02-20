
#include "PathDependentOption01.h"
#include <iostream>
#include <fstream>


using namespace std;

int main() 
{
    //Black-Scholes parameters
    double S0 = 100.0;
    double r = 0.03;
    double sigma = 0.2;

    //Vasicek parameters
    double r0_vasicek = 0.05;
    double alpha_vasicek = 0.1;
    double beta_vasicek = 0.05;
    double sigma_vasicek = 0.02;

    //Hull-White parameters
    double r0_hw = 0.05;
    double alpha_hw = 0.1;
    double sigma_hw = 0.02;

    double T = 1.0; //time
    int m = 100;    //number of time steps

    
    vector<double> samplePathBS(m);
    vector<double> samplePathVasicek(m + 1);
    vector<double> samplePathHW(m + 1); 

    //init
    BSModel bsModel(S0, r, sigma);
    VasicekModel vasicekModel(r0_vasicek, alpha_vasicek, beta_vasicek, sigma_vasicek);
    HullWhiteModel hwModel(r0_hw, alpha_hw, sigma_hw);

    //Generate sample paths
    bsModel.GenSamplePath(T, m, samplePathBS);
    vasicekModel.GenSamplePath(T, m, samplePathVasicek);
    hwModel.GenSamplePath(T, m, samplePathHW);

    //print the generated paths
    cout << "Black-Scholes sample path:" << endl;
    for (int i = 0; i < m; ++i)
    {
        cout << "S[" << i << "] = " << samplePathBS[i] << endl;
    }

    cout << "\nVasicek sample path:" << endl;
    for (int i = 0; i <= m; ++i)
    {
        cout << "r[" << i << "] = " << samplePathVasicek[i] << endl;
    }

    cout << "\nHull-White sample path:" << endl;
    for (int i = 0; i <= m; ++i)
    {
        cout << "r[" << i << "] = " << samplePathHW[i] << endl;
    }

    ofstream outputFile("print_sample_paths.txt");
    if (outputFile.is_open()) {
        outputFile << "Black-Scholes sample path:\n";
        for (int i = 0; i < m; ++i) {
            outputFile << samplePathBS[i] << endl;
        }

        outputFile << "\nVasicek sample path:\n";
        for (int i = 0; i <= m; ++i)
        {
            outputFile << samplePathVasicek[i] << endl;
        }

        outputFile << "\nHull-White sample path:\n";
        for (int i = 0; i <= m; ++i)
        {
            outputFile << samplePathHW[i] << endl;
        }

        outputFile.close();
        cout << "saved to print_sample_paths.txt\n";
    }
    else {
        cout << "Cannot open file. Do you have it open in the background?\n";
    }

    return 0;
}
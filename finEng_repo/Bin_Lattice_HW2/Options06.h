#ifndef Options06
#define Options06
#include "BinModel02.h"
#include"BinLattice02.h"

//European Option Class for BinModel
class EuropeanOption
{
private:
    int N; //steps to expiry

public:
    void SetN(int N_) { N = N_; }
    virtual double Payoff(double z) { return 0.0; }
    virtual double PriceByCRR(BinModel model);
};


class CallBinModel : public EuropeanOption
{
private:
    double K; //strike
public:
    void SetK(double K_) { K = K_; }
    int GetInputData();
    virtual double Payoff(double z);
};



class PutBinModel : public EuropeanOption
{
private:
    double K; 

public:
    void SetK(double K_) { K = K_; }
    int GetInputData();
    virtual double Payoff(double z);
};


// Digital Double
class DigiDouble : public EuropeanOption
{
private:
    double K1; //lower strike
    double K2; //upper strike

public:
    void SetK(double K1, double K2) { this->K1 = K1; this->K2 = K2; }
    int GetInputData();
    virtual double Payoff(double z);
};

////////////////////////////////
// 
//General Option Class to use for BinLattice
class Option {
private:
    int N;

public:
    void SetN(int N_) { N = N_; }
    int GetN() { return N; }
    virtual double Payoff(double z) = 0;
};


class EurOptionBinLattice : public virtual Option 
{
public:

    double PriceByCRRBinLattice(BinModel model, BinLattice<double>& DeltaTree, BinLattice<double>& CashPositionTree);
};

class AmericanOption : public virtual Option 
{
public:
    // pricing American option
    double PriceBySnell(BinModel model,
        BinLattice<double>& PriceTree,
        BinLattice<bool>& StoppingTree);
};

class Call : public EurOptionBinLattice, public AmericanOption 
{
private:
    double K; //strike
public:
    void SetK(double K_) {
        K = K_;
    }
    int GetInputData();
    double Payoff(double z);
};

class Put : public EurOptionBinLattice, public AmericanOption 
{
private:
    double K; //strike

public:
    void SetK(double K_) { K = K_; }
    int GetInputData();
    double Payoff(double z);
};


class KO_Call : public EurOptionBinLattice, public AmericanOption 
{
private:
    double K;
    double Barrier;

public:
    int GetInputData();
    double Payoff(double z);
};

class KI_Call : public EurOptionBinLattice, public AmericanOption 
{
private:
    double K;
    double Barrier;

public:
    int GetInputData();
    double Payoff(double z);
};

class KO_Put : public EurOptionBinLattice, public AmericanOption 
{
private:
    double K;
    double Barrier;

public:
    int GetInputData();
    double Payoff(double z);
};

class KI_Put : public EurOptionBinLattice, public AmericanOption 
{
private:
    double K;
    double Barrier;

public:
    int GetInputData();
    double Payoff(double z);
};


#endif
#pragma once

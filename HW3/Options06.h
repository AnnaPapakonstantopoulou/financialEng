#pragma once
#ifndef Options06
#define Options06

#include "BinModel02.h"

class EuropeanOption
{
	

	public:
		void setN(int N_) { N = N_; }

        virtual double Payoff(double z) { return 0.0; }

		double CRR(BinModel Model);

	private:

		int N;
};


class Call : public EuropeanOption
{

    public:
        int GetInputData();

        void SetK(double K_) { K = K_; }

        virtual double Payoff(double z);

    private:
        double K;
};

class Put : public EuropeanOption
{

public:
    int GetInputData();

    void SetK(double K_) { K = K_; }

    virtual double Payoff(double z);

private:
    double K;
};

class Digi : public EuropeanOption
{

public:
    int GetInputData();

    virtual double Payoff(double z);

private:
    double K1;
    double K2;
};



#endif

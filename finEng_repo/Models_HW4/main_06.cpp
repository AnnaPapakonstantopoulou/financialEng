
#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
#include <random>

//
// analytical calculation wiht greeks
//

//average of a vector
double averageOfVector(const std::vector<double>& vec) {
    return std::accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
}

//Monte Carlo for Asian Call Option pricing
double asianCallPrice(int N, double S0, double K, double r, double sigma, double T, int observations)
{
    std::mt19937_64 rng;
    rng.seed(std::random_device()());
    std::normal_distribution<double> dist(0, 1);

    double dt = T / observations;
    std::vector<double> payoffs;

    for (int i = 0; i < N; ++i)
    {
        std::vector<double> path;
        double S = S0;
        for (int j = 0; j < observations; ++j) {
            S *= exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * dist(rng));
            path.push_back(S);
        }
        double avgPrice = averageOfVector(path);
        payoffs.push_back(std::max(avgPrice - K, 0.0));
    }

    double meanPayoff = averageOfVector(payoffs);
    return exp(-r * T) * meanPayoff;
}

// Approximating Vega
double vega(int N, double S0, double K, double r, double sigma, double T, int observations)
{
    double sigmaUp = sigma + 0.01; // Increase sigma by 1%
    double priceOriginal = asianCallPrice(N, S0, K, r, sigma, T, observations);
    double priceSigmaUp = asianCallPrice(N, S0, K, r, sigmaUp, T, observations);
    return (priceSigmaUp - priceOriginal) / 0.01; // Vega approximation
}

// Approximating Theta
double theta(int N, double S0, double K, double r, double sigma, double T, int observations)
{
    double TShorter = T - (1.0 / 365.0); // Move time forward by one day
    double priceOriginal = asianCallPrice(N, S0, K, r, sigma, T, observations);
    double priceTimeShorter = asianCallPrice(N, S0, K, r, sigma, TShorter, observations);
    return (priceTimeShorter - priceOriginal) / (-1.0 / 365.0); // Theta approximation
}

// Approximating Rho
double rho(int N, double S0, double K, double r, double sigma, double T, int observations)
{
    double rUp = r + 0.01; // Increase r by 1%
    double priceOriginal = asianCallPrice(N, S0, K, r, sigma, T, observations);
    double priceRUp = asianCallPrice(N, S0, K, rUp, sigma, T, observations);
    return (priceRUp - priceOriginal) / 0.01; // Rho approximation
}

int main()
{
    int N = 50000; // Number of simulations
    double S0 = 100; // Spot price
    double K = 100; // Strike price
    double r = 0.03; // Risk free rate
    double sigma = 0.2; // Volatility
    double T = 1.0 / 12.0; // Time to expiry = 1m
    int observations = 30; // Daily observations for 30 days

    double price = asianCallPrice(N, S0, K, r, sigma, T, observations);
    std::cout << "Asian Call Option Price: " << price << std::endl;

    double optionVega = vega(N, S0, K, r, sigma, T, observations);
    double optionTheta = theta(N, S0, K, r, sigma, T, observations);
    double optionRho = rho(N, S0, K, r, sigma, T, observations);

    std::cout << "Vega: " << optionVega << std::endl;
    std::cout << "Theta: " << optionTheta << std::endl;
    std::cout << "Rho: " << optionRho << std::endl;

    return 0;
}
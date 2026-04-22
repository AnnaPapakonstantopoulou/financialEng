# Financial Engineering Homework — City University London

C++ implementations of derivatives pricing models completed as coursework for the Financial Engineering short course at City University London.

---

## Overview

Five progressive homework assignments covering core quantitative finance topics — from basic binomial trees through to Monte Carlo simulation with variance reduction. All pricing models are implemented from scratch in C++ with no external numerical libraries.

---

## Assignments

### HW1 — Binomial Option Pricing (`Bin_Model_HW1/`)

Fundamental binomial tree model for European option pricing.

- Risk-neutral probability calculation
- Stock price lattice: `S(n,i) = S₀ × Uⁱ × D^(n−i)`
- Cox-Ross-Rubinstein (CRR) European call pricing (numerical and analytical)

---

### HW2 — Binomial Lattice & Exotic Options (`Bin_Lattice_HW2/`)

Extended binomial lattice with American and barrier options.

- Template-based `BinLattice<T>` for flexible node storage
- American options priced via the Snell envelope (dynamic programming)
- Barrier options: Knock-Out (KO) and Knock-In (KI)
- Digital (double) options
- Delta hedging: price, delta, and cash-position lattices

---

### HW3 — Black-Scholes & Path-Dependent Options (`BS_Model_HW3/`)

Monte Carlo simulation under the Black-Scholes framework.

- Geometric Brownian Motion (GBM) sample path generation
- European call and put pricing via simulation
- Arithmetic Asian call option pricing

---

### HW4 — Interest Rate Models (`Models_HW4/`)

Stochastic models extended to interest rates.

- **Vasicek model**: `dr = α(β − r)dt + σdW` (mean-reverting SDE)
- **Hull-White model**: extended Vasicek with time-dependent parameters
- Monte Carlo sample path generation and file output for all models

---

### HW5 — Variance Reduction & Advanced Options (`More_Options_and_Models_HW5/`)

Reducing Monte Carlo estimation error using control variates.

- Geometric Asian call — closed-form pricing used as a control variate
- Arithmetic Asian call — priced with direct MC and variance-reduced MC
- Barrier call option (knock-out)
- Side-by-side comparison of MC error across methods

---

## Topics Covered

| Area | Concepts |
|---|---|
| Binomial models | Risk-neutral pricing, CRR, recombining lattices |
| Black-Scholes | GBM, European option formula, Monte Carlo |
| Exotic options | Asian (arithmetic/geometric), barrier (KO/KI), digital |
| American options | Early exercise, Snell envelope, backward induction |
| Interest rate models | Vasicek, Hull-White, SDE discretisation |
| Variance reduction | Control variates, MC error estimation |
| Hedging | Delta, cash position, replicating portfolio |

---

## Build

The project is configured for **Visual Studio on Windows** (`.sln` / `.vcxproj` files included). Open `finEng_repo.sln` in Visual Studio and build the desired homework project.

**Requirements:** C++11 or later, no external dependencies.

---

## Parameters Used in Examples

| Symbol | Meaning | Typical value |
|---|---|---|
| S₀ | Initial stock price | 100.0 |
| K | Strike price | 100.0 |
| r | Risk-free rate | 0.03 |
| σ | Volatility | 0.20 |
| T | Time to maturity (years) | 1.0 |
| N | Simulation steps / paths | 300 – 30 000 |

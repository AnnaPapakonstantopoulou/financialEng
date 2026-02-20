#pragma once
#ifndef BinLattice02
#define BinLattice02
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;


template<typename Type>
class BinLattice {
private:
    int N;
    vector<vector<Type>> lattice;

public:
    void SetN(int N_) {
        N = N_;
        lattice.resize(N + 1);
        for (int n = 0; n <= N; n++)
            lattice[n].resize(n + 1);
    }

    void SetNode(int n, int i, Type x) {
        lattice[n][i] = x;
    }

    Type GetNode(int n, int i) {
        return lattice[n][i];
    }

    void Display() {
        for (int n = 0; n <= N; n++)
        {
            for (int i = 0; i <= n; i++)
                cout << setw(7) << GetNode(n, i);
            cout << endl;
        }
        cout << endl;
    }




};


#endif

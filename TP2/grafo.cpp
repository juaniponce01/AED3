#include "grafo.h"

#include <utility>

Grafo::Grafo(const string& test_path) {
    // TODO
};

Grafo::Grafo(int n, int m, vector<pair<int, int>> aristas) {
    n_ = n;
    m_ = m;
    aristas_ = std::move(aristas);
    la_ = vector<vector<int>>(n);
    for (auto & arista : aristas_) {
        la_[arista.first-1].push_back(arista.second);
    }
    ma_ = vector<vector<int>>(n, vector<int>(n, 0));
    for (auto & arista : aristas_) {
        ma_[arista.first-1][arista.second-1] = 1;
    }
};

Grafo::~Grafo() {
    // TODO
};

int Grafo::n() const {
    return n_;
};

int Grafo::m() const {
    return m_;
};

vector<vector<int>>& Grafo::ma() {
    return ma_;
};

vector<int> Grafo::vecinos(int v) {
    return la_[v-1];
};

unsigned int Grafo::grado(int v) {
    return la_[v-1].size();
};



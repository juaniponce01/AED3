#include <stack>
#include "grafo.h"

Grafo::Grafo(const string& test_path) {
    // TODO
};

Grafo::Grafo(int n, int m, vector<pair<int, int>> aristas) {
    n_ = n;
    m_ = m;
    aristas_ = std::move(aristas);
    la_ = vector<set<int>>(n);
    for (auto & arista : aristas_) {
        la_[arista.first-1].insert(arista.second);
        la_[arista.second-1].insert(arista.first);
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

vector<set<int>>& Grafo::la() {
    return la_;
};

set<int> Grafo::vecinos(int v) {
    return la_[v-1];
};

unsigned int Grafo::grado(int v) {
    return la_[v-1].size();
};

//bool Grafo::perteneceACicloAux(int u, int v, vector<bool> visitados, int anterior) {
//    if (u == v) {
//        return true;
//    }
//    if (visitados[u-1]) {
//        return false;
//    }
//    visitados[u-1] = true;
//    for (auto & w : vecinos(u)){
//        if (w == anterior) continue;
//        if (perteneceACicloAux(w, v, visitados, u)){
//            return true;
//        }
//    }
//
//    return false;
//};
//
//bool Grafo::perteneceACiclo(int v) {
//    vector<bool> visitados(n_, false);
//    for (auto & u : vecinos(v)){
//        if (perteneceACicloAux(u, v, visitados, v)){
//            return true;
//        }
//    }
//    return false;
//};

bool Grafo::esPuente(int u, int v) {
vector<bool> visitados(n_, false);
    visitados[u-1] = true;
    stack<int> pila;
    pila.push(u);
    while (!pila.empty()) {
        int w = pila.top();
        pila.pop();
        for (auto & x : vecinos(w)) {
            if (x == v) {
                return false;
            }
            if (!visitados[x-1]) {
                visitados[x-1] = true;
                pila.push(x);
            }
        }
    }
    return true;
}

vector<int> Grafo::cantidadDeVerticesPorCiclo() {
    vector<int> res;
    vector<bool> visitados(n_, false);
    vector<int> cicloAlQuePertenece(n_, 0);
    dfs(1, visitados, cicloAlQuePertenece, 1);

    int max = 0;
    for (auto & i : cicloAlQuePertenece) {
        if (i > max) {
            max = i;
        }
    }
    res.resize(max);
    for (int i = 0; i < n_; ++i) {
        res[cicloAlQuePertenece[i]-1]++;
    }
    return res;
};

//bool Grafo::pertenecenAlMismoCiclo(int u, int v) {
//    vector<bool> visitados(n_, false);
//    return perteneceACicloAux(u, v, visitados, v);
//};

void Grafo::dfs(int v, vector<bool>& visitados, vector<int>& num_ciclo, int next) {
    visitados[v-1] = true;
    num_ciclo[v-1] = next;
    for (auto & u : vecinos(v)) {
        if (!visitados[u-1]) {
            if (esPuente(v, u)) {
                num_ciclo[u-1] = ++next;
            }
            dfs(u, visitados, num_ciclo, next);
        }
    }
};

ArbolDFS::ArbolDFS(int r, Grafo G): raiz_(r), g_(G), h_(0), n_(G.n()), pred_(vector<int>(n_)), orden_(vector<int>(n_)), cubren_(vector<int>(n_)) {
    int next = 1;
    pred_[raiz_-1] = 0;
    stack<int> lista;
    lista.push(raiz_);
    orden_[raiz_-1] = next;
    while (!lista.empty()) {
        int v = lista.top();
        lista.pop();
        for (auto & u : g_.vecinos(v)) {
            if (pred_[u-1] == 0) {
                pred_[u-1] = v;
                orden_[u-1] = ++next;
                lista.push(u);
            }
        }
    }
};






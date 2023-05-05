#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
int n, m;
vector<vector<int>> la;

double comb(int n, int k){
    if(k==0 || k==n){
        return 1;
    } else {
        return comb(n-1,k-1) + comb(n-1,k);
    }
};

void build_la(vector<pair<int, int>>& aristas){
    la = vector<vector<int>>(n);
    for (auto & arista : aristas){
        la[arista.first-1].push_back(arista.second);
        la[arista.second-1].push_back(arista.first);
    }
}

vector<int> vecinos(int v){
    return la[v-1];
};

bool perteneceACicloAux(int u, int v, vector<bool> visitados, int anterior) {
    if (u == v) {
        return true;
    }
    if (visitados[u-1]) {
        return false;
    }
    visitados[u-1] = true;
    for (auto & w : vecinos(u)){
        if (w == anterior) continue;
        if (perteneceACicloAux(w, v, visitados, u)){
            return true;
        }
    }

    return false;
};

bool perteneceACiclo(int v, vector<pair<int, int>>& aristas){
    vector<bool> visitados(n, false);
    for (auto & u : vecinos(v)){
        if (perteneceACicloAux(u, v, visitados, v)){
            return true;
        }
    }
    return false;
};

double probabilidadPerder(vector<pair<int, int>>& aristas){
    int cantVerticesEnCiclo = 0;
    for (int i = 1; i <= n; i++) {
        if (perteneceACiclo(i, aristas)){
            cantVerticesEnCiclo++;
        }
    }
    return 1 - comb(cantVerticesEnCiclo, 2) / comb(n, 2);
};


int main() {
    cin >> n >> m;
    vector<pair<int, int>> aristas;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        aristas.emplace_back(u, v);
    }
    build_la(aristas);
    cout << fixed << setprecision(5) << probabilidadPerder(aristas) << endl;

    return 0;
}
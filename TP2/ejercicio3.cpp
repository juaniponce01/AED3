#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

int C, n, R, W, U ,V;
float res_UTP, res_FO;
vector<pair<float, float>> result;
/*
 * c es Cantidad de Casos
 * N es la cantidad de oficinas
 * R es el radio maximo en el que puedo extender un cable UTP
 * W es la cantidad de modems
 * U es el precio de UTP
 * V es el precio del cable de fibra optica
 */
vector<vector<pair<int, int>>> aristas;
vector<pair<int, int>> oficinas;
vector<vector<pair<int, int>>> agm;
vector<tuple<int, int, int>> E;

struct DSU{
    void resize(int n){
        padre.resize(n+1);
        rank.resize(n+1);
        for(int v = 1; v <= n; v++) padre[v] = v;
    }

    int find(int v){
        if(v == padre[v]) return v;
        return padre[v] = find(padre[v]);
    }

    void unite(int u, int v){
        u = find(u), v = find(v);
        if(u == v) return;
        if(rank[u] < rank[v]) swap(u,v);
        padre[v] = padre[u];
        rank[u] = max(rank[u],rank[v]+1);
    }

    void clear(){
        padre.clear();
        rank.clear();
    }

    vector<int> padre;
    vector<int> rank;
};

DSU dsu;

//================= IDEA ================================
/*
 * 1) generar el grafo completo: tener e cuenta que cada arista tiene un peso que varia dependiendo de la distancia R
 * si la distancia es < R entonces usamos U, caso contrario usamos solo V
 * 2) hacer el agm con kruskal
 * 3) sacar las w aristas de mayor peso
 * 4) calcular el peso total de las w aristas
 */

float distancia(pair<float, float> a, pair<float, float> b){
    return sqrtf(powf(a.first - b.first, 2) + powf(a.second - b.second, 2));
}

bool puedoCable(pair<int, int> a, pair<int, int> b){
    return distancia(a, b) <= R;
}

void completarGrafo(){
    for (int i = 1; i <= n; i++){
        for (int j = i+1; j <= n; j++){
            if (puedoCable(oficinas[i], oficinas[j])){
                // usar UTP
                aristas[i].emplace_back(j, U);
                aristas[j].emplace_back(i, U);
                E.emplace_back(U, i, j);
            } else {
                // usar fibra optica
                aristas[i].emplace_back(j, V);
                aristas[j].emplace_back(i, V);
                E.emplace_back(V, i, j);
            }
        }
    }
}

void kruskal(){
    sort(E.begin(),E.end());
    int cant_aristas = 0;
    dsu.clear();
    dsu.resize(n);
    for(auto arista : E){
        int p = get<0>(arista); // Peso
        int v = get<1>(arista); // Vertice 1
        int u = get<2>(arista); // Vertice 2
        //si (u,v) es arista segura
        if(dsu.find(v) != dsu.find(u)){
            // agregar
            dsu.unite(u,v);
            agm[v].emplace_back(u, p);
            agm[u].emplace_back(v, p);
            cant_aristas++;
            if (p == U) {
                res_UTP += (float)p * distancia(oficinas[v], oficinas[u]);
            } else {
                res_FO += (float)V * distancia(oficinas[v], oficinas[u]);
            }
            if (cant_aristas == n-W) break;
        }
        if (cant_aristas == n-W) break;
    }
}

int main(){
    cin >> C;

    for (int i = 1; i <= C; i++){
        cin >> n >> R >> W >> U >> V;

        res_UTP = 0, res_FO = 0;
        aristas.clear();
        agm.clear();
        E.clear();
        oficinas.resize(n+1);
        aristas.resize(n+1);
        agm.resize(n+1);

        for (int j = 1; j <= n; j++){
            int x, y;
            cin >> x >> y;
            oficinas[j] = make_pair(x, y);
        }

        completarGrafo();

        kruskal();

        result.emplace_back(res_UTP, res_FO);

    }

    for (int i = 0; i < result.size(); i++){
        cout << "Caso #" << i+1 << ": " << fixed << setprecision(3) << result[i].first << " " << result[i].second << endl;
    }

    return 0;
};
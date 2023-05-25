#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

int C, n, R, W, U ,V;
double res_UTP, res_FO;
vector<pair<double, double>> result;
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
vector<tuple<double, int, int>> E;
vector<tuple<double, int, int>> agm;

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

double distancia(pair<int, int> a, pair<int, int> b){
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

bool puedoCable(pair<int, int> a, pair<int, int> b){
    return distancia(a, b) <= R;
}

void completarGrafo(){
    for (int i = 1; i <= n; i++){
        for (int j = i+1; j <= n; j++){
            double peso;
            double dist = distancia(oficinas[i], oficinas[j]);
            if (dist <= (double)R){ // usar UTP
                peso = (double)U * dist;
            } else { // usar fibra optica
                peso = (double)V * dist;
            }
            E.emplace_back(peso, i, j);
        }
    }
}

void kruskal(){
    sort(E.begin(),E.end());
    int cant_aristas = 0;
    dsu.clear();
    dsu.resize(n);
    for(auto arista : E){
        double p = get<0>(arista); // Peso
        int v = get<1>(arista); // Vertice 1
        int u = get<2>(arista); // Vertice 2
        //si (u,v) es arista segura
        if(dsu.find(v) != dsu.find(u)){
            // agregar
            dsu.unite(u,v);
            cant_aristas++;
            agm.push_back(arista);
            if (puedoCable(oficinas[v], oficinas[u])) {
                res_UTP += p;
            } else {
                res_FO += p;
            }
        }
        if (cant_aristas == n-W) break;
    }
}

int main(){
    cin >> C;

    for (int i = 1; i <= C; i++){
        cin >> n >> R >> W >> U >> V;

        res_UTP = 0, res_FO = 0;
        E.clear();
        agm.clear();
        oficinas.resize(n+1);

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
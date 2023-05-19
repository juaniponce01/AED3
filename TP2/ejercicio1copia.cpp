#include <iostream>
#include <vector>
#include <iomanip>

long long NO_LO_VI = 0;
long long EMPECE_A_VER = 1;
long long TERMINE_DE_VER = 2;

using namespace std;

long long n, m;
vector<vector<long long>> aristas;
vector<long long> estado; // estados de los nodos en el grafo
vector<bool> visitado; // visitados en el arbol
vector<long long> backConExtremoInferiorEn;
vector<long long> backConExtremoSuperiorEn;
vector<long long> pred;
vector<vector<long long>> treeEdges;
vector<long long> memo; // cantidad de backedges que cubren el nodo
vector<long long> cantidadNodosPorCC;

/*
 * 1) busco los puentes
 * 2) armo grafo sin puentes
 * 3) cuento cantidad de nodos por componente conexa
 * 4) calculo probabilidad de perder
 */


void dfs(long long v, long long p = -1) { // p es el padre de v
    estado[v] = EMPECE_A_VER;
    for (long long u : aristas[v]) {
        if (estado[u] == NO_LO_VI) {
            treeEdges[v].push_back(u);
            pred[u] = v;
            dfs(u, v);
        } else if (u != p && estado[u] == EMPECE_A_VER) { // backedge
            backConExtremoInferiorEn[v]++;
            backConExtremoSuperiorEn[u]++;
        }
    }
    estado[v] = TERMINE_DE_VER;
}

long long cubren(long long v, long long p = -1) { // cantidad de backedges que cubren la arista del nodo v y su padre p
    if (memo[v] != -1) return memo[v];
    long long res = 0;
    res += backConExtremoInferiorEn[v];
    res -= backConExtremoSuperiorEn[v];
    for (long long hijo : treeEdges[v]) {
        if (hijo != p) {
            res += cubren(hijo, v);
        }
    }
    memo[v] = res;
    return res;
}

void dfsCantidadNodos(long long v, long long p = -1, long long cc = 0) {
    /*
     * Calcula
    */
    visitado[v] = true;
    for (long long u : treeEdges[v]) {
        if (cubren(u, v) == 0) { // si (u, v) es puente
            cantidadNodosPorCC.push_back(1);
            dfsCantidadNodos(u, v, cc+1);
        } else {
            cantidadNodosPorCC[cc]++;
            dfsCantidadNodos(u, v, cc);
        }
    }
}

void cantidadNodosPorComponenteConexa() {
    /*
     * Calcula cantidad de nodos por componente conexa
    */
    for (long long i = 0; i < n; i++) {
        if (estado[i] == NO_LO_VI) {
            dfs(i);
        }
    }
    cantidadNodosPorCC.push_back(1);
    for (long long i = 0; i < n; i++) {
        if (visitado[i] == NO_LO_VI) {
            dfsCantidadNodos(i);
        }
    }
}

float probabilidadDePerder(){
    double posiblesGanadas = 0;
    for (long long & i : cantidadNodosPorCC) {
        posiblesGanadas += (double)(i*(i-1)) / 2;
    }
    double posiblesJugadas = (double)(n*(n-1)) / 2;
    return (float)(1 - (posiblesGanadas*1.0)/posiblesJugadas);
}


int main() {
    cin >> n >> m;

    aristas.resize(n+1);
    estado.resize(n+1, NO_LO_VI);
    visitado.resize(n+1, false);
    backConExtremoInferiorEn.resize(n+1, 0);
    backConExtremoSuperiorEn.resize(n+1, 0);
    pred.resize(n+1, -1);
    treeEdges.resize(n+1);
    memo.resize(n+1, -1);

    for (long long i = 0; i < m; i++) {
        long long u, v;
        cin >> u >> v;
        aristas[u].push_back(v);
        aristas[v].push_back(u);
    }

    cantidadNodosPorComponenteConexa();

    cout << fixed << setprecision(5) << probabilidadDePerder() << endl;

    return 0;
}
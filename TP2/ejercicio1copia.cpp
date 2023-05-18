#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

int NO_LO_VI = 0;
int EMPECE_A_VER = 1;
int TERMINE_DE_VER = 2;

using namespace std;

int n, m;
vector<vector<int>> aristas;
vector<int> estado;
vector<bool> visitado;
vector<int> backConExtremoInferiorEn;
vector<int> backConExtremoSuperiorEn;
vector<int> pred;
vector<vector<int>> treeEdges;
vector<int> memo; // cantidad de backedges que cubren el nodo

/*
 * 1) busco los puentes
 * 2) armo grafo sin puentes
 * 3) cuento cantidad de nodos por componente conexa
 * 4) calculo probabilidad de perder
 */


void dfs(int v, int p = -1) { // p es el padre de v
    estado[v] = EMPECE_A_VER;
    for (int u : aristas[v]) {
        if (estado[u] == NO_LO_VI) {
            treeEdges[v].push_back(u);
            pred[u] = v;
            dfs(u, v);
        } else if (u != p && estado[u] == EMPECE_A_VER) {
            backConExtremoInferiorEn[v]++;
            backConExtremoSuperiorEn[u]++;
        }
    }
    estado[v] = TERMINE_DE_VER;
}

int cubren(int v, int p = -1) { // cantidad de backedges que cubren la arista del nodo v y su padre p
    if (memo[v] != -1) return memo[v];
    int res = 0;
    res += backConExtremoInferiorEn[v];
    res -= backConExtremoSuperiorEn[v];
    for (int hijo : treeEdges[v]) {
        if (hijo != p) {
            res += cubren(hijo, v);
        }
    }
    memo[v] = res;
    return res;
}

int dfsCantidadNodos(int v, int p = -1, int res = 0) {
    visitado[v] = true;
    for (int u : aristas[v]) {
        if (u != p && !visitado[u]) {
            res = 1 + dfsCantidadNodos(u, v);
        }
    }
    return res;
}

void cantidadNodosPorComponenteConexa(vector<int>& res) {
    for (int i = 0; i < n; i++) {
        if (estado[i] == NO_LO_VI) {
            dfs(i);
        }
    }
    int cant_nodos = 0;
    for (int i = 0; i < n; i++) {

        // TODO: tengo que lograr que cuente los nodos que estan en una comp conexa
        // lo que pasa ahora es que existe una componente conexa que no contamos por no entrar al if

        if (cubren(i) == 0) {
            cant_nodos = 1 + dfsCantidadNodos(i, pred[i]);
            res.push_back(cant_nodos);
            cant_nodos = 0;
        }
    }
}

double probabilidadDePerder(){
    vector<int> nodosEnCC;
    cantidadNodosPorComponenteConexa(nodosEnCC);
    double posiblesGanadas = 0;
    for (int & i : nodosEnCC) {
        posiblesGanadas += (double)(i*(i-1)) / 2;
    }
    double posiblesJugadas = (double)(n*(n-1)) / 2;
    return 1 - posiblesGanadas/posiblesJugadas;
}


int main() {
    cin >> n >> m;

    aristas.resize(n);
    estado.resize(n, NO_LO_VI);
    visitado.resize(n, false);
    backConExtremoInferiorEn.resize(n, 0);
    backConExtremoSuperiorEn.resize(n, 0);
    pred.resize(n, -1);
    treeEdges.resize(n);
    memo.resize(n, -1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        aristas.at(u-1).push_back(v);
    }

    cout << fixed << setprecision(5) << probabilidadDePerder() << endl;

    return 0;
}
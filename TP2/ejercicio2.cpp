#include <iostream>
#include <vector>
#include <iomanip>
#include <stack>
#include <algorithm>

long long NO_LO_VI = 0;
long long EMPECE_A_VER = 1;
long long TERMINE_DE_VER = 2;

using namespace std;

//================= IDEA ================================
/*
 * 1) encontrar todos los componentes fuertemente conexos
 * 2) armar el grafo de cfcs
 * 3) ver el menor vertice de los cfcs son grado de salida 0
 */

stack<long long> S;
long long n, m; //Cant piezas, m cant de pares de caida
vector<vector<long long>> aristas;
vector<vector<long long>> aristasT;
vector<long long> estado;
vector<long long> pred;
vector<vector<long long>> treeEdges;
vector<vector<long long>> cfcs;
vector<bool> gradoINcero;
vector<long long> minimos;
long long F = 0;


void dfs(long long v, long long p = -1) { // p es el padre de v
    estado[v] = EMPECE_A_VER;
    for (long long u : aristas[v]) {
        if (estado[u] == NO_LO_VI) {
            treeEdges[v].push_back(u);
            pred[u] = v;
            dfs(u, v);
        }
    }
    S.push(v);
    estado[v] = TERMINE_DE_VER;
}

void dfsCFCs(long long v, long long p = -1) { // p es el padre de v
    // Construimos cfcs el cual representa las componentes fuertemente conexas
    estado[v] = EMPECE_A_VER;
    for (long long u : aristasT[v]) {
        if (estado[u] == NO_LO_VI) {
            if (u < minimos[F]) minimos[F] = u;
            dfsCFCs(u, v);
        } else if (find(cfcs[F].begin(), cfcs[F].end(), u) == cfcs[F].end() && estado[u] == TERMINE_DE_VER){
            gradoINcero[F] = false;
        }
    }
    cfcs[F].push_back(v);
    estado[v] = TERMINE_DE_VER;
}


int main(){
    cin >> n >> m;
    aristas.resize(n+1);
    aristasT.resize(n+1);
    estado.resize(n+1);
    pred.resize(n+1);
    treeEdges.resize(n+1);

    for (long long i = 0; i < m; i++) {
        long long u, v;
        cin >> u >> v;
        // Agrego los valores a aristas y a su version traspuesta
        aristas[u].push_back(v);
        aristasT[v].push_back(u);
    }

    //Hago DFS
    for (long long i = 1; i <= n; i++) {
        if (estado[i] == NO_LO_VI) {
            dfs(i);
        }
    }

    //Reseteo estado
    estado.clear();
    estado.resize(n+1, NO_LO_VI);

    //vacio el stack, haciendo dfsCFCs por los nodos que no visite
    while (!S.empty()) {
        long long v = S.top();
        S.pop();
        if (estado[v] == NO_LO_VI) {
            cfcs.emplace_back();
            minimos.push_back(v);
            gradoINcero.push_back(true);
            dfsCFCs(v);
            F++;
        }
    }

    vector<long long> result;

    for (long long i = F-1; i >= 0; i--) {
        if (gradoINcero[i]) {
            result.push_back(minimos[i]);
        }
    }

//    sort(result.begin(), result.end());

    //Imprimir tamaño de algún conjunto optimo
    cout << result.size() << endl;

    //Imprimir menor conjunto optimo
    for (long long i : result){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

/*No borrar
⢀⡴⠑⡄⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠸⡇⠀⠿⡀⠀⠀⠀⣀⡴⢿⣿⣿⣿⣿⣿⣿⣿⣷⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠑⢄⣠⠾⠁⣀⣄⡈⠙⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢀⡀⠁⠀⠀⠈⠙⠛⠂⠈⣿⣿⣿⣿⣿⠿⡿⢿⣆⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⢀⡾⣁⣀⠀⠴⠂⠙⣗⡀⠀⢻⣿⣿⠭⢤⣴⣦⣤⣹⠀⠀⠀⢀⢴⣶⣆
⠀⠀⢀⣾⣿⣿⣿⣷⣮⣽⣾⣿⣥⣴⣿⣿⡿⢂⠔⢚⡿⢿⣿⣦⣴⣾⠁⠸⣼⡿
⠀⢀⡞⠁⠙⠻⠿⠟⠉⠀⠛⢹⣿⣿⣿⣿⣿⣌⢤⣼⣿⣾⣿⡟⠉⠀⠀⠀⠀⠀
⠀⣾⣷⣶⠇⠀⠀⣤⣄⣀⡀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀
⠀⠉⠈⠉⠀⠀⢦⡈⢻⣿⣿⣿⣶⣶⣶⣶⣤⣽⡹⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠉⠲⣽⡻⢿⣿⣿⣿⣿⣿⣿⣷⣜⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣷⣶⣮⣭⣽⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣀⣀⣈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠻⠿⠿⠿⠿⠛⠉
 */
#include "grafo.h"
#include <iomanip>



double comb(int n, int k){
    if(k==0 || k==n){
        return 1;
    } else {
        return comb(n-1,k-1) + comb(n-1,k);
    }
}

double probabilidadPerder(Grafo G){
    int cantVerticesEnCiclo = 0;
    for (int i = 1; i <= G.n(); i++) {
        if (G.perteneceACiclo(i)) {
            cantVerticesEnCiclo++;
        }
    }
    return 1 - comb(cantVerticesEnCiclo, 2) / comb(G.n(), 2);
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> aristas;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        aristas.push_back(make_pair(u, v));
    }

    Grafo grafo(n, m, aristas);
    
    cout << fixed << setprecision(5) << probabilidadPerder(grafo) << endl;

    return 0;
}
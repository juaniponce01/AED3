#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Calle {
    int d_i;
    int c_i;
    int l_i;
};
int max_int = int(pow(10, 8));
vector<vector<pair<int, int>>> calles;
vector<vector<pair<int, int>>> callesT;
vector<Calle> callesBidireccionales;
vector<int> Ds, Dt;
vector<bool> visitado;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;
vector<int> res;
int n, m, k, s, t;

void initialize_single_source(vector<int>& D, int source) {
    D.clear();
    visitado.clear();
    D.resize(n+1, max_int);
    visitado.resize(n + 1, false);

    Q.emplace(0, source);
    D[source] = 0;
}

void relax(int u, int v, int w, vector<int>& D) {
    if (D[v] > D[u] + w) {
        D[v] = D[u] + w;
    }
}

void Dijkstra(vector<vector<pair<int, int>>>& G, vector<int>& D, int source) {
    initialize_single_source(D, source);

    while (!Q.empty()) {
        int u = Q.top().second;
        Q.pop();
        if (visitado[u]) continue;
        visitado[u] = true;

        for (auto p : G[u]) {
            int v = p.first;
            int w = p.second;
            relax(u, v, w, D);
            Q.emplace(D[v], v);
        }
    }
}

int main() {
    int c;
    int d_i, c_i, l_i;
    int mejorDist;
    cin >> c;

    for (int it = 0; it < c; it++) {
        cin >> n >> m >> k >> s >> t;
        calles.clear();
        callesT.clear();
        callesBidireccionales.clear();
        calles.resize(n + 1);
        callesT.resize(n + 1);

        for (int i = 0; i < m; i++) {
            cin >> d_i >> c_i >> l_i;
            calles[d_i].emplace_back(c_i, l_i);
            callesT[c_i].emplace_back(d_i, l_i);
        }

        for (int j = 0; j < k; j++) {
            cin >> d_i >> c_i >> l_i;
            callesBidireccionales.push_back({ d_i, c_i, l_i });
        }

        Dijkstra(calles, Ds, s);
        Dijkstra(callesT, Dt, t);

        mejorDist = Ds[t];

        for (auto& a : callesBidireccionales) {
            int u = a.d_i;
            int v = a.c_i;
            int w = a.l_i;

            if (Ds[u] + w + Dt[v] < mejorDist) {
                mejorDist = Ds[u] + w + Dt[v];
            }
            if (Ds[v] + w + Dt[u] < mejorDist) {
                mejorDist = Ds[v] + w + Dt[u];
            }
        }

        if (mejorDist >= max_int) {
            res.push_back(-1);
        }
        else {
            res.push_back(mejorDist);
        }
    }

    for (int r : res) {
        cout << r << endl;
    }

    return 0;
}
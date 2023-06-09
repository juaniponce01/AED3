#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Calle {
    long long d_i;
    long long c_i;
    long long l_i;
};

vector<vector<pair<long long, long long>>> calles;
vector<vector<pair<long long, long long>>> callesT;
vector<Calle> callesBidireccionales;
vector<long long> Ds, Dt, pred_s, pred_t;
vector<bool> visitado;
priority_queue<long long> Q;
vector<long long> res;
long long n, m, k, s, t;

void initialize_single_source(vector<long long>& D, vector<long long>& pred, long long source) {
    D.resize(n + 1);
    pred.resize(n + 1);
    visitado.resize(n + 1);

    for (long long i = 1; i <= n; i++) {
        D[i] = INT_MAX;
        pred[i] = -1;
        visitado[i] = false;
    }
    Q.push(source);
    D[source] = 0;
}

void relax(long long u, long long v, long long w, vector<long long>& D, vector<long long>& pred) {
    if (D[v] > D[u] + w) {
        D[v] = D[u] + w;
        pred[v] = u;
    }
}

void Dijkstra(vector<vector<pair<long long, long long>>>& G, vector<long long>& D, vector<long long>& pred, long long source) {
    initialize_single_source(D, pred, source);

    while (!Q.empty()) {
        long long u = Q.top();
        Q.pop();
        if (visitado[u]) {
            continue;
        }
        visitado[u] = true;

        for (auto p : G[u]) {
            long long v = p.first;
            long long w = p.second;
            relax(u, v, w, D, pred);
            if (!visitado[v]) {
                Q.push(v);
            }
        }
    }
}

int main() {
    long long c;
    long long d_i, c_i, l_i;
    long long mejorDist;
    cin >> c;

    for (long long it = 0; it < c; it++) {
        cin >> n >> m >> k >> s >> t;
        calles.clear();
        callesT.clear();
        callesBidireccionales.clear();
        calles.resize(n + 1);
        callesT.resize(n + 1);

        for (long long i = 0; i < m; i++) {
            cin >> d_i >> c_i >> l_i;
            calles[d_i].emplace_back(c_i, l_i);
            callesT[c_i].emplace_back(d_i, l_i);
        }

        for (long long j = 0; j < k; j++) {
            cin >> d_i >> c_i >> l_i;
            callesBidireccionales.push_back({ d_i, c_i, l_i });
        }

        Dijkstra(calles, Ds, pred_s, s);
        Dijkstra(callesT, Dt, pred_t, t);

        mejorDist = Ds[t];

        for (auto& a : callesBidireccionales) {
            long long u = a.d_i;
            long long v = a.c_i;
            long long w = a.l_i;

            if (Ds[u] + w + Dt[v] < mejorDist) {
                mejorDist = Ds[u] + w + Dt[v];
            }
            if (Ds[v] + w + Dt[u] < mejorDist) {
                mejorDist = Ds[v] + w + Dt[u];
            }
        }

        if (mejorDist == Ds[t]) {
            res.push_back(-1);
        }
        else {
            res.push_back(mejorDist);
        }
    }

    for (long long r : res) {
        cout << r << endl;
    }

    return 0;
}

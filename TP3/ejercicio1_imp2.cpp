#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Calle {
    long long d_i;
    long long c_i;
    long long l_i;
};
long long maxx = 188888888;
vector<vector<pair<long long, long long>>> calles;
vector<long long> Ds;
vector<bool> visitado;
priority_queue<pair<long long, long long>,vector<pair<long long, long long>>,greater<pair<long long, long long>>> Q;
vector<long long> res;
long long n, m, k, s, t;

void initialize_single_source(vector<long long>& D, long long source) {
    D.clear();
    D.resize(n*2+1, maxx);

    visitado.clear();
    visitado.resize(n*2+1, false);

    Q.emplace(0, source);
    D[source] = 0;
}

void relax(long long u, long long v, long long w, vector<long long>& D) {
    if (D[v] > D[u] + w) {
        D[v] = D[u] + w;
    }
}

void Dijkstra(vector<vector<pair<long long, long long>>>& G, vector<long long>& D, long long source) {
    initialize_single_source(D, source);

    while (!Q.empty()) {
        pair<long long, long long> u = Q.top();
        Q.pop();
        if (visitado[u.second]) {continue;}
        visitado[u.second] = true;

        for (auto p : G[u.second]) {
            long long v = p.first;
            long long w = p.second;
            relax(u.second, v, w, D);
            if (!visitado[v]) {
                Q.emplace(w, v);
            }
        }
    }
}

int main() {
    long long c;
    long long d_i, c_i, l_i;
    cin >> c;

    for (long long it = 0; it < c; it++) {
        cin >> n >> m >> k >> s >> t;
        calles.clear();
        calles.resize(n*2+1);

        for (long long i = 0; i < m; i++) {
            cin >> d_i >> c_i >> l_i;
            calles[d_i].emplace_back(c_i, l_i); //Creo la calle en G
            calles[d_i+n].emplace_back(c_i+n, l_i); //Creo la calle en G'
        }

        for (long long j = 0; j < k; j++) {
            cin >> d_i >> c_i >> l_i;
            calles[d_i].emplace_back(c_i+n, l_i); //Creo la avenida entre G y G'
            calles[c_i].emplace_back(d_i+n, l_i); //Creo la avenida entre G y G'
        }

        Dijkstra(calles, Ds, s);

        if (Ds[t+n] >= maxx) {
            res.push_back(-1);
        }
        else {
            res.push_back(Ds[t+n]);
        }
    }

    for (long long r : res) {
        cout << r << endl;
    }

    return 0;
}
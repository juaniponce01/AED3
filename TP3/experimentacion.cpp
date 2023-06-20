#include <bits/stdc++.h>

using namespace std;

struct Calle {
    int d_i;
    int c_i;
    int l_i;
};
int max_int = int(pow(10, 8));
vector<vector<pair<int, int>>> calles;
vector<Calle> callesBidireccionales;
vector<int> Ds, Dt;
vector<bool> visitado;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;
vector<int> res;
int n, m, k, s, t;
vector<vector<int>> graphT;

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


// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(vector<int> & D)
{
    // Initialize min value
    int min = max_int, min_index;

    for (int v = 1; v <= n; v++)
        if (!visitado[v] && D[v] <= min)
            min = D[v], min_index = v;

    return min_index;
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void DijkstraV2(vector<vector<int>>& g, vector<int>& D, int source) {
    initialize_single_source(D, source);

    // Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minDistance(D);

        // Mark the picked vertex as processed
        visitado[u] = true;

        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < n; v++)

            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!visitado[v] && g[u][v]
                && D[u] != max_int
                && D[u] + g[u][v] < D[v])
                D[v] = D[u] + g[u][v];
    }
}

int main() {
    ofstream file;
    file.open("exp3nano.csv");
    file << "n " << "nlogn "  << "n2" << endl;
    auto start = chrono::steady_clock::now();
    auto end = chrono::steady_clock::now();
    unsigned t1, t2;
    int c;
    int d_i, c_i, l_i;
    cin >> c;

    for (int it = 0; it < c; it++) {
        cin >> n >> m >> k >> s >> t;
        file << n << " ";
        calles.clear();
        graphT.clear();
        callesBidireccionales.clear();
        calles.resize(n + 1);
        graphT.resize(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++) {
            cin >> d_i >> c_i >> l_i;
            calles[d_i].emplace_back(c_i, l_i);
            graphT[c_i][d_i] = l_i;
        }

        for (int j = 0; j < k; j++) {
            cin >> d_i >> c_i >> l_i;
            callesBidireccionales.push_back({ d_i, c_i, l_i });
        }

        start = chrono::steady_clock::now();
        t1 = clock();
        Dijkstra(calles, Ds, s);
        end = chrono::steady_clock::now();
        t2 = clock();
        file << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ";
//        file << (double)(t2 - t1) / CLOCKS_PER_SEC << " ";

        start = chrono::steady_clock::now();
        t1 = clock();
        DijkstraV2(graphT, Dt, t);
        end = chrono::steady_clock::now();
        t2 = clock();
        file << chrono::duration_cast<chrono::nanoseconds>(end - start).count();
//        file << (double)(t2 - t1) / CLOCKS_PER_SEC;

        file << endl;
    }

    file.close();

    cout << "Listo!" << endl;
    return 0;
}
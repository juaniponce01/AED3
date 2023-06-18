#include <vector>
#include <tuple>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

// 0 0 para terminar
// m lineas con dos numeros i y j, indicando que los estudiantes i y j son amigos
// una linea con n numeros, donde el i-esimo numero es el algoritmo favorito del estudiante i, siendo 1 para Prim y 0 para Kruskal
// n, m cantidad de estudiantes y aristas
//votar a favor de su algoritmo favorito pero genera tension = disconformidad
//votar en contra de su algoritmo favorito = disconformidad

//https://cp-algorithms.com/graph/edmonds_karp.html#implementation

vector<int> estudiantes;

int n, m;

vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.emplace(s, INT_MAX);

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.emplace(next, new_flow);
            }
        }
    }
    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n+2);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}
int main(){
    int u, v;
    int S = 0, T;
    vector<int> res;

    while (true){
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0){break;}
        T = n+1;
        adj.clear();
        capacity.clear();
        adj.resize(n+2);
        capacity.resize(n+2, vector<int>(n+2, 0));

        estudiantes.resize(n+2);

        for (int i = 1; i <= n; i++){
            scanf("%d", &estudiantes[i]);
            if (estudiantes[i] == 1){
                adj[S].push_back(i);
                capacity[S][i] = 1;
            }else{
                adj[i].push_back(T);
                capacity[i][T] = 1;
            }
        }

        for (int i = 0; i < m; i++){
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
            capacity[u][v] = 1;
            capacity[v][u] = 1;
        }
        res.push_back(maxflow(S, T));
    }

    for(int & r : res){
        printf("%d\n", r);
    }
    return 0;
}
#include <vector>
#include <tuple>
#include <iostream>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<tuple<int, int>>> aristas; // aristas[i] = vector de tuplas (j, capacidad)
vector<int> estudiantes;

int n, m;

//votar en contra de su algoritmo favorito = disconformidad
//votar a favor de su algoritmo favorito pero genera tension = disconformidad
// n, m cantidad de estudiantes y aristas
// una linea con n numeros, donde el i-esimo numero es el algoritmo favorito del estudiante i, siendo 1 para Prim y 0 para Kruskal
// m lineas con dos numeros i y j, indicando que los estudiantes i y j son amigos
// 0 0 para terminar

//https://cp-algorithms.com/graph/edmonds_karp.html#implementation
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INT_MAX});

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
                q.push({next, new_flow});
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
    int S = n-2;
    int T = n-1;
    vector<int> res;

    while (true){
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0){break;}

        estudiantes.resize(n+1);
        aristas.resize(n+1+2); //aristas[S] = s; aristas[S] = t;

        capacity.resize(vector<int>(n+2, 0));

        for (int i = 1; i <= n; i++){
            scanf("%d", &estudiantes[i]);
            if (estudiantes[i] == 1){
                aristas[S].emplace_back(i, 1);
                aristas[i].emplace_back(S, 1);
                adj[S].push_back(i);
            }else{
                aristas[i].emplace_back(T, 1);
                aristas[T].emplace_back(i, 1);
                adj[i].push_back(T);
            }
        }

        for (int i = 0; i < m; i++){
            scanf("%d %d", &u, &v);
            aristas[u].emplace_back(v, 1);
            aristas[v].emplace_back(u, 1);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        n +=2;
        res.push_back(maxflow(S, T));
    }

    for(int i = 0; i < res.size(); i++){
        printf("%d\n", res[i]);
    }
    return 0;
}
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void BFS(vector<vector<int>>& adj, int start, int vertices) {
    vector<bool> visited(vertices, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < vertices; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    int vertices, edges, u, v, src;
    cin >> vertices >> edges;
    vector<vector<int>> adj(vertices, vector<int>(vertices, 0));

    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1; // Undirected graph
    }

    cin >> src;
    BFS(adj, src, vertices);
    return 0;
}

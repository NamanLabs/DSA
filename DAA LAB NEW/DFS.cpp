#include<iostream>
#include<vector>
using namespace std;

void DFS(vector<vector<int>>& adj, int node, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < adj.size(); i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            DFS(adj, i, visited);
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
    vector<bool> visited(vertices, false);
    DFS(adj, src, visited);
    return 0;
}

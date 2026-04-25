#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void primMST(int n, vector<vector<int>>& graph) {
    vector<int> parent(n, -1);
    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);
    key[0] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        for (int v = 0; v < n; v++) {
            if (!inMST[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        inMST[u] = true;
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    cout << "Enter the edges (u v weight):\n";
    for (int i = 0; i < e; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u][v] = weight;
        graph[v][u] = weight;  // for undirected graph
    }

    primMST(n, graph);
    return 0;
}

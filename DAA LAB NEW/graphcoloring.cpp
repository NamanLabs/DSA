#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& color, int c, int V) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(vector<vector<int>>& graph, vector<int>& color, int V, int m, int v) {
    if (v == V) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c, V)) {
            color[v] = c;
            if (graphColoringUtil(graph, color, V, m, v + 1)) {
                return true;
            }
            color[v] = 0;
        }
    }

    return false;
}

bool graphColoring(vector<vector<int>>& graph, int V, int m) {
    vector<int> color(V, 0);
    if (!graphColoringUtil(graph, color, V, m, 0)) {
        return false;
    }
    cout << "Solution exists: Following are the assigned colors:" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " ---> Color " << color[i] << endl;
    }
    return true;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> graph(V, vector<int>(V, 0));

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }

    int m;
    cout << "Enter the number of colors: ";
    cin >> m;

    if (!graphColoring(graph, V, m)) {
        cout << "Solution does not exist\n";
    }

    return 0;
}

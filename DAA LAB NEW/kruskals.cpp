#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int findParent(int u, vector<int>& parent) {
    if (parent[u] != u) {
        parent[u] = findParent(parent[u], parent);  // Path compression
    }
    return parent[u];
}

void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);

    if (rootU != rootV) {
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

void kruskalMST(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());

    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;

    vector<Edge> mstEdges;
    for (Edge& e : edges) {
        int u = e.u;
        int v = e.v;

        if (findParent(u, parent) != findParent(v, parent)) {
            mstEdges.push_back(e);
            unionSets(u, v, parent, rank);
        }
    }

    cout << "Edge \tWeight\n";
    for (Edge& e : mstEdges) {
        cout << e.u << " - " << e.v << " \t" << e.weight << endl;
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<Edge> edges;
    cout << "Enter the edges (u v weight):\n";
    for (int i = 0; i < e; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back({u, v, weight});
    }

    kruskalMST(n, edges);
    return 0;
}

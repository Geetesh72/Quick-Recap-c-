#include <bits/stdc++.h>
using namespace std;

/* 
ABOUT QUESTION:
What is a Bipartite Graph?
- A graph is called bipartite if its vertices can be divided into two disjoint sets such that no two adjacent vertices are in the same set.

Key Properties of Bipartite Graph:
1. A graph is bipartite if it can be colored using two colors such that no two adjacent nodes have the same color.
2. Only linear (tree-like) graphs are bipartite.
3. A cyclic graph with an even length is bipartite.
4. A cyclic graph with an odd length can never be bipartite.
*/

// Function to check if a graph is bipartite using BFS
bool check(int start, vector<vector<int>> &graph, vector<int> &color) {
    queue<int> q;
    q.push(start);
    color[start] = 0; // Assign the first color (e.g., 0) to the starting node

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // Traverse all adjacent nodes
        for (auto it : graph[node]) {
            // If the adjacent node is not colored, assign the opposite color
            if (color[it] == -1) {
                color[it] = !color[node];
                q.push(it);
            }
            // If the adjacent node has the same color as the current node, it's not bipartite
            else if (color[it] == color[node]) {
                return false;
            }
        }
    }
    return true;
}

// Function to check if the entire graph is bipartite
bool isBipartite(int n, vector<vector<int>> &graph) {
    vector<int> color(n, -1); // Initialize color array with -1 (uncolored)

    // Check all components of the graph
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            // If the component is not colored, check for bipartiteness
            if (!check(i, graph, color)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes (n) and edges (m): ";
    cin >> n >> m;

    vector<vector<int>> graph(n); // Adjacency list representation of the graph

    cout << "Enter the edges (u v for an edge between nodes u and v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Since the graph is undirected
    }

    if (isBipartite(n, graph)) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}

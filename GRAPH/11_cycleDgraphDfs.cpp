#include <bits/stdc++.h>
using namespace std;

/* 
ABOUT QUESTION:
We have to check if there is a cycle in a directed graph or not.

APPROACH:
- Use two arrays:
  1. `nodeVis` (Node Visited): Tracks whether a node has been visited at least once.
  2. `pathVis` (Path Visited): Tracks nodes that are currently in the recursive call stack.
- If during DFS traversal, we encounter a node that is already in the call stack (`pathVis`), it indicates a cycle.

COMPLEXITY:
- Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
- Space Complexity: O(V), due to recursion and the storage for visited arrays.
*/

// Function to detect a cycle in a directed graph using DFS
bool detectDfs(int node, vector<vector<int>> &graph, vector<int> &nodeVis, vector<int> &pathVis) {
    nodeVis[node] = 1;      // Mark the node as visited
    pathVis[node] = 1;      // Mark the node as part of the current path

    for (auto it : graph[node]) { // Traverse all neighbors of the node
        if (!nodeVis[it]) {       // If the neighbor is not visited
            if (detectDfs(it, graph, nodeVis, pathVis) == true) {
                return true;      // Cycle detected
            }
        } else if (pathVis[it] == 1) { // If the neighbor is already in the current path
            return true;          // Cycle detected
        }
    }

    pathVis[node] = 0;  // Remove the node from the current path before returning
    return false;       // No cycle detected
}

// Function to check if the entire graph has a cycle
bool isCyclic(int n, vector<vector<int>> &graph) {
    vector<int> nodeVis(n, 0); // Initialize node visited array
    vector<int> pathVis(n, 0); // Initialize path visited array

    // Check all components of the graph
    for (int i = 0; i < n; i++) {
        if (!nodeVis[i]) { // If the node has not been visited
            if (detectDfs(i, graph, nodeVis, pathVis)) {
                return true; // Cycle detected
            }
        }
    }

    return false; // No cycle detected
}

int main() {
    int n, m;
    cout << "Enter the number of nodes (n) and edges (m): ";
    cin >> n >> m;

    vector<vector<int>> graph(n); // Adjacency list representation of the graph

    cout << "Enter the edges (u v for a directed edge from u to v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v); // Directed edge from u to v
    }

    if (isCyclic(n, graph)) {
        cout << "The graph contains a cycle." << endl;
    } else {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}

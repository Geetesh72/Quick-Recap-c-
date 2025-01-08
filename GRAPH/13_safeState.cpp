#include <bits/stdc++.h>
using namespace std;

/*
ABOUT QUESTION:
- The goal is to find all "safe nodes" in a directed graph.
- Safe nodes are those which are not part of any cycle and do not lead to a cycle.

IDEA:
1. A node is not safe if it is part of a cycle or leads to a cycle.
2. Use DFS to detect cycles and track safe nodes.
3. Maintain arrays:
   - `nVis` (nodeVis): To check if a node has been visited.
   - `pVis` (pathVis): To check if a node is part of the current DFS path.
   - `check`: To mark nodes as safe (1) or unsafe (0).
*/

// Helper function to detect cycles and determine safe nodes
bool detectCycle(int node, vector<vector<int>> &graph,
                 vector<int> &nVis, vector<int> &pVis, vector<int> &check) {
    nVis[node] = 1;
    pVis[node] = 1;
    check[node] = 0; // Assume the node is not safe initially

    for (auto it : graph[node]) {
        if (!nVis[it]) {
            if (detectCycle(it, graph, nVis, pVis, check)) {
                return true; // Cycle detected
            }
        } else if (pVis[it] == 1) {
            return true; // Cycle detected
        }
    }

    // If no cycle detected, mark the node as safe
    check[node] = 1;
    pVis[node] = 0; // Backtrack: remove the node from the current path
    return false;
}

// Function to return all safe nodes
vector<int> safeState(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> nVis(n, 0);   // Node visited
    vector<int> pVis(n, 0);   // Path visited
    vector<int> check(n, 0);  // Safe status (1 if safe, 0 if not)

    for (int i = 0; i < n; i++) {
        if (!nVis[i]) {
            detectCycle(i, graph, nVis, pVis, check);
        }
    }

    // Collect all safe nodes
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (check[i] == 1) {
            ans.push_back(i);
        }
    }
    return ans;
}

int main() {
    // Example usage
    int n, m;
    cout << "Enter the number of nodes (n) and edges (m): ";
    cin >> n >> m;

    vector<vector<int>> graph(n);
    cout << "Enter the edges (u v for a directed edge from u to v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    vector<int> safeNodes = safeState(graph);
    cout << "Safe nodes are:" << endl;
    for (auto node : safeNodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

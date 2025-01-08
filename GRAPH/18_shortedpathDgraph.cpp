#include <bits/stdc++.h>
using namespace std;

/*
Question Description:
Given a Directed Acyclic Graph (DAG) with `n` nodes and `m` edges, where each edge has a weight, find the shortest path from 
the source node (node 0) to all other nodes. If a node is not reachable from the source, assign `-1` as its distance.

Approach (Intuition):
1. Topological Sort:
   - For a DAG, use DFS to find a topological order of the nodes.
   - Topological order ensures that for every edge `u -> v`, `u` appears before `v`.
2. Shortest Path using Topological Order:
   - Initialize distances to infinity (`1e9`).
   - Process nodes in topological order and relax edges to calculate the shortest path.

Time Complexity:
1. Building the adjacency list: O(m), where m = number of edges.
2. Topological sort (DFS): O(n + m), where n = number of nodes.
3. Relaxing edges: O(n + m).
Total: O(n + m).

Space Complexity:
1. Adjacency list: O(n + m).
2. Visited array and stack: O(n).
3. Distance array: O(n).
Total: O(n + m).
*/

void topoSort(int node, vector<vector<pair<int, int>>> &adj, vector<int> &vis, stack<int> &st) {
    vis[node] = 1;
    for (auto iter : adj[node]) {
        int it = iter.first;
        if (!vis[it]) {
            topoSort(it, adj, vis, st);
        }
    }
    st.push(node);
}

vector<int> shortestPath(int n, int m, vector<vector<int>> &graph) {
    // Build the adjacency list
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u = graph[i][0];
        int v = graph[i][1];
        int wt = graph[i][2];
        adj[u].push_back({v, wt}); // Directed edge from u to v with weight wt
    }

    // Perform topological sort
    vector<int> vis(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            topoSort(i, adj, vis, st);
        }
    }

    // Initialize distances
    vector<int> dis(n, 1e9);
    dis[0] = 0; // Distance to the source node is 0

    // Process nodes in topological order
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (dis[node] != 1e9) { // Process only if the node is reachable
            for (auto iter : adj[node]) {
                int v = iter.first;
                int wt = iter.second;
                if (dis[node] + wt < dis[v]) {
                    dis[v] = dis[node] + wt;
                }
            }
        }
    }

    // Replace unreachable nodes' distance with -1
    for (int i = 0; i < n; i++) {
        if (dis[i] == 1e9) {
            dis[i] = -1;
        }
    }
    return dis;
}

int main() {
    // Example usage
    int n = 6; // Number of nodes
    int m = 7; // Number of edges
    vector<vector<int>> graph = {
        {0, 1, 2}, {0, 4, 1}, {1, 2, 3}, {4, 2, 2}, {4, 5, 4}, {2, 3, 6}, {5, 3, 1}};

    // Call the shortestPath function
    vector<int> result = shortestPath(n, m, graph);

    // Print the shortest distances
    cout << "Shortest distances from node 0: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

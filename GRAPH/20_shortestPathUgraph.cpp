#include <bits/stdc++.h>
using namespace std;

/*
Question Description:
Given an undirected graph with `n` nodes and `m` edges, find the shortest distance from a source node (`src`) 
to all other nodes using the Breadth-First Search (BFS) algorithm. If a node is not reachable, return `-1` for that node.

Approach (Intuition):
1. Use BFS to explore the graph starting from the source node.
   - In an undirected graph, each edge connects two nodes bi-directionally.
   - Initialize the distances of all nodes as `infinity` (1e9).
   - Set the distance of the source node to 0.
2. Process each node in the BFS queue, and update the distance of its neighbors.
3. If a node is unreachable from the source, its distance remains `infinity`, which we will convert to `-1` in the result.

Time Complexity:
1. Building the adjacency list: O(m), where m = number of edges.
2. BFS traversal: O(n + m), where n = number of nodes and m = number of edges.
   - Each node and edge is processed once.
Total: O(n + m).

Space Complexity:
1. Adjacency list: O(n + m).
2. Distance array: O(n).
3. Queue: O(n).
Total: O(n + m).
*/

vector<int> uShortestPath(vector<vector<int>> graph, int n, int m, int src) {
    // Build the adjacency list for the undirected graph
    vector<vector<int>> adjList(n);
    for (auto it : graph) {
        int u = it[0];
        int v = it[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // Since it's undirected, add both directions
    }

    // Initialize distance array with infinity
    vector<int> dis(n, 1e9);
    dis[src] = 0;  // Distance to the source node is 0

    // BFS initialization
    queue<int> q;
    q.push(src);

    // BFS loop
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto it : adjList[node]) {
            if (dis[node] + 1 < dis[it]) {  // Relax the edge
                dis[it] = dis[node] + 1;
                q.push(it);
            }
        }
    }

    // Replace unreachable nodes' distance with -1
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        if (dis[i] != 1e9) {
            ans[i] = dis[i];
        }
    }

    return ans;
}

int main() {
    // Example usage
    int n = 5; // Number of nodes
    int m = 6; // Number of edges
    vector<vector<int>> graph = {
        {0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 3}, {3, 4}
    };
    int src = 0; // Source node

    // Call the uShortestPath function
    vector<int> result = uShortestPath(graph, n, m, src);

    // Print the shortest distances from the source node
    cout << "Shortest distances from node " << src << ": ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

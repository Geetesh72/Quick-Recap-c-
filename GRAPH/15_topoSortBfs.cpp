#include<bits/stdc++.h>
using namespace std;

/* 
ABOUT QUESTION:
Topological Sorting:
- It is the linear ordering of vertices in a directed acyclic graph (DAG) such that for every directed edge u → v, vertex u comes before v in the ordering.

Kahn's Algorithm:
- This is a BFS-based algorithm for topological sorting.
- The idea is to iteratively remove nodes with an in-degree of 0 while reducing the in-degrees of their neighbors.

Steps:
1. Compute the in-degrees of all nodes.
2. Push nodes with in-degree 0 into a queue.
3. Process each node, add it to the result, and reduce the in-degrees of its neighbors.
4. If a neighbor's in-degree becomes 0, add it to the queue.
*/

// Function to perform topological sort using Kahn's Algorithm
vector<int> topoSortKahn(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> inDegree(n, 0);

    // Compute in-degrees of all nodes
    for (int i = 0; i < n; i++) {
        for (auto it : graph[i]) {
            inDegree[it]++;
        }
    }

    // Initialize a queue with nodes having in-degree 0
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans; // To store the topological order
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        // Reduce the in-degree of neighbors and add them to the queue if in-degree becomes 0
        for (auto it : graph[node]) {
            inDegree[it]--;
            if (inDegree[it] == 0) {
                q.push(it);
            }
        }
    }

    // If the number of nodes in the result is less than 'n', the graph has a cycle
    if (ans.size() < n) {
        cout << "The graph is not a DAG; topological sorting is not possible." << endl;
        return {};
    }

    return ans;
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

    vector<int> result = topoSortKahn(graph);

    if (!result.empty()) {
        cout << "Topological Sort Order: ";
        for (int node : result) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}

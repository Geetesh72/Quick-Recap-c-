#include <bits/stdc++.h>
using namespace std;

// Function to perform Kahn's Algorithm for Topological Sort
bool topoSort(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> iDeg(n, 0);

    // Calculate in-degrees of all nodes
    for (int i = 0; i < n; i++) {
        for (auto it : graph[i]) {
            iDeg[it]++;
        }
    }

    // Initialize the queue with nodes having in-degree 0
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (iDeg[i] == 0) {
            q.push(i);
        }
    }

    int processedNodes = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        processedNodes++;

        for (auto it : graph[node]) {
            iDeg[it]--;
            if (iDeg[it] == 0) {
                q.push(it);
            }
        }
    }

    // If processed nodes are less than the total nodes, there is a cycle
    return processedNodes != n;
}

// Function to detect a cycle in a directed graph
bool detectCycleDfs(vector<vector<int>>& graph) {
    return topoSort(graph);
}

int main() {
    int n, m;
    cout << "Enter the number of nodes (n) and edges (m): ";
    cin >> n >> m;

    vector<vector<int>> graph(n);
    cout << "Enter the edges (u -> v for directed edge from u to v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    if (detectCycleDfs(graph)) {
        cout << "The graph contains a cycle." << endl;
    } else {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}

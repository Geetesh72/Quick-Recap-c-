#include <bits/stdc++.h>
using namespace std;

/*
Question Description:
Given a directed graph, find all the "safe nodes". A node is considered "safe" if starting from that node will 
not lead to a cycle in the graph. 

Key Observations:
1. Reverse the graph:
   - In the original graph, nodes with no outgoing edges (out-degree 0) are safe nodes.
   - By reversing the graph, nodes with no incoming edges (in-degree 0) in the reversed graph can be processed as "safe nodes".
2. Use BFS (Kahn's Algorithm) to find all safe nodes:
   - Start with nodes that have in-degree 0 in the reversed graph.
   - Gradually reduce the in-degree of their neighbors and add them to the queue if their in-degree becomes 0.

Approach (Intuition):
- Reverse the graph so that we process dependencies in the opposite direction.
- Nodes with an in-degree of 0 in the reversed graph are safe nodes.
- Perform a topological sort using BFS on the reversed graph to find all safe nodes.

Time Complexity:
- Reversing the graph: O(V + E), where V = number of nodes and E = number of edges.
- Processing the queue: O(V + E).
- Sorting the safe nodes: O(V log V).
- Total: O(V + E + V log V).

Space Complexity:
- Reversed graph storage: O(V + E).
- In-degree array: O(V).
- Queue and result storage: O(V).
- Total: O(V + E).

*/

vector<int> safeStateBfs(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> ideg(n, 0);          // In-degree for reversed graph
    vector<vector<int>> rGraph(n);  // Reversed graph representation

    // Reverse the graph and calculate in-degrees
    for (int i = 0; i < n; i++) {
        for (auto it : graph[i]) {
            rGraph[it].push_back(i);
            ideg[i]++;
        }
    }

    // Initialize the queue with nodes having in-degree 0
    queue<int> q;
    vector<int> safeNode;
    for (int i = 0; i < n; i++) {
        if (ideg[i] == 0) {
            q.push(i);
        }
    }

    // Process nodes using BFS
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        safeNode.push_back(node);
        for (auto it : rGraph[node]) {
            ideg[it]--;
            if (ideg[it] == 0) {
                q.push(it);
            }
        }
    }

    // Sort the safe nodes to return them in ascending order
    sort(safeNode.begin(), safeNode.end());
    return safeNode;
}

int main() {
    // Example usage
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};

    // Calling the function to find safe nodes
    vector<int> safeNodes = safeStateBfs(graph);

    // Printing the result
    cout << "Safe Nodes: ";
    for (auto node : safeNodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

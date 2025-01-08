#include<bits/stdc++.h>
using namespace std;

/* 
ABOUT QUESTION:
What is Topological Sort?
- Topological sort is a linear ordering of vertices in a directed acyclic graph (DAG) such that for every directed edge u → v, vertex u comes before v in the ordering.

Why is it applicable only in DAGs?
- Topological sorting requires the graph to be acyclic; otherwise, it would not be possible to establish a valid order of nodes.

Intuition:
- Use DFS to explore nodes, ensuring that all dependencies of a node are processed before the node itself.
- Push nodes to a stack once their processing is complete. Reversing the stack gives the topological order.
*/

// DFS function to perform Topological Sort
void topodfs(int node, vector<vector<int>> &graph, vector<int> &vis, stack<int> &st) {
    vis[node] = 1;
    for (auto it : graph[node]) {
        if (!vis[it]) {
            topodfs(it, graph, vis, st);
        }
    }
    st.push(node); // Push the node to the stack after exploring all its dependencies
}

// Function to return the topological sort order
vector<int> topoSort(vector<vector<int>> &graph) {
    int n = graph.size();
    stack<int> st;
    vector<int> vis(n, 0);
    
    // Perform DFS for all unvisited nodes
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            topodfs(i, graph, vis, st);
        }
    }
    
    // Extract the order from the stack
    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
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

    vector<int> result = topoSort(graph);

    cout << "Topological Sort Order: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

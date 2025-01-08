#include<bits/stdc++.h>
using namespace std;

/* 
ABOUT THE QUESTION:
You are given an undirected graph represented by an adjacency list. 
The task is to detect if the graph contains a cycle. A cycle is 
a path of edges and vertices wherein a vertex is reachable again 
from itself.

APPROACH:
We will use Depth-First Search (DFS) to detect cycles.
1. Use a visited array to keep track of visited nodes.
2. Recursively traverse the graph. For each neighbor of the current node:
   - If the neighbor is not visited, recursively call DFS for it.
   - If the neighbor is already visited and is not the parent of the current node, a cycle is detected.

TIME COMPLEXITY:
O(V + E) where V is the number of vertices and E is the number of edges.
- Each vertex and edge is processed once during the DFS traversal.

SPACE COMPLEXITY:
O(V) for the visited array + O(V) for the recursive call stack.

*/

// Function to detect a cycle using DFS
bool detection(int node, int parent, vector<vector<int>> &adjList, vector<int> &vis) {
    vis[node] = 1;
    for (auto it : adjList[node]) {
        if (!vis[it]) {
            if (detection(it, node, adjList, vis)) {
                return true;
            }
        } else if (it != parent) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, m; // Number of vertices and edges
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> adjList(n); // Adjacency list
    cout << "Enter the edges (u v for an edge between u and v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Since it's an undirected graph
    }

    vector<int> vis(n, 0); // Visited array
    bool hasCycle = false;

    // Checking for cycles in all components of the graph
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (detection(i, -1, adjList, vis)) {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle) {
        cout << "The graph contains a cycle." << endl;
    } else {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}

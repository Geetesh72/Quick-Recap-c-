#include <bits/stdc++.h>
using namespace std;

/* 
ABOUT THE QUESTION:
You are given an undirected graph represented by an adjacency list. 
The task is to detect if the graph contains a cycle. A cycle is 
a path of edges and vertices wherein a vertex is reachable again 
from itself.

APPROACH:
We will use Breadth-First Search (BFS) and check for cycles in the graph.
1. Use a visited array to keep track of visited nodes.
2. Maintain a queue of pairs, where each pair contains the current node 
   and its parent node.
3. Traverse the graph, and if we encounter a node that has been visited 
   and is not the parent of the current node, a cycle is detected.

TIME COMPLEXITY:
O(V + E) where V is the number of vertices and E is the number of edges. 
- Each vertex and edge is processed once during the BFS traversal.

SPACE COMPLEXITY:
O(V) for the visited array + O(V) for the BFS queue.

*/

bool detectCycle(int src, vector<vector<int>> &adjList, vector<int> &vis) {
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});
    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto it : adjList[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push({it, node});
            } else if (parent != it) { // checking if it is already visited  then it must be parent of some but 
                return true; // //if it not equal parent then definetly there is cycle this is login 
            }
        }
    }
    return false;
}

int main() {
    int n, m; // Number of vertices and edges
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> adjList(n);
    cout << "Enter the edges (u v for an edge between u and v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Since it's an undirected graph
    }

    vector<int> vis(n, 0); // Visited array
    bool hasCycle = false;
    // connected components 
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (detectCycle(i, adjList, vis)) {
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

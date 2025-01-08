#include <bits/stdc++.h>
using namespace std;

/* ABOUT QUESTION
   - Number of Provinces: A province is a group of directly or indirectly connected nodes.
     Each province forms a connected component in the graph.

   - Task: Calculate the number of provinces using BFS or DFS.

   - Approach:
     - Represent the graph as an adjacency list.
     - Use a DFS-based helper function to mark all nodes in a province as visited.
     - Count the number of times a DFS starts to identify the number of provinces.
*/

/* Utility Function to Print Adjacency List */
void printAdjList(vector<vector<int>>& adj) {
    int n = adj.size();
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (auto neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

/* Helper Function for DFS */
void provinceHelper(vector<vector<int>>& adj, vector<int>& vis, int node) {
    vis[node] = 1;  // Mark current node as visited
    for (auto neighbor : adj[node]) {
        if (!vis[neighbor]) {
            provinceHelper(adj, vis, neighbor);  // Recursively visit neighbors
        }
    }
}

/* Function to Calculate Number of Provinces */
int noOfProvinces(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> vis(n, 0);  // Visited array
    int provinceCount = 0;  // Counter for provinces

    // Traverse all nodes
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {  // If the node is unvisited, it's a new province
            provinceCount++;
            provinceHelper(adj, vis, i);  // Mark all nodes in this province as visited
        }
    }
    return provinceCount;
}

/* Main Function */
int main() {
    /* OA Example
       Input:
       1
       Enter the Number of vertices (n) and edges (m): 6 5
       Enter the edges (u v for an edge between u and v):
       0 1
       1 2
       3 4
       4 5
       0 2
       Output:
       List:
       0: 1 2 
       1: 0 2 
       2: 1 0 
       3: 4 5 
       4: 3 5 
       5: 4 3 
       Number of Provinces: 2
    */

    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        int n, m;
        cout << "\nEnter the Number of vertices (n) and edges (m): ";
        cin >> n >> m;

        // Create adjacency list
        vector<vector<int>> adjList(n);
        cout << "Enter the edges (u v for an edge between u and v):" << endl;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);  // Since it's an undirected graph
        }

        // Print adjacency list
        cout << "List:" << endl;
        printAdjList(adjList);

        // Calculate and print the number of provinces
        int provinces = noOfProvinces(adjList);
        cout << "Number of Provinces: " << provinces << endl;
    }

    return 0;
}

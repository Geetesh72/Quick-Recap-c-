#include<bits/stdc++.h>
using namespace std;

/*
** BELLMAN-FORD ALGORITHM **
1. Why are we running the algorithm `n-1` times?
   - Bellman-Ford is based on the principle of relaxation, where the shortest path to a vertex is improved by iteratively updating the distance.
   - For a graph with `n` vertices, the longest possible shortest path will consist of at most `n-1` edges. Hence, we run the algorithm `n-1` times.

2. How can we detect if there is a negative-weight cycle?
   - After running `n-1` iterations, perform one more iteration. 
   - If any distance is still being updated, it indicates the presence of a negative-weight cycle.
*/

vector<int>bellManFor(vector<vector<int>>&graph, int src) {
    int n = graph.size(); // Number of edges in the graph
    vector<int>dist(n, 1e9); // Initialize distances with infinity
    dist[src] = 0; // Distance to the source vertex is always 0

    // Relax edges `n-1` times
    for (int i = 0; i < n - 1; i++) {
        for (auto it : graph) {
            int u = it[0]; // Source vertex of the edge
            int v = it[1]; // Destination vertex of the edge
            int wt = it[2]; // Weight of the edge

            // Relax the edge if a shorter path is found
            if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative-weight cycles
    for (auto it : graph) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        // If a distance can still be updated, there is a negative cycle
        if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
            return {-1}; // Return -1 if a negative cycle exists
        }
    }

    return dist; // Return the distances to all vertices
}

int main() {
    // Example usage
    vector<vector<int>> graph = {
        {0, 1, 5},   // Edge from 0 to 1 with weight 5
        {1, 2, 3},   // Edge from 1 to 2 with weight 3
        {2, 3, 2},   // Edge from 2 to 3 with weight 2
        {3, 1, -6}   // Edge from 3 to 1 with weight -6
    };
    int src = 0; // Source vertex

    vector<int> result = bellManFor(graph, src);

    if (result[0] == -1) {
        cout << "Graph contains a negative-weight cycle." << endl;
    } else {
        cout << "Shortest distances from source " << src << ":" << endl;
        for (int i = 0; i < result.size(); i++) {
            cout << "Vertex " << i << ": " << result[i] << endl;
        }
    }

    return 0;
}

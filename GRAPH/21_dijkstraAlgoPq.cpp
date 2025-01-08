#include <bits/stdc++.h>
using namespace std;

/*
ABOUT QUESTION:
Dijkstra's algorithm is used to find the shortest path from a source node to all other nodes in a weighted graph. 
It guarantees the shortest path in graphs with non-negative weights.

Intuition:
- Use a priority queue (min-heap) to always process the node with the smallest tentative distance.
- Relax edges: For each neighbor of the current node, update its distance if a shorter path is found.
- Once a node is processed (popped from the priority queue), its shortest distance is finalized.

Why it doesn't work with negative weights:
- Dijkstra assumes that once a node's shortest distance is finalized, it won't change. 
  Negative weights can lead to shorter paths after a node is finalized, breaking this assumption.
  For graphs with negative weights, use the Bellman-Ford algorithm instead.

Time Complexity:
1. Priority queue operations: O((n + m) * log(n)), where n = number of nodes, m = number of edges.
2. Relaxation of edges: O(m).
Total: O((n + m) * log(n)).

Space Complexity:
1. Distance array: O(n).
2. Priority queue: O(n).
3. Adjacency list: O(n + m).
Total: O(n + m).

why pq not q 

Priority Queue (or Set):

  Always processes the node with the minimum distance first.
  Ensures that we relax edges in order of increasing distance, adhering to Dijkstra's logic.
  If a shorter distance is found for a node already in the queue, the distance is updated, and the priority order adjusts accordingly.
Regular Queue:

Processes nodes in the order they are added (FIFO).
  Does not consider the distance when dequeuing, leading to possible inefficiencies.
  May relax edges out of order, resulting in potentially incorrect results (if a longer path is processed before a shorter one).
  Why Can't We Use a Regular Queue in Dijkstra's Algorithm?
Correctness Issue: In a queue, nodes are processed in the order they are added, regardless of their distances. This can lead to situations where a node is processed with a longer path before it is processed with a shorter path, violating Dijkstra's principle.

Efficiency Issue: Without processing nodes in order of increasing distance, the algorithm may unnecessarily revisit nodes and repeatedly update distances, leading to inefficiency.

*/

vector<int> dijkstra(int src, vector<vector<vector<int>>> &graph) {
    int n = graph.size();

    // Initialize distance array with infinity
    vector<int> dis(n, 1e9);
    dis[src] = 0;

    // Min-heap (priority queue) for processing nodes by shortest distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    // Dijkstra's algorithm
    while (!pq.empty()) {
        int node = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        for (auto it : graph[node]) {
            int adjNode = it[0];
            int edgeWeight = it[1];
            if (dist + edgeWeight < dis[adjNode]) { // Relaxation
                dis[adjNode] = dist + edgeWeight;
                pq.push({dis[adjNode], adjNode});
            }
        }
    }
    return dis;
}

int main() {
    // Example usage
    int n = 6; // Number of nodes
    vector<vector<vector<int>>> graph = {
        {{1, 2}, {2, 4}},       // Node 0: edges to 1 (weight 2), 2 (weight 4)
        {{2, 1}, {3, 7}},       // Node 1: edges to 2 (weight 1), 3 (weight 7)
        {{4, 3}},               // Node 2: edge to 4 (weight 3)
        {{5, 1}},               // Node 3: edge to 5 (weight 1)
        {{3, 2}, {5, 5}},       // Node 4: edges to 3 (weight 2), 5 (weight 5)
        {}                      // Node 5: no outgoing edges
    };

    int src = 0; // Source node

    // Call the Dijkstra function
    vector<int> result = dijkstra(src, graph);

    // Print the shortest distances from the source node
    cout << "Shortest distances from node " << src << ": ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

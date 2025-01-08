#include <bits/stdc++.h>
using namespace std;

/*
ABOUT QUESTION:
This implementation of Dijkstra's algorithm uses a `set` instead of a priority queue to keep track of nodes with the smallest tentative distances.
The `set` is used because it allows efficient removal of elements, which is useful when updating distances.

Intuition:
- Use a `set` to store pairs of (distance, node). 
- At each step, process the node with the smallest distance and update its neighbors if a shorter path is found.
- Remove and re-insert a node into the set when its distance is updated.

Why use a `set`?
- Unlike a priority queue, a `set` allows for efficient removal of elements, making it easier to handle updates to distances.

Time Complexity:
1. Insertion and deletion in a set: O(log(n)).
2. Total operations on `set`: O((n + m) * log(n)), where n = number of nodes, m = number of edges.
3. Relaxation of edges: O(m).
Total: O((n + m) * log(n)).

Space Complexity:
1. Distance array: O(n).
2. Set: O(n).
3. Adjacency list: O(n + m).
Total: O(n + m).
*/

/*
*/

vector<int> dijkstraSet(vector<vector<vector<int>>> &graph, int src) {
    int n = graph.size();

    // Initialize distance array with infinity
    vector<int> dis(n, 1e9);
    dis[src] = 0;

    // Set to store pairs of (distance, node)
    set<pair<int, int>> st;
    st.insert({0, src});

    while (!st.empty()) {
        auto it = *(st.begin());
        int dist = it.first;
        int node = it.second;
        st.erase(it); // Remove the current node from the set

        for (auto iter : graph[node]) {
            int adjNode = iter[0];
            int edgeWeight = iter[1];

            if (dist + edgeWeight < dis[adjNode]) { // Relaxation
                if (dis[adjNode] != 1e9) {
                    st.erase({dis[adjNode], adjNode}); // Remove the old pair
                }
                dis[adjNode] = dist + edgeWeight; // Update distance
                st.insert({dis[adjNode], adjNode}); // Insert the updated pair
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
    vector<int> result = dijkstraSet(graph, src);

    // Print the shortest distances from the source node
    cout << "Shortest distances from node " << src << ": ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

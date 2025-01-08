#include<bits/stdc++.h>
using namespace std;

/*
**About the Question**
- The problem involves finding the cheapest flight from a source to a destination with at most `k` stops.
- This is a variation of the shortest path problem where the number of stops is limited.

**Why Dijkstra Fails:**
- Dijkstra's algorithm fails in this scenario because it does not consider the number of stops while calculating the shortest path.
- In Dijkstra's algorithm, we always prioritize the shortest distance, but here we must also account for the number of stops, which adds a constraint.

**Why Use Normal Queue Instead of Priority Queue:**
- We use a **normal queue** because this problem is solved using a **modified BFS**.
- BFS naturally processes nodes level by level (or stop by stop here), which is ideal for limiting the number of stops.
- A priority queue would prioritize shorter distances regardless of the number of stops, which might lead to incorrect results for this problem.

**Why Prioritize Stops:**
- The constraint on the number of stops is crucial. We cannot allow the path with fewer stops to be overridden by a path with a larger number of stops but shorter distance.

**Approach:**
- Use a BFS-like traversal where each node tracks its current distance and the number of stops taken.
- If a new path has fewer stops and a shorter distance, update the distance and explore further.
*/

int cheapFlight(vector<vector<int>>& flight, int src, int dest, int k) {
    int n = flight.size();
    vector<pair<int, int>> adjList[n]; // Adjacency list to store graph {destination, weight}
    // vector<vector<pair<int,int>>> adjList2(n
    // Build adjacency list from the flight data
    for (auto it : flight) {
        adjList[it[0]].push_back({it[1], it[2]});
    }

    // Queue to store {stops, {currentNode, currentDistance}}
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});

    // Distance array initialized to a large value
    vector<int> dist(n, 1e9);
    dist[src] = 0;

    // Perform BFS-like traversal
    while (!q.empty()) {
        auto it = q.front();
        int stops = it.first;           // Number of stops taken so far
        int node = it.second.first;     // Current node
        int nodeEdw = it.second.second; // Current distance
        q.pop();

        // If stops exceed k, skip processing
        if (stops > k) {
            continue;
        }

        // Traverse neighbors of the current node
        for (auto iter : adjList[node]) {
            int aNode = iter.first;  // Adjacent node
            int edw = iter.second;   // Edge weight
            // Check if a shorter path exists with allowed stops
            if (edw + nodeEdw < dist[aNode] && stops <= k) {
                dist[aNode] = edw + nodeEdw; // Update distance
                q.push({stops + 1, {aNode, dist[aNode]}}); // Add to queue with updated stops
            }
        }
    }

    // If the destination is unreachable, return -1
    if (dist[dest] == 1e9) return -1;
    return dist[dest];
}

int main() {
    // Example usage
    vector<vector<int>> flight = {
        {0, 1, 100}, 
        {1, 2, 100}, 
        {0, 2, 500}
    };
    int src = 0, dest = 2, k = 1;
    cout << "Cheapest flight cost: " << cheapFlight(flight, src, dest, k) << endl;
    return 0;
}

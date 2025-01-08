#include <bits/stdc++.h>
using namespace std;

/*
Question Description:
You are given `n` courses labeled from 0 to n-1 and a list of prerequisite pairs, where `pre[i] = {ai, bi}` indicates 
that you must take course `bi` before course `ai`. Determine if you can complete all the courses.

Input:
n - Number of courses (0 to n-1).
pre - A list of prerequisite pairs.

Output:
Return `true` if you can complete all courses, otherwise return `false`.

Approach (Intuition):
- Represent the problem as a directed graph where nodes are courses and edges are prerequisites.
- Perform a topological sort using Kahn's Algorithm:
    1. Calculate in-degrees of all nodes (number of prerequisites for each course).
    2. Add nodes with in-degree 0 (courses with no prerequisites) to a queue.
    3. Process nodes from the queue, reducing the in-degree of adjacent nodes (courses that depend on the current course).
    4. If all courses are processed, it's possible to complete all courses; otherwise, it's not.

Time Complexity:
- Building the adjacency list and calculating in-degrees: O(V + E), where V = n (courses) and E = number of prerequisite pairs.
- Processing the queue: O(V + E).
- Total: O(V + E).

Space Complexity:
- Adjacency list: O(V + E).
- In-degree array: O(V).
- Queue: O(V).
- Total: O(V + E).
*/

bool canFinish(int n, vector<pair<int, int>>& pre) {
    vector<vector<int>> adjList(n);  // Adjacency list to represent the graph
    vector<int> iDeg(n, 0);         // In-degree array

    // Build the graph and calculate in-degrees
    for (auto it : pre) {
        adjList[it.second].push_back(it.first);
        iDeg[it.first]++;
    }

    // Initialize the queue with courses having no prerequisites
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (iDeg[i] == 0) {
            q.push(i);
        }
    }

    int cnt = 0; // Count of courses processed

    // Process courses using BFS (Kahn's Algorithm)
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cnt++;
        // ans.push_back(node)
        for (auto it : adjList[node]) {
            iDeg[it]--;
            if (iDeg[it] == 0) {
                q.push(it);
            }
        }
    }

    return cnt == n; // If all courses are processed, return true
}

int main() {
    int n; // Number of courses
    cout << "Enter the number of courses: ";
    cin >> n;

    int m; // Number of prerequisite pairs
    cout << "Enter the number of prerequisite pairs: ";
    cin >> m;

    vector<pair<int, int>> pre; // Prerequisite pairs
    cout << "Enter the prerequisite pairs (a b, where b is prerequisite for a):" << endl;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        pre.push_back({a, b});
    }

    // Call the function and print the result
    if (canFinish(n, pre)) {
        cout << "Yes, you can finish all courses." << endl;
    } else {
        cout << "No, you cannot finish all courses." << endl;
    }

    return 0;
}

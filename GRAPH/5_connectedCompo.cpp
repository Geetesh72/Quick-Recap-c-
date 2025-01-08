#include <bits/stdc++.h>
using namespace std;

/* ABOUT QUESTION:
   - Task: Find the number of connected components in an undirected graph.
   - Input: Adjacency matrix of the graph, starting nodes, and directions allowed (left, right, up, down).
   - Approach: Use BFS for traversal. Maintain a visited 2D matrix for marking visited nodes.
*/

// Function to print the adjacency matrix
void printAdjMatrix(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// BFS to find connected components
void bfsConnectedComponent(int i, int j, vector<vector<int>> &adjMatrix, vector<vector<int>> &vis) {
    int n = adjMatrix.size();
    int m = adjMatrix[0].size();

    // Directions for left, right, up, down
    vector<int> dRow = {-1, 1, 0, 0};  // Change in rows
    vector<int> dCol = {0, 0, -1, 1};  // Change in columns

    vis[i][j] = 1;  // Mark current node as visited
    queue<pair<int, int>> q;
    q.push({i, j});

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // Explore neighbors
        for (int k = 0; k < 4; k++) {
            int newRow = row + dRow[k];
            int newCol = col + dCol[k];

            // Check bounds and conditions
            if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < m &&
                adjMatrix[newRow][newCol] == 1 && !vis[newRow][newCol]) {
                vis[newRow][newCol] = 1;
                q.push({newRow, newCol});
            }
        }
    }
}

// Function to count connected components
int connectedComponents(vector<vector<int>> &adjMatrix) {
    int n = adjMatrix.size();
    int m = adjMatrix[0].size();
    int count = 0;

    // Visited matrix
    vector<vector<int>> vis(n, vector<int>(m, 0));

    // Traverse all nodes
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (adjMatrix[i][j] == 1 && !vis[i][j]) {
                count++;
                bfsConnectedComponent(i, j, adjMatrix, vis);  // Start BFS for a new component
            }
        }
    }
    return count;
}

/* MAIN FUNCTION */
int main() {
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--) {
        int n, m;  // Dimensions of the matrix
        cout << "Enter the dimensions of the adjacency matrix (n x m): ";
        cin >> n >> m;

        // Input adjacency matrix
        vector<vector<int>> adjMatrix(n, vector<int>(m, 0));
        cout << "Enter the adjacency matrix values (1 for edge, 0 for no edge):" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> adjMatrix[i][j];
            }
        }

        // Print adjacency matrix
        cout << "Adjacency Matrix:" << endl;
        printAdjMatrix(adjMatrix);

        // Calculate the number of connected components
        int components = connectedComponents(adjMatrix);
        cout << "Number of Connected Components: " << components << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// Function to perform BFS and update distances
void updateBFS(int i, int j, vector<vector<int>> &nums, vector<vector<int>> &dist, vector<vector<int>> &vis) {
    int n = nums.size();
    int m = nums[0].size();
    queue<pair<pair<int, int>, int>> q; // { {row, col}, distance }
    vector<int> drow = {1, -1, 0, 0};  // Directions for row movement
    vector<int> dcol = {0, 0, -1, 1};  // Directions for column movement

    q.push({{i, j}, 0}); // Start BFS from cell (i, j)
    vis[i][j] = 1;

    while (!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dis = q.front().second;
        q.pop();

        dist[row][col] = dis; // Update the distance for the current cell

        // Explore all 4 possible directions
        for (int k = 0; k < 4; k++) {
            int nrow = row + drow[k];
            int ncol = col + dcol[k];

            // Check bounds and conditions for BFS traversal
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] && nums[nrow][ncol] == 1) {
                q.push({{nrow, ncol}, dis + 1});
                vis[nrow][ncol] = 1;
            }
        }
    }
}

// Function to calculate the updated distances for each cell
vector<vector<int>> updatedDist(vector<vector<int>> &nums) {
    int n = nums.size();
    int m = nums[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0)); // Visited matrix
    vector<vector<int>> dist(n, vector<int>(m, 0)); // Distance matrix

    // Traverse the grid and start BFS from cells with value 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && nums[i][j] == 0) {
                updateBFS(i, j, nums, dist, vis);
            }
        }
    }
    return dist; // Return the updated distance matrix
}

int main() {
    int n, m;
    cout << "Enter the number of rows (n) and columns (m): ";
    cin >> n >> m;

    vector<vector<int>> nums(n, vector<int>(m));
    cout << "Enter the grid values (0 or 1):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> nums[i][j];
        }
    }

    vector<vector<int>> result = updatedDist(nums);

    cout << "Updated Distance Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

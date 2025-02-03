#include <bits/stdc++.h>
using namespace std;

/*
Searching in a 2D Matrix (Sorted Row-wise and Column-wise):

Approach:
- Start from one of the four possible corners:
  1. Top-right corner (0, m-1)
  2. Bottom-left corner (n-1, 0)
- Move either left or down based on the comparison of the current element with the target:
  - If the current element is greater than the target, move left.
  - If the current element is smaller than the target, move down.

Why these corners?
- From the top-right corner (0, m-1):
  - Moving left decreases the value.
  - Moving down increases the value.
- Similarly, from the bottom-left corner (n-1, 0):
  - Moving up decreases the value.
  - Moving right increases the value.

Time Complexity: O(n + m)
Space Complexity: O(1)
*/

// Function to search for a target in a sorted 2D matrix
vector<int> searchII(vector<vector<int>>& nums, int target) {
    int n = nums.size();
    int m = nums[0].size();
    
    // Starting from the top-right corner (0, m-1)
    int row = 0, col = m - 1;
    
    while (row < n && col >= 0) {
        if (nums[row][col] == target) {
            return {row, col};  // Target found
        } else if (nums[row][col] > target) {
            col--;  // Move left
        } else {
            row++;  // Move down
        }
    }
    return {-1, -1};  // Target not found
}

int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };
    int target = 5;

    // Search for the target in the matrix
    vector<int> result = searchII(matrix, target);

    if (result[0] != -1) {
        cout << "Target found at position: (" << result[0] << ", " << result[1] << ")\n";
    } else {
        cout << "Target not found in the matrix.\n";
    }

    return 0;
}

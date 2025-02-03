#include <bits/stdc++.h>
using namespace std;

/*
Finding a Peak Element in a 2D Matrix:

Problem:
- A peak element is an element that is strictly greater than its neighbors.
- For a 2D matrix, the neighbors are the adjacent elements to the left, right, top, and bottom.

Approach:
- Use Binary Search on columns:
  1. For the current middle column, find the maximum element in that column.
  2. Compare this maximum element with its left and right neighbors.
  3. Based on the comparison, decide whether to move left, right, or if the current element is the peak.

Why Binary Search on columns?
- This approach reduces the search space from \(m\) columns to \(\log m\), where \(m\) is the number of columns.
- Combined with the linear scan for finding the maximum in a column (\(O(n)\)), the overall complexity is \(O(n \cdot \log m)\).

Function Breakdown:
1. `findMaxIndex`: Finds the maximum element in a given column.
2. `findPeak`: Uses binary search on columns to find a peak element.

Time Complexity: \(O(n \cdot \log m)\)
Space Complexity: \(O(1)\*/

// Function to find the maximum element in a given column
int findMaxIndex(vector<vector<int>>& nums, int n, int m, int col) {
    int maxVal = -1;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (nums[i][col] > maxVal) {
            maxVal = nums[i][col];
            index = i;
        }
    }
    return index;
}

// Function to find a peak element in the 2D matrix
vector<int> findPeak(vector<vector<int>>& nums) {
    int n = nums.size();     // Number of rows
    int m = nums[0].size();  // Number of columns
    int low = 0, high = m - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;           // Middle column
        int maxRowIdx = findMaxIndex(nums, n, m, mid); // Row index of the max element in the middle column
        
        int left = (mid - 1 >= 0) ? nums[maxRowIdx][mid - 1] : -1;  // Left neighbor
        int right = (mid + 1 < m) ? nums[maxRowIdx][mid + 1] : -1;  // Right neighbor
        
        // Check if the current element is a peak
        if (nums[maxRowIdx][mid] > left && nums[maxRowIdx][mid] > right) {
            return {maxRowIdx, mid}; // Return the coordinates of the peak
        }
        // Move to the left half
        else if (nums[maxRowIdx][mid] < left) {
            high = mid - 1;
        }
        // Move to the right half
        else {
            low = mid + 1;
        }
    }
    return {-1, -1}; // If no peak is found (edge case)
}

int main() {
    vector<vector<int>> matrix = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}
    };

    vector<int> peak = findPeak(matrix);

    if (peak[0] != -1) {
        cout << "Peak element found at: (" << peak[0] << ", " << peak[1] << ")\n";
        cout << "Peak element value: " << matrix[peak[0]][peak[1]] << "\n";
    } else {
        cout << "No peak element found in the matrix.\n";
    }

    return 0;
}

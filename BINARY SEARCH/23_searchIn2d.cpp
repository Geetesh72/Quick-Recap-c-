#include <bits/stdc++.h>
using namespace std;

/*
Search in a 2D Sorted Matrix:

1. Method 1 (Row-wise Binary Search):
   - Perform binary search on each row if the target lies within the row's range.
   - Time Complexity: O(n * log(m)), where n = number of rows, m = number of columns.
   - Space Complexity: O(1).

2. Method 2 (Optimal Solution):
   - Treat the 2D matrix as a 1D array using the formula:
     - row = mid / number_of_columns
     - col = mid % number_of_columns
   - Perform binary search on this virtual 1D array.
   - Time Complexity: O(log(n * m)).
   - Space Complexity: O(1).
*/

// Helper function for binary search in a 1D array
bool binary_search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            return true;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return false;
}

// Method 1: Row-wise Binary Search in 2D Matrix
bool searchIn2D(vector<vector<int>>& nums, int target) {
    int n = nums.size();
    int m = nums[0].size();

    for (int i = 0; i < n; i++) {
        // Check if the target could be in this row
        if (nums[i][0] <= target && target <= nums[i][m - 1]) {
            if (binary_search(nums[i], target)) {
                return true;
            }
        }
    }
    return false;
}

// Method 2: Optimal Search in 2D Matrix
bool search2DOptimal(vector<vector<int>>& nums, int target) {
    int n = nums.size();
    int m = nums[0].size();
    int low = 0, high = n * m - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int element = nums[mid / m][mid % m];  // Convert 1D index to 2D row & col

        if (element == target) {
            return true;
        } else if (element < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target = 3;

    // Test Row-wise Binary Search
    if (searchIn2D(matrix, target)) {
        cout << "Target found using Row-wise Binary Search.\n";
    } else {
        cout << "Target not found using Row-wise Binary Search.\n";
    }

    // Test Optimal Search
    if (search2DOptimal(matrix, target)) {
        cout << "Target found using Optimal Search.\n";
    } else {
        cout << "Target not found using Optimal Search.\n";
    }

    return 0;
}

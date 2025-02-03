#include <bits/stdc++.h>
using namespace std;

/*
Median of a Row-Wise Sorted Matrix:

Problem:
- Given a matrix where each row is sorted, find the median of the matrix.
- Median: The middle element in the sorted order of all elements. 
  - If the total number of elements is odd, it's the middle one.
  - If it's even, it's the average of the two middle elements.

Approach:
1. **Binary Search on Value Range**:
   - Find the minimum and maximum values in the matrix.
   - Use binary search to count how many elements in the matrix are less than or equal to a mid-value.
   - Narrow down the search space until the median is found.

2. **Why Binary Search on Values?**
   - Instead of sorting all elements (O(n*m * log(n*m))), binary search on the value range reduces complexity.
   - Counting elements less than or equal to `mid` takes O(n * log(m)) (using binary search for each row).

Time Complexity: O(32 * n * log(m)) ≈ O(n * log(m)), where 32 is the number of bits in an integer.
Space Complexity: O(1) */

// Helper function to count elements <= target in a row using binary search
int countSmallerEqual(vector<int>& row, int target) {
    return upper_bound(row.begin(), row.end(), target) - row.begin();
}

// Function to find the median of a row-wise sorted matrix
int findMedian(vector<vector<int>>& matrix) {
    int n = matrix.size();    // Number of rows
    int m = matrix[0].size(); // Number of columns
    
    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < n; i++) {
        low = min(low, matrix[i][0]);      // Minimum value in the matrix
        high = max(high, matrix[i][m - 1]); // Maximum value in the matrix
    }
    
    int desired = (n * m + 1) / 2; // Position of the median element in sorted order
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = 0;
        
        // Count elements <= mid for all rows
        for (int i = 0; i < n; i++) {
            count += countSmallerEqual(matrix[i], mid);
        }
        
        if (count < desired) {
            low = mid + 1; // Median is greater than mid
        } else {
            high = mid;    // Median is <= mid
        }
    }
    
    return low; // The median value
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    
    cout << "Median of the matrix: " << findMedian(matrix) << endl;

    return 0;
}

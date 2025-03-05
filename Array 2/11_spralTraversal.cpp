#include<bits/stdc++.h>
using namespace std;

/* Spiral Matrix Traversal:
   - Traverse the matrix layer by layer in the following order:
     1. Top row (left to right)
     2. Right column (top to bottom)
     3. Bottom row (right to left) [if applicable]
     4. Left column (bottom to top) [if applicable]
*/


vector<int>spiralOrder(vector<vector<int>>&nums) {
    int n = nums.size();     // Number of rows
    int m = nums[0].size();  // Number of columns
    vector<int>ans;          // Resultant vector to store spiral order

    int left = 0, right = m - 1;   // Column boundaries
    int top = 0, bottom = n - 1;  // Row boundaries

    // Iterate until all layers are processed
    while (top <= bottom && left <= right) {
        
        // Step 1: Traverse the top row (left to right)
        for (int i = left; i <= right; i++) {
            ans.push_back(nums[top][i]);
        }
        top++;  // Move the top boundary down
        
        // Step 2: Traverse the right column (top to bottom)
        for (int i = top; i <= bottom; i++) {
            ans.push_back(nums[i][right]);
        }
        right--;  // Move the right boundary left
        
        // Step 3: Traverse the bottom row (right to left), if still within bounds
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(nums[bottom][i]);
            }
            bottom--;  // Move the bottom boundary up
        }

        // Step 4: Traverse the left column (bottom to top), if still within bounds
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(nums[i][left]);
            }
            left++;  // Move the left boundary right
        }
    }
    
    return ans;
}

int main() {
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--) {
        int n, m;
        cout << "Enter number of rows and columns: ";
        cin >> n >> m;

        vector<vector<int>>nums(n, vector<int>(m));
        cout << "Enter the elements of the matrix:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> nums[i][j];
            }
        }

        // Compute the spiral order
        vector<int>result = spiralOrder(nums);

        // Display the spiral order
        cout << "Spiral Order of the Matrix:" << endl;
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
    }

    

    return 0;
}

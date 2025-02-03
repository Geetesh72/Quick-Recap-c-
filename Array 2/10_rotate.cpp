#include<bits/stdc++.h>
using namespace std;

/* Brute Force Approach:
   Create a new matrix `ans` and set each cell in the rotated position.
   Equation derived:
   - Row index of the rotated element: `j`
   - Column index of the rotated element: `(n-1)-i`
*/
vector<vector<int>>rotate90Brute(vector<vector<int>>&nums) {
    int n = nums.size();
    int m = nums[0].size();
    
    // Initialize a new matrix for the result
    vector<vector<int>>ans(n, vector<int>(m, 0));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            // Assign the rotated value
            ans[j][(n-1)-i] = nums[i][j];
        }
    }
    
    return ans;
}

/* Optimal Approach (In-place Rotation):
   1. Transpose the matrix:
      Swap elements across the diagonal `nums[i][j]` and `nums[j][i]` for `j > i`.
   2. Reverse each row:
      After transposition, reverse each row to achieve the 90-degree rotation.
*/
vector<vector<int>>rotate90Optimal(vector<vector<int>>&nums) {
    int n = nums.size(); // Number of rows (square matrix)
    
    // Step 1: Transpose the matrix
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) { // Only swap for `j > i`
            swap(nums[i][j], nums[j][i]);
        }
    }
    
    // Step 2: Reverse each row to achieve the final rotation
    for(int i = 0; i < n; i++) {
        reverse(nums[i].begin(), nums[i].end());
    }
    
    return nums;
}

int main() {
    int t;  // Number of test cases
    cout << "Enter number of test cases: ";
    cin >> t;

    while(t--) {
        int n;  // Size of the matrix (assuming square matrix)
        cout << "Enter the size of the matrix (n x n): ";
        cin >> n;

        vector<vector<int>>nums(n, vector<int>(n));
        
        cout << "Enter the elements of the matrix:" << endl;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> nums[i][j];
            }
        }
        
        cout << "Original Matrix:" << endl;
        for(auto row : nums) {
            for(auto val : row) {
                cout << val << " ";
            }
            cout << endl;
        }

        // Rotate the matrix 90 degrees using the optimal method
        nums = rotate90Optimal(nums);

        cout << "Matrix After 90-degree Rotation:" << endl;
        for(auto row : nums) {
            for(auto val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}

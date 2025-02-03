#include<bits/stdc++.h>
using namespace std;
void markRow (vector<vector<int>>&nums,int i){
    int n = nums.size();
    int m = nums[0].size();
    for(int j =0;j<m;j++){
        nums[i][j] = -1;
    }
}
void markCol (vector<vector<int>>&nums,int j){
    int n = nums.size();
    int m = nums[0].size();
    for(int i = 0;i<n;i++){
        nums[i][j] = -1;
    }
}
vector<vector<int>>setMatrixZero(vector<vector<int>>&nums){
    int n = nums.size();
    int m = nums[0].size();
    vector<vector<int>>copy = nums;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(nums[i][j]==0){
                markRow(nums,i);
                markCol(nums,j);
            }
        }
    }
}
vector<vector<int>>setZero(vector<vector<int>>&nums){
    int n = nums.size();
    int m = nums[0].size();
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(nums[i][j]==-1){
                nums[i][j]=0;
            }
        }
    }
    return nums;
}


// better approach 
vector<vector<int>>betterSetZero(vector<vector<int>>&nums){
    int n = nums.size();
    int m = nums[0].size();
    vector<int>row(n,0);
    vector<int>col(m,0);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(nums[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(row[i]==1 || col[j]==1){
                nums[i][j]=0;
            }
        }
    }
    return nums;

}

// optimal one 
#include<bits/stdc++.h>
using namespace std;

// Function to set matrix zeros optimally
vector<vector<int>>optimalSet(vector<vector<int>>&nums){
    int n = nums.size();  // Number of rows
    int m = nums[0].size();  // Number of columns
    
    int col0 = 1;  // A flag to check if the first column needs to be set to zero

    // Step 1: Mark rows and columns that need to be set to zero using the first row and first column
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(nums[i][j] == 0) {  
                // Mark the corresponding row and column
                nums[i][0] = 0;  // Mark the first cell of the row
                if(j != 0) {
                    nums[0][j] = 0;  // Mark the first cell of the column
                } else {
                    col0 = 0;  // First column itself needs to be set to zero
                }
            }
        }
    }

    // Step 2: Set matrix cells to zero based on markers, except the first row and column
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(nums[i][0] == 0 || nums[0][j] == 0) { 
                nums[i][j] = 0;  // If either row or column marker is zero, set the cell to zero
            }
        }
    }

    // Step 3: Handle the first row separately if needed
    if(nums[0][0] == 0) {
        for(int j = 0; j < m; j++) {
            nums[0][j] = 0;  // Set the entire first row to zero
        }
    }

    // Step 4: Handle the first column separately if needed
    if(col0 == 0) {
        for(int i = 0; i < n; i++) {
            nums[i][0] = 0;  // Set the entire first column to zero
        }
    }

    return nums;
}

int main(){ 
    // Example usage
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    cout << "Original Matrix: " << endl;
    for (auto row : matrix) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    matrix = optimalSet(matrix);

    cout << "\nMatrix After Setting Zeros: " << endl;
    for (auto row : matrix) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

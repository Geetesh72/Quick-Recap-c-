#include <bits/stdc++.h>
using namespace std;

/*

no outer boundary 

*/

int triangle(int i , int j  , vector<vector<int>>&nums,vector<vector<int>>&dp){
    int n = nums.size();
    if(i==n-1){
        return nums[n-1][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int down = nums[i][j]+triangle(i+1,j,nums,dp);
    int diagonal  = nums[i][j]+triangle(i+1,j+1,nums,dp);
    dp[i][j]=min(down,diagonal);

}


// space otimized 
int triangleBottom(vector<vector<int>>&nums,vector<vector<int>>&dp){
    int n = nums.size();
    for(int j =0;j<n;j++){
        dp[n-1][j] = nums[n-1][j];
    }

    for(int i = n-2;i>=0;i--){
        for(int j = i ;j>=0;j--){
            int down = dp[i+1][j]+nums[i][j];
            int daigonal = dp[i+1][j+1]+nums[i][j];
            dp[i][j]=min(daigonal,down);
        }
    }
    return dp[0][0];
}


int main()
{
     int n;
    cout << "Enter the number of rows in the triangle: ";
    cin >> n;
    vector<vector<int>> nums(n);
    cout << "Enter the elements of the triangle:\n";
    for (int i = 0; i < n; i++) {
        nums[i] = vector<int>(i + 1);
        for (int j = 0; j <= i; j++) {
            cin >> nums[i][j];
        }
    }

    // Memoization approach
    vector<vector<int>> dpMemo(n, vector<int>(n, -1));
    int resultMemo = triangle(0, 0, nums, dpMemo);
    cout << "\nMinimum Path Sum (Memoization): " << resultMemo << endl;

    // Tabulation approach
    vector<vector<int>> dpTab(n, vector<int>(n, 0));
    int resultTab = triangleBottom(nums, dpTab);
    cout << "Minimum Path Sum (Tabulation): " << resultTab << endl;

    return 0;
}
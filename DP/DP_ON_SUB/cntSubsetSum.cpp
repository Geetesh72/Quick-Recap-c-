/*
You are given an array (0-based indexing) of positive integers and you have
to tell how many different ways of selecting the elements from the array are
there such that the sum of chosen elements is equal to the target number
"tar".


*/

// tc 2^N FOR RECURSION 
// WE HAVE SPACE COMPLEXITY THE RECUSIVE STACK SPACE 
// no of zero and 1 
#include <bits/stdc++.h>
using namespace std;

int ways(int i, int target, vector<int> &nums, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if(target == 0 && nums[0]==0)return 2;
        if(target==0 || nums[0]==target)return 1;
        return 0;
    }
    if(dp[i][target]!=-1){
        return dp[i][target];
    }
    int notPick = ways(i-1,target,nums,dp);
    int pick =0;
    if(nums[i]<=target){
        pick  = ways(i-1,target-nums[i],nums,dp);
    }
    return dp[i][target] = pick + notPick;

}
// Now in tabulation 
int waysTabulation(vector<int>&nums,vector<vector<int>>&dp,int target){
    int n = nums.size();
    for(int i = 0;i<n;i++){
        dp[i][0] = 1;

    }
    if(nums[0]<=target){
        dp[0][nums[0]]=1;
    }
    for(int i = 1;i<n;i++){
        for(int j = 0;j<=target;j++){
            int notPick = dp[i-1][j];
            int pick =0;
            if(nums[i]<=j){
                pick = dp[i-1][j-nums[i]];

            }
            dp[i][j]=pick+notPick;
        }
    }
    return dp[n-1][target];

}

int main()
{
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter target sum: ";
    cin >> target;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Memoization
    vector<vector<int>> dpMemo(n, vector<int>(target + 1, -1));
    int memoResult = ways(n - 1, target, nums, dpMemo);
    cout << "Number of ways (Memoization): " << memoResult << endl;

    // Tabulation
    vector<vector<int>> dpTab(n, vector<int>(target +1, 0));
    int tabResult = waysTabulation(nums, dpTab, target);
    cout << "Number of ways (Tabulation): " << tabResult << endl;

    // Display Tabulation DP Table
    cout << "DP Table (Tabulation): " << endl;
    for (const auto &row : dpTab) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
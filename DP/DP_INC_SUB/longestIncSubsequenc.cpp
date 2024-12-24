#include<bits/stdc++.h>


/*ABOUT QUESTION 
  10 9 2 5 3 7 101 18 

*/

using namespace std;
int LongestIncresingSubsequence(int i , int prev, vector<int>&nums, vector<vector<int>>&dp){
    if(i==nums.size()){
        return 0;
    }
    if(dp[i][prev+1]!=-1){ // shifting the index 
        return dp[i][prev+1];

    }
    int notTake = 0+LongestIncresingSubsequence(i+1,prev,nums,dp);
    int take = 0;
    if(nums[i]>nums[prev] || prev==-1){
        take  = 1+LongestIncresingSubsequence(i+1,i,nums,dp);

    }
    return  dp[i][prev+1] = max(notTake,take);
 
}

// Tabulation
int tabulation(vector<int>&nums, vector<vector<int>>&dp){
    int n = nums.size();
    // no base case 
    for(int i  = n-1;i>=0;i--){
        for(int prev= i-1;prev>=-1;prev--){
            int notTake = 0 +dp[i+1][prev+1]; // cause going till last 
            int take = 0;
            if(prev==-1 || nums[i]>nums[prev]){
                take =1+dp[i+1][i+1];
            }
            dp[i][prev+1]=max(take,notTake);
        }
        
    }
    return dp[0][-1+1];
}
int main(){ 
int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Recursive with Memoization
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    int maxLengthRec = LongestIncresingSubsequence(0, -1, nums, dp);
    cout << "Length of Longest Increasing Subsequence (Recursive): " << maxLengthRec << endl;

    // Tabulation
    vector<vector<int>> dpTab(n + 1, vector<int>(n + 1, 0));
    int maxLengthTab = tabulation(nums, dpTab);
    cout << "Length of Longest Increasing Subsequence (Tabulation): " << maxLengthTab << endl;

    return 0;
}
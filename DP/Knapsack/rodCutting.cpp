/*
Problem description ->
given length of Rod = 5
also give price array 2 5 7 8 10
cut the pieces of rod so that geting maximum value
Size Of Rod----> price of that piece of Rod -------> maxi
1                 1X5                                 2X5 = 10
so on
we have to return maxi mum price of cutting he can get


collect Rod length to make N
try to pick length l & sum them up
made N i all possible ways

// rod index + 1 ;

*/
#include <bits/stdc++.h>
using namespace std;

int rodCost (int i , int N , vector<int>&nums,vector<vector<int>>&dp){
    if(i==0){
        return nums[0]*N;

    }
    if(dp[i][N]!=-1){
        return dp[i][N];
    }


    int notTake = 0 + rodCost(i-1,N,nums,dp);
    int take = INT_MIN;
    int rodLength = i+1;
    if(rodLength<=N){
        take = nums[i] + rodCost(i,N-rodLength,nums,dp);

    }
    dp[i][N] = max(take,notTake);
}
int rodCostTabular(int N, vector<int>&nums, vector<vector<int>>&dp){
    int  n = nums.size();
    for(int i = 0;i<=N;i++){
        dp[0][i] = nums[0]*i;
    }
    for(int i = 1;i<n;i++){
        for(int j = 0;j<=N;j++){
            int notTake = dp[i-1][j];
            int take =INT_MIN;
            if(i+1<=j){
                take = nums[i]+dp[i][j-(i+1)];
            }
            dp[i][j]=max(take,notTake);
        }
    }
    return dp[n-1][N];
}
int main()
{
   int N; // Rod length
    cout << "Enter the length of the rod: ";
    cin >> N;

    int n; // Number of price entries
    cout << "Enter the number of price entries: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the price array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Memoization
    vector<vector<int>> dpMemo(n, vector<int>(N + 1, -1));
    int maxCostMemo = rodCost(n - 1, N, nums, dpMemo);
    cout << "Maximum cost (Memoization): " << maxCostMemo << endl;

    // Tabulation
    vector<vector<int>> dpTab(n, vector<int>(N + 1, 0));
    int maxCostTab = rodCostTabular(N, nums, dpTab);
    cout << "Maximum cost (Tabulation): " << maxCostTab << endl;

    // Print DP table for Tabulation
    cout << "DP Table (Tabulation):" << endl;
    for (const auto& row : dpTab) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
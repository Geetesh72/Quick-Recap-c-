/*
ccoldown cant by right after sell

*/

#include <bits/stdc++.h>
using namespace std;
int coolDown(int i , int buy , int fee, vector<int>&nums, vector<vector<int>>&dp){
    int n = nums.size();
    if(i>=n){
     return 0;
    }
    if(dp[i][buy]!=-1){
        return dp[i][buy];
    }
    int profit = 0;
    if(buy){
        profit = max(-nums[i]+coolDown(i+1,0,fee,nums,dp),coolDown(i+1,1,fee,nums,dp));
    }
    else{
        profit = max(nums[i]-fee+coolDown(i+2,1,fee,nums,dp),coolDown(i+1,0,fee,nums,dp)); // selling is perform here 
    }
    return dp[i][buy] = profit;
}


// Tabulation 
int coolDownTabulation(int fee,vector<int>&nums,vector<vector<int>>&dp){
    int n = nums.size();
    dp[n][0] =dp[n][1]=0;
    for(int i  = n-1;i>=0;i--){
        for(int buy = 0; buy<=1;buy++){
            int profit  = 0;
            if(buy){
                profit = max(-nums[i]+dp[i+1][0],dp[i+1][1]);
            }
            else {
                profit = max(nums[i]-fee+((i+2<n)?dp[i+2][1]:0 ),dp[i+1][0]);
            }
            dp[i][buy]=profit;
        }
    }
    return dp[0][1];
}
int main()
{

    int n;
    cout << "Enter the number of days: ";
    cin >> n;
    int fee;
    cout<<"Enter the Fee of Transaction: ";
    cin>>fee;
    vector<int> prices(n);
    cout << "Enter the prices of stocks: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    // Recursive with Memoization
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    int maxProfitRec = coolDown(0, 1,fee, prices, dp);
    cout << "Maximum Profit (Recursive): " << maxProfitRec << endl;

    // Tabulation
    vector<vector<int>> dptab(n + 2, vector<int>(2, 0)); // Ensure extra space for dp[i+2]
    int maxProfitTab = coolDownTabulation(fee,prices, dptab);
    cout << "Maximum Profit (Tabulation): " << maxProfitTab << endl;

    return 0;
}
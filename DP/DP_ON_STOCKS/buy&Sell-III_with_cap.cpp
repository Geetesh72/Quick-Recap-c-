#include <bits/stdc++.h>
using namespace std;

/*
this question limit the cap not of only 2 transaction are allowed 
cap means we consider if we buy and it than we have to sell it that make the complete one transaction 
You are Harshad Mehta's friend. He told
you the price of a particular stock for the
next 'N' days. You can either buy or sell a
stock. Also, you can only complete at most
2-transactions. Find the maximum profit
that you can earn from these transactions.
You can take help from Mr. Mehta as well.


This question limits the cap to allow at most 2 transactions.
A transaction consists of a "buy" followed by a "sell".
Find the maximum profit you can earn under these conditions.

*/
int buySell_III(int i , int buy ,int cap, vector<int>&nums, vector<vector<vector<int>>>&dp){
    int n = nums.size();
     if (cap == 0 || i == n) return 0;
    if(dp[i][buy][cap]!=-1){
        return dp[i][buy][cap];
    }
    int profit = 0;
    if(buy){
        profit = max(-nums[i]+buySell_III(i+1,0,cap,nums,dp)
                     ,0+buySell_III(i+1,1,cap,nums,dp));
    }
    else {
        profit = max(nums[i]+buySell_III(i+1,1,cap-1,nums,dp),
                      buySell_III(i+1,0,cap,nums,dp));
    }
    return dp[i][buy][cap]  = profit;
}
int buy_sell_III_Tabulation( int cap, vector<int>&nums,vector<vector<vector<int>>>&dp){
    int n = nums.size();
    for(int i= 0;i<n;i++){
        for(int buy=0;buy<=1;buy++){
            dp[i][buy][0]=0; //No profit if no transactions are allowed.
        }
    }
    for(int buy = 0;buy<=1;buy++){
        for(int j  = 0;j<=cap;j++){
            dp[n][buy][j]=0;  // No profit if no days are left.
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int c = 1; c <= cap; c++) {
                if (buy) {
                    dp[i][buy][c] = max(-nums[i] + dp[i + 1][0][c], dp[i + 1][1][c]);
                } else {
                    dp[i][buy][c] = max(nums[i] + dp[i + 1][1][c - 1], dp[i + 1][0][c]);
                }
            }
        }
    }
    return dp[0][1][cap];





}


int main()
{
     int n;
    cout << "Enter the number of days: ";
    cin >> n;
    int cap;
    cout << "Enter the cap Allowed: ";
    cin>>cap;

    vector<int> prices(n);
    cout << "Enter the prices of stocks: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    // Recursive with Memoization
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(cap+1, -1)));
    int maxProfitRec = buySell_III(0, 1, cap, prices, dp);
    cout << "\nMaximum Profit (Recursive): " << maxProfitRec << endl;

    // Tabulation
    vector<vector<vector<int>>> dptab(n + 1, vector<vector<int>>(2, vector<int>(cap + 1, 0)));
    int maxProfitTab = buy_sell_III_Tabulation(cap,prices,dptab);
    cout << "Maximum Profit (Tabulation): " << maxProfitTab << endl;
    return 0;
}
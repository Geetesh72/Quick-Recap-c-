#include<bits/stdc++.h>
using namespace std;
/*
You can buy and sell as many times as you want.
Before buying the stock, you should have sold the previous holding stocks.
*/

/*
index , buy 0 / 1
if(1){
profit = max(-nums[i]+f(i+1,0),f(i+1,1))
}
else{
profit = max(nums[idx]+f(i+1,1),f(i+1,0))
}

look at the size of dp table so buy can have two values so that nX2 
we are goint 0 ---------------> n in this recursive apprach top down 
we are goinf n----------------> 0 in the bottom up 


*/
int buy_sell(int idx , int buy  , vector<int>&nums,vector<vector<int>>&dp){
    int n = nums.size();
    if(idx==n){
        return 0; // No profit if no days are left.
    }
    if(dp[idx][buy]!=-1){
        return dp[idx][buy];
    }
    int profit = 0;
    if(buy){
        profit = max(-nums[idx]+buy_sell(idx+1,0,nums,dp)
                      ,buy_sell(idx+1,1,nums,dp));
    }
    else{
        profit = max(nums[idx]+buy_sell(idx+1,1,nums,dp),
                     buy_sell(idx+1,0,nums,dp));
    }
    return dp[idx][buy] = profit;
}

int buy_sellTabulation(vector<int>&nums,vector<vector<int>>&dp){
    int n = nums.size();
    dp[n][0] = dp[n][1] = 0;
    for(int i = n-1;i>=0;i--){
        for(int j = 0;j<=1;j++){
            int profit = 0;
            if(j){
                profit = max(-nums[i]+dp[i+1][0],dp[i+1][1]);
            }
            else{
                profit = max(nums[i]+dp[i+1][1],dp[i+1][0]);
            }
            dp[i][j]=profit;

        }
    }
    
    

    return dp[0][1];
      
}
int main(){ 
     int n;
    cout << "Enter the number of days: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter the prices of stocks: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    // Recursive with Memoization
    vector<vector<int>> dp(n, vector<int>(2, -1));
    int maxProfitRec = buy_sell(0, 1, prices, dp);
    cout << "Maximum Profit (Recursive): " << maxProfitRec << endl;
     vector<vector<int>> dptab(n + 1, vector<int>(2, 0));

    // Tabulation
    int maxProfitTab = buy_sellTabulation(prices,dptab);
    cout << "Maximum Profit (Tabulation): " << maxProfitTab << endl;


return 0;
}
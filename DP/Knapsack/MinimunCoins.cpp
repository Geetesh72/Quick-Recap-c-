/*
No of denomination of coin to the target

 */


/* QUESTION'S DESCRIPTION 
little change in logic beacuse infinity suppy of coins 
take at same index because and adding one to every count of that coin
 take = 1+coins(i,target-nums[i],nums,dp);


in tabulation that t is not intial t so that 
run loop 0 ---------------> T so 
which target value is completely divide by nums[0] 
that is fill the dp table dp[0]---------> couse index is zero 
dp[0][i] ------> [i] -----> this is variable value of target 
so how can we fill it 
dp[0][i] = i/nums[0];

Infinite supply of coin that why we are standing at that index 
*/


#include <bits/stdc++.h>
using namespace std;

int coins(int i , int target , vector<int>&nums,vector<vector<int>>&dp){
    if(i==0){
        if(target%nums[i]==0){
            return target/nums[i];
        }
        return 1e9;
    }
    if(dp[i][target]!=-1){
        return dp[i][target];
    }
    int notTake = coins (i-1, target,nums,dp);
    int take = INT_MAX;
    if(target>=nums[i]){
        take = 1+coins(i,target-nums[i],nums,dp);

    }
    return dp[i][target ] = min(take,notTake);
}

int coinsTabulation(int target , vector<int>&nums, vector<vector<int>>&dp){
    int n = nums.size();
    for(int i = 0;i<=target;i++){
        if(i%nums[0]==0){
            dp[0][i]=i/nums[0];
        }else{
            dp[0][i] = 1e9;
        }
    }
    for(int i = 1;i<n;i++){
        for(int j = 0;j<=target;j++){
            int notTake = dp[i-1][j];
            int take = 1e9;
            if(j>=nums[i]){
                take  = 1 + dp[i][j-nums[i]];
            }
            dp[i][j] = min(take,notTake);
        }
    }
    return dp[n-1][target];
}

int main()
{
   int n, target;
    cout << "Enter number of coin denominations: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter coin denominations: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << "Enter target value: ";
    cin >> target;
    
    // Memoization Approach (Uncomment for testing)
    vector<vector<int>> dpMemo(n, vector<int>(target + 1, -1));
    int memoResult = coins(n - 1, target, nums, dpMemo);
    cout << "Minimum coins (Memoization): " << memoResult << endl;

    // Tabulation Approach
    vector<vector<int>> dpTab(n, vector<int>(target + 1, 0));
    int tabResult = coinsTabulation(target, nums, dpTab);
    cout << "Minimum coins (Tabulation): " << tabResult << endl;

    // Display DP Table (Tabulation)
    cout << "DP Table (Tabulation):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= target; j++) {
            if (dpTab[i][j] == 1e9)
                cout << "INF ";  // Representing unreachable with INF
            else
                cout << dpTab[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
/*\

given weight array =  3 4 5
given value array = 30 50 60
bag wt capacity = 8

whenever two array is given think about knapsack problem



*/

//
/*

Trying out all ways

*/

// Rules
/*
express in term of index in this case (ind , weight of bag )
explore all possiblities
max of all
*/
#include <bits/stdc++.h>
using namespace std;

int knapSack(int i, int wt, vector<int> &nums, vector<int> &val, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (nums[i] <= wt)
        {
            return val[i];
        }
        return 0;
    }
    if (dp[i][wt] != -1)
    {
        return dp[i][wt];
    }
    int notTake = 0 + knapSack(i - 1, wt, nums, val, dp);
    int take = -1e9;
    if (nums[i] <= wt)
    {
        take = val[i] + knapSack(i - 1, wt - nums[i], nums, val, dp);
    }

    return dp[i][wt] = max(take, notTake);
}

// tabulation
int knapSackTabulation(vector<int> &nums, vector<int> &val, vector<vector<int>> &dp, int maxi)
{
    int n = nums.size();
    int m = val.size();

    for(int wt  = 0;wt<=maxi;wt++){
        if(wt>=nums[0])
        {
            dp[0][wt] = val[0];
        }
    }
    // for (int i = nums[0]; i <= maxi; i++)
    // {
    //     dp[0][i] = val[0];
    // }
    /*
    for(int wt = 0;wt<=maxi;wt++){
       if(wt>=nums[0]){
       dp[0][wt]=val[0];
      }
    }
    */

    for (int i = 1; i < n; i++)
    {
        for (int wt = 0; wt <= maxi; wt++)
        {
            int notTake = dp[i - 1][wt];
            int take = -1e9;
            if (nums[i] <= wt)
            {
                take = val[i] + dp[i - 1][wt - nums[i]];
            }
            dp[i][wt] = max(take, notTake);
        }
    }
    return dp[n - 1][maxi];
}



// Space optimization 


int main()
{
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter bag capacity: ";
    cin >> capacity;

    vector<int> nums(n), val(n);
    cout << "Enter weights: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

     if (capacity == 0) {
        cout << "Maximum value (Memoization): 0" << endl;
        cout << "Maximum value (Tabulation): 0" << endl;
        return 0;
    }

    // Memoization
    vector<vector<int>> dpMemo(n, vector<int>(capacity + 1, -1));
    int memoResult = knapSack(n - 1, capacity, nums, val, dpMemo);
    cout << "Maximum value (Memoization): " << memoResult << endl;

    // Tabulation
    vector<vector<int>> dpTab(n, vector<int>(capacity + 1, 0));
    int tabResult = knapSackTabulation(nums, val, dpTab, capacity);
    cout << "Maximum value (Tabulation): " << tabResult << endl;

    // Display Tabulation DP Table
    cout << "DP Table (Tabulation):" << endl;
    for (const auto& row : dpTab) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}

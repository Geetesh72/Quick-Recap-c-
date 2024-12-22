/*
again here is infinite suppy  


*/






#include <bits/stdc++.h>
using namespace std;


int unbounded(int i , int wt , vector<int>&nums,vector<int>&values , vector<vector<int>>&dp){
    if(i==0){
        if(nums[0]<=wt){
            return values[0]*(wt/nums[0]); // this is most important part
        }
        return 0;
    }
    if(dp[i][wt]!=-1){
        return dp[i][wt];
    }
    int notTake  = unbounded(i-1,wt,nums,values, dp);
    int take = INT_MIN;
    if(nums[i]<=wt){
        take = values[i] + unbounded(i,wt-nums[i],nums,values,dp);
    }
    return dp[i][wt] = max(take,notTake);
}

int unboundedTabulation (int wt , vector<int>&nums, vector<int>&values , vector<vector<int>>&dp){
    int n = nums.size();
    for(int i  = 0;i<=wt;i++){
        dp[0][i] = values[0]*(i/nums[0]);
    }

    for(int i = 1;i<n;i++){
        for(int j = 0;j<=wt;j++){
            int notTake  = dp[i-1][j];
            int take = INT_MIN;
            if(nums[i]<=j){
                take = values[i]+dp[i][j-nums[i]];
            }
            dp[i][j]=max(take,notTake);
        }
    }
    return dp[n-1][wt];
}
int main()
{
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter capacity of the knapsack: ";
    cin >> capacity;

    vector<int> nums(n), values(n);
    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++) cin >> values[i];

    // Recursive DP
    vector<vector<int>> dpRecursive(n, vector<int>(capacity + 1, -1));
    int maxValueRecursive = unbounded(n - 1, capacity, nums, values, dpRecursive);
    cout << "Maximum Value (Recursive): " << maxValueRecursive << endl;

    // Tabulation DP
    vector<vector<int>> dpTabulation(n, vector<int>(capacity + 1, 0));
    int maxValueTabulation = unboundedTabulation(capacity, nums, values, dpTabulation);
    cout << "Maximum Value (Tabulation): " << maxValueTabulation << endl;

    // Display DP Table (Tabulation)
    cout << "DP Table (Tabulation):" << endl;
    for (const auto &row : dpTabulation) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
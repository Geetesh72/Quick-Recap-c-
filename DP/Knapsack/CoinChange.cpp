#include <bits/stdc++.h>
using namespace std;
/*


*/
// tc exponential of recursion
// sc also greater than >>>>>>>>>>>O(n)
int coinChangeII(int i, int target, vector<int> &nums, vector<vector<int>> &dp)
{
    // we are going n-1 -------->0
    if (i == 0)
    {
        return target % nums[i] == 0;
    }
    if (dp[i][target] != -1)
    {
        return dp[i][target];
    }

    int notTake = coinChangeII(i - 1, target, nums, dp);
    int take = 0;
    if (nums[i] <= target)
    {
        take = coinChangeII(i, target - nums[i], nums, dp);
    }
    return dp[i][target] = take + notTake;
}

int coinChangeTabulation(int target, vector<int> &nums, vector<vector<int>> &dp)
{
    int n = nums.size();
    for (int T = 0; T <= target; T++)
    {
        dp[0][T] = (T % nums[0] == 0);
    }

    for (int i = 1; i < n; i++)
    {
        for (int T = 0; T <= target; T++)
        {
            int notTake = dp[i - 1][T];
            int take = 0;
            if (nums[i] <= T)
            {
                take = dp[i][T - nums[i]];
            }
            dp[i][T] = take + notTake;
        }
    }
    return dp[n - 1][target];
}

int main()
{
    int n, target;
    cout << "Enter the number of coin denominations: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the coin denominations: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter the target amount: ";
    cin >> target;

    // Memoization Approach (Optional, for Testing)
    vector<vector<int>> dpMemo(n, vector<int>(target + 1, -1));
    int memoResult = coinChangeII(n - 1, target, nums, dpMemo);
    cout << "Number of combinations (Memoization): " << memoResult << endl;

    // Tabulation Approach
    vector<vector<int>> dpTab(n, vector<int>(target + 1, 0));
    int tabResult = coinChangeTabulation(target, nums, dpTab);
    cout << "Number of combinations (Tabulation): " << tabResult << endl;

    // Display DP Table (Tabulation)
    cout << "DP Table (Tabulation):" << endl;
    for (const auto &row : dpTab)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
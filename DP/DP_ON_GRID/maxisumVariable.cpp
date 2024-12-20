#include <bits/stdc++.h>
using namespace std;

/*
variable starting point and variable ending point
You're calculating the maximum path sum in a matrix,
 where you can start from any element in the first row and move to the last row. At each step
 , you can move either directly downward, diagonally left-down, or diagonally right-down.
*/

int maxiSum(int i, int j, vector<vector<int>> &nums, vector<vector<int>> &dp)
{
    if (j < 0 || j >= nums[0].size())
        return -1e9;
    if (i == 0)
    {
        return nums[i][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int up = nums[i][j] + maxiSum(i - 1, j, nums, dp);
    int leftup = nums[i][j] + maxiSum(i - 1, j - 1, nums, dp);
    int rightup = nums[i][j] + maxiSum(i - 1, j + 1, nums, dp);
    return dp[i][j] = max(up, max(leftup, rightup));
}

int maxiSumTabulation(int n, int m, vector<vector<int>> &nums, vector<vector<int>> &dp)
{
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = nums[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = nums[i][j] + dp[i - 1][j];
            int leftup = (j - 1 >= 0) ? nums[i][j] + dp[i - 1][j - 1] : -1e9;
            int rightup = (j + 1 < m) ? nums[i][j] + dp[i - 1][j + 1] : -1e9;
            dp[i][j] = max(up, max(leftup, rightup));
        }
    }
    return *max_element(dp[n - 1].begin(), dp[n - 1].end());
}

int main()
{
    int n, m;
    cout << "Enter number of rows and columns of the matrix: ";
    cin >> n >> m;

    vector<vector<int>> nums(n, vector<int>(m));
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> nums[i][j];
        }
    }

    vector<vector<int>> dpMemo(n, vector<int>(m, -1));
    int resultMemo = INT_MIN; // To store the result from memoization
    for (int j = 0; j < m; j++)
    {
        resultMemo = max(resultMemo, maxiSum(n - 1, j, nums, dpMemo));
    }
    cout << "\nMaximum Path Sum (Memoization): " << resultMemo << endl;

    // Tabulation approach
    vector<vector<int>> dpTab(n, vector<int>(m, 0));
    int resultTab = maxiSumTabulation(n, m, nums, dpTab);
    cout << "Maximum Path Sum (Tabulation): " << resultTab << endl;

    return 0;
}
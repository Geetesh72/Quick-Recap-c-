#include <bits/stdc++.h>
using namespace std;

int uniquePath(int i, int j, vector<vector<int>> &nums, vector<vector<int>> &dp)
{
    if (i >= 0 && j >= 0 && nums[i][j] == -1)
        return 0;
    if (i == 0 && j == 0)
    {
        return 1;
    }
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != 0)
    {
        return dp[i][j];
    }
    int left = 0;
    int up = 0;
    left = uniquePath(i - 1, j, nums, dp);
    up = uniquePath(i, j - 1, nums, dp);
    return dp[i][j] = left + up;
}
// tabulation
int uniquePathTabulation(int n, int m, vector<vector<int>> &nums, vector<vector<int>> &dp)
{
    dp[0][0] = nums[0][0] == -1 ? 0 : 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (nums[i][j] == -1)
            {
                dp[i][j] = 0;
                continue;

            }
            if (i == 0 && j == 0)
                {
                    continue;
                }
            int left = 0;
            int up = 0;
            if (i > 0)
                up = dp[i - 1][j];
            if (j > 0)
                left = dp[i][j - 1];
            dp[i][j] = up + left;
        }
    }
    return dp[n - 1][m - 1];
}
void print(vector<vector<int>> &nums)
{
    int n = nums.size();
    int m = nums[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nums(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> nums[i][j];
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    cout << endl
         << "Input Matrix:" << endl;
    print(nums);
    int memoResult = uniquePath(n - 1, m - 1, nums, dp);
    cout << "\nMemoization Result: " << memoResult << endl;
    vector<vector<int>> dpTab(n, vector<int>(m, 0)); // Separate dp for tabulation
    int tabResult = uniquePathTabulation(n, m, nums, dpTab);
    cout << "Tabulation Result: " << tabResult << endl;

    return 0;
}
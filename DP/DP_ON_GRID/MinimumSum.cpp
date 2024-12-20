#include <bits/stdc++.h>
using namespace std;
int minimumSum(int i, int j, vector<vector<int>> &nums, vector<vector<int>> &dp) {
    if (i == 0 && j == 0) return nums[i][j]; // Base case
    if (i < 0 || j < 0) return INT_MAX;     // Out of bounds
    if (dp[i][j] != -1) return dp[i][j];    // Already computed

    int up = minimumSum(i - 1, j, nums, dp);
    int left = minimumSum(i, j - 1, nums, dp);

    // Only add nums[i][j] if `up` or `left` is not `INT_MAX`
    if (up != INT_MAX) up += nums[i][j];
    if (left != INT_MAX) left += nums[i][j];

    return dp[i][j] = min(up, left);
}

// Tabulations
int minimumSumTabulation(int n, int m, vector<vector<int>> &nums, vector<vector<int>> &dp)
{
    dp[0][0] = nums[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                continue;
            int left = INT_MAX;
            int up = INT_MAX;
            if (i > 0)
            {
                up = 0 + nums[i][j] + dp[i - 1][j];
            }
            if (j > 0)
            {
                left = nums[i][j] + dp[i][j - 1];
            }
            dp[i][j] = min(up, left);
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

// out put table
void print2(vector<vector<int>> &matrix)
{
    for (auto &row : matrix)
    {
        for (auto &val : row)
            cout << val << " ";
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
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << endl
         << "Input Matrix:" << endl;
    print(nums);
    int memoResult = minimumSum(n-1 , m-1 , nums, dp);
    cout << "\nMemoization Result: " << memoResult << endl;
    print(dp);

    vector<vector<int>> dpTab(n, vector<int>(m, 0)); // Separate dp for tabulation
    int tabResult = minimumSumTabulation(n, m, nums, dpTab);
    cout << "Tabulation Result: " << tabResult << endl;
    print(dpTab);

    return 0;
}
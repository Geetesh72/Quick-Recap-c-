/*
about question have to sum max element with picking adjecet elemenet
standard case of pick or not pick
base case explantion
if index is zero that we wont pick index 1 cause that meke it adjcent
so what the value at index 0 we will take it
*/
#include <bits/stdc++.h>
using namespace std;

int sumAdj(int i, vector<int> &nums, vector<int> &dp)
{
    int pick = 0;
    if (i == 0)
    {
        return nums[i];
    }
    if (i < 0)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    // picking
    if (i > 1)
    {

        pick = nums[i] + sumAdj(i - 2, nums, dp);
    }
    int notPick = sumAdj(i - 1, nums, dp);
    return dp[i] = max(pick, notPick);
}

// bottom up
int sumBottomup(int n, vector<int> &nums, vector<int> &dp)
{
    dp[0] = nums[0];
    if (n == 1)
        return dp[0];
    int pick = 0;
    for (int i = 1; i < n; i++)
    {
        if (i > 1)
        {
            pick = nums[i] + dp[i - 2];
        }
        int notPick = dp[i - 1];
        dp[i] = max(notPick, pick);
    }
    return dp[n - 1];
}

int sumSpace(int n, vector<int> &nums)
{
    int prev1 = nums[0];
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int pick = nums[i] + prev2;
        int notPick = prev1;
        int curr = max(pick, notPick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> dp(n + 1, -1);
    cout << sumAdj(n - 1, nums, dp);
    cout << endl
         << endl;
    cout << sumBottomup(n, nums, dp);
    cout << endl
         << endl;
    cout << sumSpace(n, nums);

    return 0;
}


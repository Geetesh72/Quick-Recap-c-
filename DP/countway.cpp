#include <bits/stdc++.h>
using namespace std;
/*
understand the Pattern
how do i understand dp problem /
here is the some types

1-> count the total no of ways
2-> min or max

try possible  all ways
or they ask to the best ways
*/

/* Shortcut for solving the question

1-> try to represent the problem in term of index
2-> do all possible stuffs on that index according to the problem statement
if question says ->>> SUM ALl STUFF -> then sum
if question says ->>> FIND MINIMIN -> then find mini
same for the max



*/

// Question breakdowm
/*
n is give i treat as index 0 -> n


*/

int climingStair(int n)
{
    int secJump = 0;
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
        return 1;
    int oneJump = climingStair(n - 1);
    if (n > 1)
    {
        secJump = climingStair(n - 2);
    }
    return secJump + oneJump;
}
int memoClimbing(int n, vector<int> &dp)
{
    int secJump = 0;
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }
    int oneJump = memoClimbing(n - 1, dp);
    if (n > 1)
    {
        secJump = memoClimbing(n - 2, dp);
    }
    return dp[n] = oneJump + secJump;
}

// space otimized
int spaceClimbling(int n)
{
    int prev2 = 1;
    int prev1 = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev2 + prev1;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);

    cout << climingStair(n);
    cout << endl
         << endl;
    cout << memoClimbing(n, dp);
    cout << endl
         << endl;
    cout << spaceClimbling(n);

    return 0;
}
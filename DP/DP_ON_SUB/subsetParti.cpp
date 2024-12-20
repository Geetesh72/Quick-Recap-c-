/*
logic :
exactly 2 subset = s1 = s2 = total/2;
          s
         /  \
        /    \
       s2     s1

if s = odd not possible
if even

*/

#include <bits/stdc++.h>
using namespace std;
// subset sum equal to k
bool subsetSum(int i, vector<int> &nums, vector<vector<int>> &dp, int target)
{
    if (target == 0)
    {
        return true;
    }
    if (i == 0)
    {
        return target == nums[i]; // note here you did mistake
    }
    if (dp[i][target] != -1)
    {
        return dp[i][target];
    }

    bool notTake = subsetSum(i - 1, nums, dp, target);
    bool takeit = false;
    if (target >= nums[i])
    {

        takeit = subsetSum(i - 1, nums, dp, target - nums[i]);
    }

    return dp[i][target] = notTake || takeit;
}

bool subsetSumTabulation(vector<int> &nums, vector<vector<bool>> &dp, int target)
{
    /*
    any moment target is zero
    then what are the possiblities of index ask yourself
    */
    // base case
    // Base case: If target is 0, any subset can form it by taking no elements
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    // Base case: If only the first element is considered
    if (nums[0] <= target)
    {
        dp[0][nums[0]] = true;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            bool notTake = dp[i - 1][j];
            bool takeit = false;
            if (j >= nums[i])
            {
                takeit = dp[i - 1][j - nums[i]];
            }
            dp[i][j] = notTake || takeit;
        }
    }
    return dp[n - 1][target];
}

int main()
{

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int k = 0;
    for(int i = 0;i<n;i++){
        k+=nums[i];
    }
    if(k%2==0){
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    // Memoization
    bool memoResult = subsetSum(n - 1, nums, dp, k/2);
    cout << "Subset with sum " << k << " exists (Memoization): " << (memoResult ? "Yes" : "No") << endl;
    vector<vector<bool>> dptab(n, vector<bool>(k + 1, false));
    // Tabulation
    bool tabResult = subsetSumTabulation(nums, dptab, k/2);
    cout << "Subset with sum " << k << " exists (Tabulation): " << (tabResult ? "Yes" : "No") << endl;


    }

    else{
        cout<<"Subset have odd sum cannot divide to for equal subset "<<" "<<"ZERO"  ;
    }

    return 0;
}
/*
Darivation of subset sum
if we check for a target = k
we can derive if every possible target between (i & k) is tick / not tick
means can acheived or not acheived

*/

// important question 
// problem
/*
abs diff between the two subset sub is as minimum as possible
 {3 ,2,7}
 s1 can 0 , 
 s1 can 12 all elements 
*/

//
/*
logic

s1 0 , 2 ,3,5,7,9,10,12 this i see from last row of dp table 
s2 12, 10,9,7,5,3,2,0
abs 12,8,6,2,2,6,8,12  minimum is 2 

// logic

*/

#include <bits/stdc++.h>
using namespace std;

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
    // int tolSum = accumulate(nums.begin(), nums.end(), 0);
    int tolSum = 0;
    for(int i  = 0;i<n;i++){
        tolSum+=nums[i];
    }

    vector<vector<int>>dp(n,vector<int>(tolSum+1,0));
 
    for(int i = 0;i<n;i++){
        dp[i][0] = true;

    }
    if(nums[0]<=tolSum){
        dp[0][nums[0]]=true; // First element can form a subset if it's <= tolSum
    }
    for(int i =1;i<n;i++){
        for(int j = 1;j<=tolSum;j++){
            bool notTake = dp[i-1][j];
            bool takeIt = false;
            if(nums[i]<=j){
                takeIt = dp[i-1][j-nums[i]];
            }
            dp[i][j]  = takeIt|| notTake;
        }
    }
    // dp[n-1][tolSum]; this will tell me ans 
    int mini = 1e9 ;
    for(int s1 = 0 ;s1<=tolSum/2;s1++){
        if(dp[n-1][s1]==true){  // If subset sum `s1` is achievable
            mini = min(mini,abs((tolSum-s1)-s1)); //Calculate and update minimum difference
        }
    }
    cout<<mini;
    
    return 0;
}

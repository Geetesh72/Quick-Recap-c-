/*
Important also be careFull cause new thing to learn
*/
#include <bits/stdc++.h>
using namespace std;
int frogKJump (int i , vector<int>&nums,vector<int>&dp,int k){
    // int jumpEnergy= 0;
    if(i==0)
    {
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int energy = INT_MAX;
    // complime all possible k jump in for loop so that frog can jump any where along with energy spend
    for(int j  = 1;j<=k;j++){
        if(i-j>=0){
        int jumpEnergy = abs(nums[i]-nums[i-j])+frogKJump(i-j,nums,dp,k);
          energy = min(energy,jumpEnergy);
        }

    }
    return dp[i] = energy;
}

/* 
O(n)*k

*/
// now Bottom up 
int frogKJumpBottomUp (int n , vector<int>&dp , vector<int>&nums, int k ){
    dp[0]=0;
    for(int i =1;i<n;i++){
        int energy = INT_MAX;
        for(int j = 1;j<=k;j++){
            if(i-j>=0){
                int jumpEnergy = abs(nums[i-j]-nums[i])+dp[i-j];
                energy = min(energy,jumpEnergy);
            }
        }
        dp[i]=energy;
    }
    return dp[n-1];
}

// space optimization
/*
prev1 
prev2 

 */
int frogKJumpWithspace (int n , vector<int>&nums,int k ){
    int prev1 = 0;
    int prev2 = 0;
    for(int i = 1;i<n;i++){
        int energy = 0;
        for(int j = 1 ;j<=k;j++){
            int curr = abs(nums[i-j]-nums[i])+prev1;
            energy = min(energy,curr);
            prev2 = prev1;
            prev1  = curr;

        }

    }
    return prev1;
}


int main()
{
    int n ,k ;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>dp(n+1,-1);
    cout<<frogKJump(n-1,nums,dp,k);
    cout<<endl<<endl;
    cout<<frogKJumpBottomUp(n,dp,nums,k);
    cout<<endl<<endl;
    cout<<frogKJumpWithspace(n,nums,k);


    return 0;
}
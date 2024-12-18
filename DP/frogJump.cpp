/*
Question understanding
10 20,30,10,40
he can jump one place or second place

why greedy fails
30 10 60 50 60 20
*/

/*

1-> try to represent the problem in term of index
2-> do all possible stuffs on that index according to the problem statement
if question says ->>> SUM ALl STUFF -> then sum
if question says ->>> FIND MINIMIN -> then find mini
same for the max
*/
#include <bits/stdc++.h>
using namespace std;

int jumpEnergy(int i,vector<int>&nums,vector<int>&dp ){
    int secJump = INT_MAX;
    if(i==0){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i]; 
    }
    int firstJump = jumpEnergy(i-1,nums,dp) + abs(nums[i]-nums[i-1]);
    if(i>1){
        secJump = jumpEnergy(i-2,nums,dp) + abs(nums[i]-nums[i-2]);
    }
    return  dp[i] = min(firstJump,secJump);

}
//  BOTTOM up 
/*
rule look the base case find realtion of base case in term of memoiozed array 
so i can se from the base of the recursion dp[0] =0
*/

// let start 
int jumpEnergyBottomup(int n , vector<int>&nums,vector<int>&dp){
    dp[0]=0;
    int secondJump = INT_MAX;
    
    for(int i = 1;i<n;i++){
        int firstJump = abs(nums[i]-nums[i-1]) + dp[i-1];
        if(i>1){
            secondJump = abs(nums[i]-nums[i-2])+dp[i-2];
            
        }
        dp[i] = min(firstJump,secondJump);

    }
    return dp[n-1];
}

// space optimization 
/*
key idea is 
prev2 
prev1 
curr 

*/

int jumpWithSpace(int n , vector<int>&nums){
    int prev2 = 0;
    int prev1 = 0;
    int secJump = INT_MAX;
    for(int i =1;i<n;i++ ){
        int firstJump = abs(nums[i]-nums[i-1])+prev1;
        if(i>1){
            secJump = abs(nums[i]-nums[i-2])+prev2;
        }
        int curr = min(firstJump,secJump);
        prev2 = prev1;
        prev1  = curr;


    }
    return prev1;
}



int main()
{
    int n ;
    cin>>n;
    vector<int>nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>dp(n+1,-1);
    cout<<jumpEnergy(n-1,nums,dp);
    cout<<endl<<endl;
    cout<<jumpEnergyBottomup(n,nums,dp);
    cout<<endl<<endl;
    cout<<jumpWithSpace(n,nums);




    return 0;
}
#include <bits/stdc++.h>
using namespace std;

/*
About question 
on top left cell -> have to go bottom right cell with right and down movement allowed 


(0,0)->    (m-1,n-1)

in term of index i and j cause having row and col 
*/ //
// base case 
// if(i==0 && j==0 )return 1  we found one way

// if(i<0 || j<0) return 0;


int uniquePaths(int i , int j , vector<vector<int>>&nums,vector<vector<int>>&dp){
    if(i==0 && j==0){
        return 1;
    }
    if(i<0 || j<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int left = uniquePaths(i-1 , j,nums,dp);
    int up = uniquePaths(i,j-1,nums,dp);
    return dp[i][j] = left+up;


}

/*Steps tp memoiozation to tabulation 
look at the base case 
try to formulate some information that give intail value of dp array 
the copy the recurrence relation 

*/

int uniquePathsBottomUp(int n , int m , vector<vector<int>>&nums,vector<vector<int>>&dp){
    dp[0][0] = 1;
    int left  = 0,up = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(i==0 &&j==0)dp[0][0]=1;
            else{
                if(i>0)  left  = 0 + dp[i-1][j];
                if(j>0)  up = 0 +dp[i][j-1];
                dp[i][j] = left+up;
            }

        }
    }
    return dp[n-1][m-1];
}
// space optimization





void print(vector<vector<int>>&nums){
    int n = nums.size();
    int m = nums[0].size();
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }
}


// space optimization 
int uniquePathSpace(vector<vector<int>>&nums){
    int n = nums.size();
    int m = nums[0].size();
    vector<int>prev(m,0);
    for(int i = 0;i<n;i++){
        vector<int>curr(m,0);
        for(int j = 0;j<m;j++)
        {
            if(i==0 && j==0 )curr[j]=0;
            else {
                int left = 0;
                int up = 0;
                if(i>0)up = prev[j];
                if(j>0)left = curr[j-1];
                curr[j] = left+up;
            }

        }
        prev = curr;
    }
    return prev[m-1];

}
int main()
{
    int n , m;
    cin>>n>>m;
    vector<vector<int>>nums(n,vector<int>(m));
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>nums[i][j];
        }
    }
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    cout<<endl;
    print(nums);


    return 0;
}
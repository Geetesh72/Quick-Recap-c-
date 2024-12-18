/*
Recursion ->Memoiozation-> Tabulation -> Space Optimizations :


//
 Fibbonacci No
 f(n){
 if(n<=1){
 return n
 }
 return f(n-1) + f(n-2);
 }


 memoization -> tend to store the value of subproblems in some map / table


step for recursion to memoiozation

step 1 : Create dp[n+1]
step 2 : dp[n] = f(n-1) + f(n-2);
step 3 : check if(dp[n]!=-1) why i wont return this make stop recursion to recompute the further digging to recursion tree

*/



#include <bits/stdc++.h>
using namespace std;


// space optimized 





int fibo(int n , vector<int>&dp){
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n] = fibo(n-1,dp)+fibo(n-2,dp);
    return dp[n];
}
int spaceOptimized(int n ){
 int prev2 = 0;
 int prev1 = 1;
 for(int i = 2;i<=n;i++){
    int curr = prev2+prev1;
    prev2 = prev1;
    prev1 = curr;
 }
 return prev1;
}
int main()
{
    int n ;
    cin>>n;
    vector<int>dp(n+1,-1);
    cout<<fibo(n,dp);
    cout<<endl<<endl;
    cout<<spaceOptimized(n);


    // space optimized 
    // int prev2  = 0;
    // int prev1 = 1; 
    // for(int i = 2;i<=n;i++){
    //     int curr1 = prev1+prev2; // this is recurrence relation 
    //     prev2  = prev1;
    //     prev1 = curr1;
        
    // }
    // cout<<prev1;




    return 0;
}

/*

precomputed are problem take  constant time 
so at max recursive depth is O(n);

So TC -> O(N)
   SC -> O(n) + O(n);




*/

// Now Tabulation  -> Bottom Up 
/*
base case to the required 
steps 
step 1 : Intilize with same size array 
step 2 : look at the base case then try to extract intials index value from base case like 
          dp[0] = 0
          dp[1] = 1
step 3 : paste the recurrence relation 

tc O(n)
sc -> O(n) we remove the stack space that use in recursion 

*/


//  space optimization 

/*
first place prev2 to prev1 
then prev1 to curr 


note that : we have to return prev1 because it holds our ans 
*/



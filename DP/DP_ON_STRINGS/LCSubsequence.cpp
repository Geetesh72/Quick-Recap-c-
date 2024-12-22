/*Introduction
s = abc so no of subsequence is 2 ^3 = 8
*/

/*common things of Longest Common SubSequence
some recurrence
express the indices of two string i , j
exlore all possibilities
take the best among them

eg :
f(2,2) ------------> LCS of str1 (0,2)
       ------------> LCS of str2 (0,2)
f(index of str1 , index of str2)
// Do comparison Characterwise 

*/

#include <bits/stdc++.h>
using namespace std;


/*Approach to problem
    acd / ced  --> have to find longest common subsequence 
    we dealed that we have two pointer for both strings
    so if the s[idx1] == p [idx2] then count 1 
    
    if they dont match  like this ec / ce we can se we can draw the lcs 
    but we have to explore all path by halting on of the index 
    like ec movig idx1 so that p'string 'c' will match to e of index 2 
    
    likewise halting idx1 do the same with matching c with ec's c 
    

    how to write recursive function 0 + max(f(idx1-1,idx2),f(idx1,idx2-1))

TC 2^n * 2^m

*/

/*HOW TO SOLVE 
BASE CASE 
 
 THEN 

 IS MATCHED 

 NOT MATCHED 

 RETURN 

*/

int longestCommon(int i , int j , string &s , string&t,vector<vector<int>>&dp){
    if(i==0 || j==0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s[i-1]==t[j-1]){
        return dp[i][j] = 1 + longestCommon(i-1,j-1,s,t,dp);
    }
    return dp[i][j] = max(longestCommon(i-1,j,s,t,dp),longestCommon(i,j-1,s,t,dp));
    /*
    TC O(NxM)
    SC O(NXM)+O(N+M)
    */

}

/*
Index Shifting:
To simplify handling edge cases and avoid accessing out-of-bound indices, we shift the indices by 1. This means we treat the string indices as starting from 1 instead of 0.

Loop Runs from 1 to n (Inclusive):
After shifting, the loop for calculating the LCS runs from 1 to n for the first string and 1 to m for the second string. This ensures we cover the entire string while maintaining the shifted index.

Declaring Size as (n+1) and (m+1):
The DP table (dp) is declared with dimensions (n+1) x (m+1) to accommodate the shifted indices. This extra row and column represent the base case where either string is empty.

Returning dp[n][m]:
After filling the DP table, the result is stored in dp[n][m], which represents the LCS length for the full strings. Since n corresponds to the last index of the shifted table, it effectively points to the original string index n-1.

Access in Shifted Table:

Original indices: s[i-1] and t[j-1]
Shifted table: Corresponds to dp[i][j].
Key Adjustments:

Base cases are defined at dp[i][0] = 0 (string t is empty) and dp[0][j] = 0 (string s is empty).
Matching condition:
If s[i-1] == t[j-1], then dp[i][j] = 1 + dp[i-1][j-1].
Non-matching condition:
If s[i-1] != t[j-1], then dp[i][j] = max(dp[i-1][j], dp[i][j-1]).
Advantages of Index Shifting:

Eliminates the need to manually handle negative indices.
Ensures consistent logic for base cases and recurrence relations.
Results in cleaner and more readable code.



*/

// TABULATION 
int longestTabular(string &s, string&t, vector<vector<int>>&dp){
    int n = s.length();
    int m =t.length();
    for(int i = 0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j  = 0;j<=m;j++){
        dp[0][j]=0;
    }

    for(int i = 1;i<=n;i++ ){ // why we are going till equal to n becuse we shift the index by 1 
        for(int j = 1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]  = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];

}


int main()
{
    string s, t;
    cout << "Enter the first string: ";
    cin >> s;
    cout << "Enter the second string: ";
    cin >> t;

    int n = s.length();
    int m = t.length();

    // Memoization
    vector<vector<int>> dpMemo(n + 1, vector<int>(m + 1, -1));
    int lcsMemo = longestCommon(n, m, s, t, dpMemo);
    cout << "LCS Length (Memoization): " << lcsMemo << endl;

    // Tabulation
    vector<vector<int>> dpTab(n + 1, vector<int>(m + 1, 0));
    int lcsTab = longestTabular(s, t, dpTab);
    cout << "LCS Length (Tabulation): " << lcsTab << endl;

    // Print the DP table for tabulation
    cout << "DP Table (Tabulation):" << endl;
    for (const auto &row : dpTab) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
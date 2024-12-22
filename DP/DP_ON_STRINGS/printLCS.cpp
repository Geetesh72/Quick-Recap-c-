#include <bits/stdc++.h>
using namespace std;

/*
  c e d
0 0 0 0
0 0 0 0  -> a
0 1 1 1  -> c 
0 1 1 2  -> d


*/

string printLongestSequence(string &s, string&t, vector<vector<int>>&dp){
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

    // important
    int len  = dp[n][m];
    string ans ="";
    for(int i = 0;i<len;i++){
        ans+="$";
    }
    int index = len-1;
    int i = n , j = m;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            ans[index] = s[i-1];
            index--;
            i--,j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;

        }
        else{
            j--;
        }
    }
    return ans;
    

}

int main()
{
    string s = "abcde";
    string t = "ace";
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    string result = printLongestSequence(s, t, dp);

    cout << "Longest Common Subsequence: " << result << endl;

    return 0;
}
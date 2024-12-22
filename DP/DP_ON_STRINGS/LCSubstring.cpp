#include <bits/stdc++.h>
using namespace std;



int lcSubstring(string &s ,string &t , vector<vector<int>>&dp)
{
    int n = s.length();
    int m = t.length();
    for(int i = 0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int j = 0;j<=m;j++){
        dp[0][j]=0;
    }
    int ans= 0;
    for(int i= 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                ans = max(ans,dp[i][j]);
            }else{
                dp[i][j]=0;
            }
        }
    }
    return ans;
}


int main()
{
    string s = "geeteesh";
    string t = "sonigeet";
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int length = lcSubstring(s, t, dp);

    cout << "Length of Longest Common Substring: " << length << endl;

    return 0;
}
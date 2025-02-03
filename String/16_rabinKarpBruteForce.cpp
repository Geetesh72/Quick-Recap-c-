#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Brute-force string matching
vector<int> bruteForceStringMatching(const string &s, const string &p)
{
    int n = s.length();
    int m = p.length();
    vector<int> ans;

    for (int i = 0; i <= n - m; i++)
    {
        if (s.substr(i, m) == p)
        { // Direct comparison
            ans.push_back(i);
        }
    }

    return ans;
}
vector<int>bruteForceMatching(string &s,string &p){
    int n = s.length();
    int m = p.length();
    vector<int>ans;
    for(int i = 0;i<=n-m;i++){
        int j = 0;
        while(j>m && s[i+j]==p[j]){
            j++;
        }
        if(j==m){
            ans.push_back(i);
        }
    }
    return ans;
}

int main()
{
    int t;
    cout << "Enter Number of test cases: ";
    cin >> t;
    cin.ignore(); // Fixes newline issue

    while (t--)
    {
        string text, pattern;
        cout << "Enter text: ";
        getline(cin, text);
        cout << "Enter pattern: ";
        getline(cin, pattern);

        vector<int> matches = bruteForceStringMatching(text, pattern);

        if (matches.empty())
        {
            cout << "Pattern not found\n";
        }
        else
        {
            cout << "Pattern found at indices: ";
            for (int index : matches)
            {
                cout << index << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

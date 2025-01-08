#include <bits/stdc++.h>
using namespace std;

/*
Problem Description:
Given two strings `s` and `t`, find the minimum window in `s` that contains all the characters in `t`.
If there is no such window, return an empty string.

Examples:
1. Input: s = "ADOBECODEBANC", t = "ABC"
   Output: "BANC"
   Explanation: The minimum window substring that contains "A", "B", and "C" is "BANC".

2. Input: s = "a", t = "a"
   Output: "a"
   Explanation: The minimum window substring that contains "a" is "a".

3. Input: s = "a", t = "aa"
   Output: ""
   Explanation: There's no substring of `s` containing "aa".
*/

// Brute Force Approach
string windowSubstring(string &s, string &t)
{
    int n = s.length();
    int m = t.length();
    int minLen = INT_MAX;
    int sIdx = -1;

    for (int i = 0; i < n; i++)
    {
        vector<int> hashMap(256, 0);
        for (char c : t)
        {
            hashMap[c]++;
        }

        int cnt = 0;
        for (int j = i; j < n; j++)
        {
            if (hashMap[s[j]] > 0)
            {
                cnt++;
            }
            hashMap[s[j]]--;

            if (cnt == m)
            {
                if (j - i + 1 < minLen)
                {
                    minLen = j - i + 1;
                    sIdx = i;
                }
                break;
            }
        }
    }

    return sIdx == -1 ? "" : s.substr(sIdx, minLen);
}

// Optimal Approach using Sliding Window
string windowSub(string &s, string &t)
{
    int n = s.length();
    int m = t.length();
    vector<int> hashMap(256, 0);

    // Populate the hashmap with characters of `t`
    for (char c : t)
    {
        hashMap[c]++;
    }

    int minLen = INT_MAX;
    int sIdx = -1;
    int cnt = 0; // Number of characters matched
    int right = 0, left = 0;

    while (right < n)
    {
        // Include the current character in the window
        if (hashMap[s[right]] > 0)
        {
            cnt++;
        }
        hashMap[s[right]]--;

        // Try to shrink the window while maintaining the condition
        while (cnt == m)
        {
            if (right - left + 1 < minLen)
            {
                minLen = right - left + 1;
                sIdx = left;
            }

            hashMap[s[left]]++;
            if (hashMap[s[left]] > 0)
            {
                cnt--;
            }
            left++;
        }

        right++;
    }

    return sIdx == -1 ? "" : s.substr(sIdx, minLen);
}

int main()
{

    int t;
    cout << "Enter no of test case: " << endl;
    cin>>t;
    while (t--)
    {
        string s, t;
        cout << "Enter the main string (s): ";
        cin >> s;
        cout << "Enter the target string (t): ";
        cin >> t;

        cout << "\nResults:\n";
        cout << "Brute Force Result: " << windowSubstring(s, t) << endl;
        cout << "Optimal Sliding Window Result: " << windowSub(s, t) << endl;
    }

    return 0;
}

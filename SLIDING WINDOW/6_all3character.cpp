#include <bits/stdc++.h>
using namespace std;

/*
Problem Description:
Given a string `s` consisting of lowercase letters 'a', 'b', and 'c', 
count the number of substrings that contain at least one occurrence 
of all three characters.

Examples:
1. Input: s = "abcabc"
   Output: 10
   Explanation: Substrings satisfying the condition include:
   "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc", "abc".

2. Input: s = "aaacb"
   Output: 3
   Explanation: Substrings satisfying the condition include:
   "acb", "aab", "aaacb".
*/

// Brute Force Approach
int countSubstringsBruteForce(string &s) {
    int n = s.length();
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        int hashMap[3] = {0}; // To track occurrences of 'a', 'b', 'c'
        for (int j = i; j < n; j++) {
            hashMap[s[j] - 'a'] = 1; // Mark the character as seen
            if (hashMap[0] + hashMap[1] + hashMap[2] == 3) { // All characters found
                cnt += (n - j); // Add all substrings starting from `j` to the end
                break;
            }
        }
    }
    return cnt;
}

// Optimal Approach using Sliding Window
int countSubstringsOptimal(string &s) {
    int n = s.length();
    vector<int> lastSeen(3, -1); // Track the last seen index of 'a', 'b', 'c'
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        lastSeen[s[i] - 'a'] = i; // Update the last seen index for the current character
        if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
            cnt += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]}); // Add valid substrings
        }
    }
    return cnt;
}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        string s;
        cout << "\nEnter the string (s): ";
        cin >> s;

        // Calling the brute force and optimal functions
        int bruteForceResult = countSubstringsBruteForce(s);
        int optimalResult = countSubstringsOptimal(s);

        cout << "\nResults:\n";
        cout << "Brute Force Answer: " << bruteForceResult << endl;
        cout << "Optimal Answer: " << optimalResult << endl;
    }

    return 0;
}

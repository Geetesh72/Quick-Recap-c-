#include <bits/stdc++.h>
using namespace std;

/*
Problem Description:
Given a string `s` and an integer `k`, find the length of the longest substring 
that contains at most `k` distinct characters.

Examples:
1. Input: s = "abcba", k = 2
   Output: 3
   Explanation: The longest substring with at most 2 distinct characters is "bcb".

2. Input: s = "aa", k = 1
   Output: 2
   Explanation: The longest substring with at most 1 distinct character is "aa".
*/

// Brute Force Approach
int substring(string &s, int k) {
    int n = s.length();
    int maxi = 0;

    for (int i = 0; i < n; i++) {
        set<char> st; // To track distinct characters in the current substring
        for (int j = i; j < n; j++) {
            st.insert(s[j]); // Add the current character to the set
            if (st.size() <= k) {
                maxi = max(maxi, (j - i + 1)); // Update maximum length
            }
        }
    }
    return maxi;
}

// Optimal Approach using Sliding Window
int subString(string &s, int k) {
    int n = s.length();
    int right = 0, left = 0;
    unordered_map<char, int> umap; // To count the frequency of characters in the current window
    int maxi = 0;

    while (right < n) {
        umap[s[right]]++; // Add the character at the `right` index to the map

        // Shrink the window until there are at most `k` distinct characters
        while (umap.size() > k) {
            umap[s[left]]--;
            if (umap[s[left]] == 0) {
                umap.erase(s[left]); // Remove the character from the map if its count is 0
            }
            left++; // Move the left pointer forward
        }

        if (umap.size() <= k) {
            maxi = max(maxi, (right - left + 1)); // Update the maximum length
        }
        right++; // Move the right pointer forward
    }

    return maxi;
}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        int k;
        cout << "\nEnter the value of k: ";
        cin >> k;

        string s;
        cout << "Enter the string s: ";
        cin >> s;

        // Calling the brute force and optimal functions
        int bruteForce = substring(s, k);
        int optimalAns = subString(s, k);

        cout << "\nResults:\n";
        cout << "Brute Force Answer: " << bruteForce << endl;
        cout << "Optimal Answer: " << optimalAns << endl;
    }

    return 0;
}

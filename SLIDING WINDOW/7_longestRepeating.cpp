#include <bits/stdc++.h>
using namespace std;

/*
Problem Description:
Given a string `s` consisting of uppercase English letters and an integer `k`, 
you can change at most `k` characters in the string to any other character 
to form the longest substring with all characters being the same.

Return the length of such a substring.

Examples:
1. Input: s = "ABAB", k = 2
   Output: 4
   Explanation: Change both 'A's to 'B's or both 'B's to 'A's.

2. Input: s = "AABABBA", k = 1
   Output: 4
   Explanation: Change the second 'B' to 'A' to form "AABA".
*/

// Brute Force Approach
int longestRepeatingBruteForce(string &s, int k) {
    int n = s.length();
    int maxi = 0;

    for (int i = 0; i < n; i++) {
        unordered_map<char, int> umap;
        int maxFreq = 0; // To track the highest frequency character in the current substring

        for (int j = i; j < n; j++) {
            umap[s[j]]++; // Increment the frequency of the current character
            maxFreq = max(maxFreq, umap[s[j]]); // Update the maximum frequency

            int changes = (j - i + 1) - maxFreq; // Calculate the number of changes needed
            if (changes <= k) {
                maxi = max(maxi, j - i + 1); // Update the maximum length
            } else {
                break; // If changes exceed k, break out of the loop
            }
        }
    }
    return maxi;
}

// Optimal Approach using Sliding Window
int longestRepeatingOptimal(string &s, int k) {
    int n = s.length();
    int right = 0, left = 0;
    int maxi = 0, maxFreq = 0;
    vector<int> hashMap(26, 0); // Frequency count for characters 'A' to 'Z'

    while (right < n) {
        hashMap[s[right] - 'A']++; // Increment the frequency of the character at `right`
        maxFreq = max(maxFreq, hashMap[s[right] - 'A']); // Update the maximum frequency

        // Shrink the window if the number of changes exceeds `k`
        while ((right - left + 1) - maxFreq > k) {
            hashMap[s[left] - 'A']--; // Reduce the frequency of the character at `left`
            left++; // Move the left pointer
        }

        // Update the maximum length
        maxi = max(maxi, right - left + 1);
        right++;
    }
    return maxi;
}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        string s;
        int k;
        cout << "\nEnter the string (s): ";
        cin >> s;
        cout << "Enter the value of k: ";
        cin >> k;

        // Call both the brute force and optimal functions
        int bruteForceResult = longestRepeatingBruteForce(s, k);
        int optimalResult = longestRepeatingOptimal(s, k);

        cout << "\nResults:\n";
        cout << "Brute Force Answer: " << bruteForceResult << endl;
        cout << "Optimal Answer: " << optimalResult << endl;
    }

    return 0;
}

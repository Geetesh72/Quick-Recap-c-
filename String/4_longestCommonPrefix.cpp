#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
Given a vector of strings, find the longest common prefix among them. 
If there is no common prefix, return an empty string.

Approach 1: Optimized Approach (Sorting-Based)
1. Sort the vector of strings.
2. Compare the first and last strings in the sorted vector (smallest and largest lexicographically).
3. Traverse both strings and find the longest common prefix between them.
4. Return the common prefix.

Time Complexity: O(n * log(n) + k), where n is the number of strings and k is the length of the smallest string.
*/

// Optimized Approach: Sorting-Based
string longestCommonPrefOptimized(vector<string>& nums) {
    int n = nums.size();
    if (n == 0) return "";

    // Sort the array of strings
    sort(nums.begin(), nums.end());

    // Compare the first and last strings in the sorted array
    string s1 = nums[0];       // Smallest string (lexicographically)
    string s2 = nums[n - 1];   // Largest string (lexicographically)
    string ans = "";           // Resultant longest common prefix

    // Find the common prefix between the first and last strings
    int i = 0, j = 0;
    while (i < s1.length() && j < s2.length()) {
        if (s1[i] == s2[j]) {
            ans.push_back(s1[i]);
            i++;
            j++;
        } else {
            break;
        }
    }
    return ans;
}

/*
Approach 2: Brute Force
1. Start with the first string as the prefix.
2. Compare the prefix with every other string in the vector.
3. Trim the prefix character by character until it matches all strings.
4. Stop if the prefix becomes empty.

Time Complexity: O(n * m), where n is the number of strings and m is the length of the longest string.
*/

// Brute Force Approach
string longestCommonPrefBruteForce(vector<string>& nums) {
    int n = nums.size();
    if (n == 0) return "";
    
    string prefix = nums[0]; // Start with the first string as the prefix

    for (int i = 1; i < n; i++) {
        while (nums[i].find(prefix) != 0) { // Check if `prefix` is a prefix of the current string
            prefix = prefix.substr(0, prefix.length() - 1); // Remove the last character from the prefix
            if (prefix.empty()) return ""; // If prefix becomes empty, return ""
        }
    }
    return prefix;
}

int main() {
    int t; // Number of test cases
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        int n;
        cout << "Enter the number of strings: ";
        cin >> n;

        vector<string> nums(n);
        cout << "Enter the strings: ";
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        // Call both approaches and display results
        cout << "Longest Common Prefix (Optimized): " << longestCommonPrefOptimized(nums) << endl;
        cout << "Longest Common Prefix (Brute Force): " << longestCommonPrefBruteForce(nums) << endl;
    }

    return 0;
}

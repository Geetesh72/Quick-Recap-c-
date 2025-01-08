#include <bits/stdc++.h>
using namespace std;

// Brute Force Solution (O(n^2) complexity)
int longestSubstring(string &s) {
    int n = s.length();
    int len = 0;

    for (int i = 0; i < n; i++) {
        int hashMap[255] = {0}; // To check for character repetition
        for (int j = i; j < n; j++) {
            if (hashMap[s[j]] == 1) { // Break if character repeats
                break;
            }
            hashMap[s[j]] = 1;
            len = max(len, (j - i + 1)); // Update maximum length
        }
    }
    return len;
}

// Optimized Solution (Sliding Window, O(n) complexity)
int longestRepeat(string &s) {
    int n = s.length();
    int right = 0, left = 0;
    int len = 0;
    vector<int> hashMap(255, -1); // To store the last seen index of characters

    while (right < n) {
        if (hashMap[s[right]] != -1) {
            // Move the left pointer to avoid repeating characters
            left = max(left, hashMap[s[right]] + 1);
        }
        len = max(len, (right - left + 1)); // Update maximum length
        hashMap[s[right]] = right;         // Update last seen index
        right++;
    }

    return len;
}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        string s;
        cout << "Enter the string: ";
        cin >> s;

        // Call both implementations
        int bruteForceResult = longestSubstring(s);
        int optimizedResult = longestRepeat(s);

        cout << "Brute Force Result: " << bruteForceResult << endl;
        cout << "Optimized Result: " << optimizedResult << endl;
    }

    return 0;
}

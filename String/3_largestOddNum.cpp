#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
Given a numeric string `s`, find the largest odd number that can be formed by truncating 
zero or more digits from the end of the string. If no odd number can be formed, return an empty string.

Approach:
1. Traverse the string from the last character to the first.
2. Check if the current character is an odd digit.
3. If an odd digit is found, return the substring from the start to this digit (inclusive).
4. If no odd digit is found, return an empty string.

Time Complexity:
- O(n), where n is the length of the string `s`.
*/

// Function to find the largest odd number by truncating digits from the end
string largestOdd(string &s) {
    int n = s.length();

    // Traverse the string from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Check if the current digit is odd
        if ((s[i] - '0') % 2 == 1) {
            // Return the substring from the start to the current digit (inclusive)
            return s.substr(0, i + 1);
        }
    }

    // If no odd digit is found, return an empty string
    return "";
}

int main() {
    int t; // Number of test cases
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        string s;
        cout << "Enter the numeric string: ";
        cin >> s; // Input the numeric string

        // Call the function and display the result
        string result = largestOdd(s);
        if (result.empty()) {
            cout << "No odd number can be formed." << endl;
        } else {
            cout << "Largest odd number: " << result << endl;
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
Given a string `s`, reverse the order of words in the string but not the characters within the words. 
The string may have leading or trailing spaces, which should be removed in the final result. 
Words should be separated by a single space in the output.

Approaches:
1. Stringstream-Based Approach:
   - Use a stringstream to extract words, add them to the result in reverse order, 
     and handle leading/trailing spaces implicitly.

2. Two-Pointer Optimal Approach:
   - Reverse the entire string first.
   - Reverse each word individually while maintaining one space between words.
   - Trim the final result for leading/trailing spaces.
*/

// Approach 1: Stringstream-Based Approach
string reverseWord(string &s) {
    int n = s.length();
    stringstream ss(s); // Use stringstream to split the string into words
    string token = "";  // Temporary variable to store each word
    string ans = "";    // To store the reversed words

    while (ss >> token) { // Extract words ignoring extra spaces
        ans = token + " " + ans; // Append the current word to the front of the result
    }
    // Remove the trailing space from the result
    return ans.substr(0, ans.length() - 1);
}

/*
Approach 2: Two-Pointer Optimal Approach
1. Reverse the entire string.
2. Reverse each word individually.
3. Remove extra spaces and ensure one space between words.
*/
string reverseWordOptimal(string &s) {
    int n = s.length();
    reverse(s.begin(), s.end()); // Reverse the entire string

    int i = 0; // Iterator for the original string
    int right = 0, left = 0; // Two pointers to track start and end of each word

    while (i < n) {
        // Traverse to the next word
        while (i < n && s[i] != ' ') {
            s[right] = s[i]; // Shift characters of the current word to the front
            right++;
            i++;
        }

        // Reverse the current word when we've reached the end of it
        if (left < right) {
            reverse(s.begin() + left, s.begin() + right); // Reverse the current word
            if (right < n) { // Add a single space after the word
                s[right] = ' ';
                right++;
            }
            left = right; // Move `left` to the start of the next word
        }
        i++; // Skip spaces
    }

    // Remove trailing space and return the valid portion of the string
    return s.substr(0, right - (right > 0 && s[right - 1] == ' ' ? 1 : 0));
}

int main() {
    int t; // Number of test cases
    cout << "Enter the number of test cases: ";
    cin >> t;
    cin.ignore(); // Ignore trailing newline after reading `t`

    while (t--) {
        string s;
        cout << "Enter the string: ";
        getline(cin, s); // Read the entire input string, including spaces

        // Call both approaches and display results
        cout << "Using Stringstream Approach: " << reverseWord(s) << endl;

        // Create a copy of the input string to avoid modifying the original for the second approach
        string sCopy = s;
        cout << "Using Two-Pointer Optimal Approach: " << reverseWordOptimal(sCopy) << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
Two strings `s` and `p` are called isomorphic if the characters in `s` can be replaced to get `p`.
All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character, but a character may map to itself.

Approach:
1. Use two hash maps to maintain mappings between characters of `s` and `p`.
2. Traverse both strings simultaneously.
3. If a mapping for a character already exists, check if it is consistent. If not, return false.
4. If no inconsistency is found, return true.

Time Complexity: O(n), where n is the length of the strings.
Space Complexity: O(1), since the size of the hash maps is limited by the number of characters (256 for ASCII).
*/

// Function to check if two strings are isomorphic
bool isoMorphic(string &s, string &p) {
    // If the lengths are not equal, they cannot be isomorphic
    if (s.length() != p.length()) return false;

    // Hash maps to store character mappings
    unordered_map<char, char> umapS; // Mapping from s -> p
    unordered_map<char, char> umapP; // Mapping from p -> s

    int n = s.length();

    // Traverse both strings
    for (int i = 0; i < n; i++) {
        char ch1 = s[i]; // Character from string s
        char ch2 = p[i]; // Corresponding character from string p

        // Check if mapping for ch1 exists and is inconsistent
        if (umapS.find(ch1) != umapS.end() && umapS[ch1] != ch2) {
            return false;
        }

        // Check if mapping for ch2 exists and is inconsistent
        if (umapP.find(ch2) != umapP.end() && umapP[ch2] != ch1) {
            return false;
        }

        // Add or update the mappings
        umapS[ch1] = ch2;
        umapP[ch2] = ch1;
    }

    // If no inconsistencies are found, return true
    return true;
}

int main() {
    int t; // Number of test cases
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        string s, p;
        cout << "Enter string s: ";
        cin >> s;
        cout << "Enter string p: ";
        cin >> p;

        // Call the function and display the result
        if (isoMorphic(s, p)) {
            cout << "The strings are isomorphic." << endl;
        } else {
            cout << "The strings are not isomorphic." << endl;
        }
    }

    return 0;
}

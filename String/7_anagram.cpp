#include<bits/stdc++.h>
using namespace std;

/* 
Problem Statement: 
Given two strings `s` and `p`, determine if they are anagrams of each other.
An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, using all the original letters exactly once.

Examples:
1. s = "listen", p = "silent" -> true
2. s = "hello", p = "world" -> false
*/

/* Approach 1: Sorting Method
1. Sort both strings `s` and `p`.
2. If both strings are anagrams, their sorted versions will be identical.
3. If they are not anagrams, they will differ in sorted order.

Time Complexity: O(n log n), where n is the length of the string (due to sorting).
Space Complexity: O(1), as the sorting is done in place.
*/

bool isAnagram(string &s, string &p) {
    int n = s.length();
    int m = p.length();
    
    // If the lengths are different, they cannot be anagrams
    if(n != m) {
        return false;
    }

    // Sort both strings
    sort(s.begin(), s.end());
    sort(p.begin(), p.end());

    // Direct comparison of sorted strings
    return s == p; // If they are equal after sorting, they are anagrams
}

/* Approach 2: Frequency Count Method (Better Approach)
1. Create two frequency count arrays of size 256 (for each ASCII character).
2. Increment the count for each character in both strings.
3. If both arrays are equal, the strings are anagrams.

Time Complexity: O(n), where n is the length of the string (due to one pass through the strings).
Space Complexity: O(1), since the space used for the frequency count is fixed (256 characters).
*/

bool isAnagramBetter(string &s, string &p) {
    int n = s.length();
    int m = p.length();

    // If the lengths are different, they cannot be anagrams
    if(n != m) {
        return false;
    }

    // Create frequency count arrays for both strings
    vector<int> hash1(256, 0); // Frequency count for string s
    vector<int> hash2(256, 0); // Frequency count for string p

    // Populate the frequency counts
    for(int i = 0; i < n; i++) {
        hash1[s[i]]++; // Increment count for s
        hash2[p[i]]++; // Increment count for p
    }

    // If both frequency arrays are identical, the strings are anagrams
    return hash1 == hash2;
}

int main() {
    // Test the functions
    string s1 = "listen", p1 = "silent";
    string s2 = "hello", p2 = "world";

    // Test the first approach (sorting)
    cout << "Using Sorting Method: " << endl;
    cout << "Is \"" << s1 << "\" an anagram of \"" << p1 << "\"? " << (isAnagram(s1, p1) ? "Yes" : "No") << endl;
    cout << "Is \"" << s2 << "\" an anagram of \"" << p2 << "\"? " << (isAnagram(s2, p2) ? "Yes" : "No") << endl;

    // Test the second approach (frequency count)
    cout << "Using Frequency Count Method: " << endl;
    cout << "Is \"" << s1 << "\" an anagram of \"" << p1 << "\"? " << (isAnagramBetter(s1, p1) ? "Yes" : "No") << endl;
    cout << "Is \"" << s2 << "\" an anagram of \"" << p2 << "\"? " << (isAnagramBetter(s2, p2) ? "Yes" : "No") << endl;

    return 0;
}

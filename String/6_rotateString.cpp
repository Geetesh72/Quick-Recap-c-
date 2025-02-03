#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
Given two strings, `s` and `goal`, determine if `goal` can be obtained by rotating `s`.

Examples:
1. s = "abcde", goal = "cdeab" -> true (rotating "abcde" right gives "cdeab").
2. s = "abcde", goal = "abced" -> false (no rotation matches "abced").

Approach 1 - Brute Force:
1. Rotate string `s` one character at a time.
2. Compare the rotated string with `goal` after each rotation.
3. If a match is found, return `true`. If all rotations are checked, return `false`.

Time Complexity: O(n^2), where n is the length of string `s`.
Space Complexity: O(1).
*/

// Helper function to perform one rotation of the string `s`
void rotated(string &s)
{
    // Rotate the string one step to the left
    rotate(s.begin(), s.begin() + 1, s.end());
}

// Function to check if `goal` can be obtained by rotating `s` (brute force)
bool rotateString(string &s, string &goal)
{
    int n = s.length();
    int m = goal.length();

    // If lengths are different, goal cannot be a rotation of s
    if (n != m)
        return false;

    // Perform `n` rotations and check if any match `goal`
    for (int i = 0; i < n; i++)
    {
        rotated(s); // Rotate string by one character
        if (s == goal)
            return true; // Check if rotated string matches goal
    }

    return false; // No match found after all rotations
}

/*
Approach 2 - Optimal:
1. Concatenate the string `s` with itself (`s + s`).
2. If `goal` is a substring of this concatenated string, return true.
3. Otherwise, return false.

Reasoning:
Concatenating `s` with itself ensures all possible rotations of `s` are present as substrings.
Example: For s = "abcde", s + s = "abcdeabcde" contains all rotations: "abcde", "bcdea", "cdeab", "deabc", "eabcd".

Time Complexity: O(n + m), where n is the length of `s` and m is the length of `goal`.
Space Complexity: O(n) (for concatenating `s` with itself).
*/

// Function to check if `goal` can be obtained by rotating `s` (optimal)

void nposse()
{
    std::string s = "hello";
    size_t pos = s.find("lo");
    if (pos != std::string::npos)
    {
        std::cout << "Found at position: " << pos << std::endl;
    }
    else
    {
        std::cout << "Not found" << std::endl;
    }

    std::string s = "hello world";
    size_t pos = s.find_first_of("aeiou");
    if (pos != std::string::npos)
    {
        std::cout << "First vowel found at position: " << pos << std::endl;
    }
}
bool optimal(string &s, string &goal)
{
    int n = s.length();
    int m = goal.length();

    // If lengths are different, goal cannot be a rotation of s
    if (n != m)
        return false;

    // Concatenate s with itself and check if goal is a substring
    string concatenated = s + s;
    if (concatenated.find(goal) != string::npos)
    {
        return true;
    }

    return false; // goal is not a substring of concatenated s
}

int main()
{
    int t; // Number of test cases
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--)
    {
        string s, goal;
        cout << "Enter string s: ";
        cin >> s;
        cout << "Enter string goal: ";
        cin >> goal;

        // Brute force approach
        cout << "Brute Force Result: ";
        if (rotateString(s, goal))
        {
            cout << "The goal string can be obtained by rotating s." << endl;
        }
        else
        {
            cout << "The goal string cannot be obtained by rotating s." << endl;
        }

        // Optimal approach
        cout << "Optimal Result: ";
        if (optimal(s, goal))
        {
            cout << "The goal string can be obtained by rotating s." << endl;
        }
        else
        {
            cout << "The goal string cannot be obtained by rotating s." << endl;
        }
    }

    return 0;
}

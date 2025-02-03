#include <bits/stdc++.h>
using namespace std;

/* 
Problem: 
Given a string, sort its characters based on frequency in descending order.
Example:
Input: "tree"
Output: "eetr" (or "eetr", "eert", depending on character order in case of tie)

Approach:
1. Use a map or array to store the frequency of each character.
2. Sort the characters based on their frequency.
3. Reconstruct the string based on the sorted frequency.

Time Complexity: O(n log n), where n is the length of the string (due to sorting).
Space Complexity: O(n), where n is the number of unique characters.
*/

string frequency(string &s) {
    // Create a map to store the frequency of each character
    unordered_map<char, int> freq_map;
    
    // Count the frequency of each character in the string
    for (char &ch : s) {
        freq_map[ch]++;
    }
    
    // Create a vector of pairs (character, frequency) to sort by frequency
    vector<pair<char, int>> freq_vector(freq_map.begin(), freq_map.end());
    
    // Sort the vector in descending order of frequency using a custom comparator
    sort(freq_vector.begin(), freq_vector.end(), [](pair<char, int>& p1, pair<char, int>& p2) {
        return p1.second > p2.second; // Sort by frequency (higher frequency first)
    });

    // Reconstruct the string based on sorted frequency
    string ans = "";
    for (auto &p : freq_vector) {
        ans += string(p.second, p.first); // Append the character `p.second` times
    }

    return ans;
}

int main() {
    // Test the function
    string s = "tree";
    cout << "Sorted string based on frequency: " << frequency(s) << endl;

    return 0;
}

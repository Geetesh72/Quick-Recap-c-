#include<bits/stdc++.h>
using namespace std;
#define prime 101  // Prime number used for modulus operation in hashing

/* Rabin-Karp Algorithm:
   The Rabin-Karp algorithm is a string matching algorithm that uses a hash function to find pattern matches in a text.
   It computes a hash value for the pattern and each substring of the text and compares them to identify potential matches.
   If the hash values match, a full comparison is performed to check for an actual match.
   This is efficient as it reduces the number of full comparisons.
*/

vector<int> rabinKarp(string &text, string &pattern) {
    int n = text.length();   // Length of the text
    int m = pattern.length(); // Length of the pattern
    int noOfchar = 256;      // Number of possible characters (ASCII range)
    int pNo = prime;         // Prime number used for modulus in the hash function
    int pHashCode = 0;       // Hash code of the pattern
    int tHashCode = 0;       // Hash code of the current substring of the text
    int hash = 1;            // Hash value for the highest character place (used in rolling hash)
    vector<int> ans;         // Vector to store the indices of matches

    // Precompute the hash for the highest place of the string
    for (int i = 0; i < m - 1; i++) {
        hash = (hash * noOfchar) % pNo;
    }

    // Calculate the hash code of the pattern and the first window of the text
    for (int i = 0; i < m; i++) {
        pHashCode = (noOfchar * pHashCode + pattern[i]) % pNo;  // Hash for the pattern
        tHashCode = (noOfchar * tHashCode + text[i]) % pNo;      // Hash for the first window of the text
    }

    // Iterate through the text to check for possible matches
    for (int i = 0; i <= n - m; i++) {
        // If the hash codes match, we need to do a character-by-character comparison
        if (pHashCode == tHashCode) {
            bool match = true;
            // Compare each character of the text window with the pattern
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;  // If a mismatch is found, break and mark as not a match
                    break;
                }
            }
            if (match) {
                ans.push_back(i);  // If the pattern matches, store the index in the answer vector
            }
        }
        // Rolling hash: Update the hash value to the next substring of text
        if (i < n - m) {
            tHashCode = (noOfchar * (tHashCode - text[i] * hash) + text[i + m]) % pNo;

            // Ensure the hash value is non-negative (handle negative values from modulus)
            if (tHashCode < 0) {
                tHashCode += pNo;
            }
        }
    }

    return ans;  // Return the indices of matches found
}

// Function to display the results
void displayResults(string &text, string &pattern, vector<int> &matches) {
    if (matches.empty()) {
        cout << "Pattern not found in the text." << endl;
    } else {
        cout << "Pattern found at indices: ";
        for (int idx : matches) {
            cout << idx << " ";
        }
        cout << endl;
        cout << "Matched substrings: " << endl;
        for (int idx : matches) {
            cout << text.substr(idx, pattern.length()) << " ";
        }
        cout << endl;
    }
}

int main() { 
    string text = "ABCCDDAEFGABCDABC";
    string pattern = "ABC";
    
    vector<int> matches = rabinKarp(text, pattern);
    displayResults(text, pattern, matches);

    return 0;
}
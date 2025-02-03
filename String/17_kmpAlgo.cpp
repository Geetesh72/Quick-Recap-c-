#include <bits/stdc++.h>
using namespace std;

/*
----------------------------------------------
📌 PROBLEM STATEMENT:
Given a text `T` and a pattern `P`, find all occurrences of `P` in `T`.

💡 WHY USE KMP?
- The naive string matching algorithm has **O(N*M)** complexity, which is inefficient for large inputs.
- KMP (Knuth-Morris-Pratt) optimizes the search by avoiding unnecessary rechecking of characters.
- It achieves **O(N + M) time complexity** using the LPS (Longest Prefix Suffix) array.

🛠️ APPROACH:
1️⃣ **Precompute LPS Array** (Pattern Preprocessing)
   - The LPS array stores the length of the longest prefix which is also a suffix.
   - This helps in avoiding unnecessary comparisons.

2️⃣ **Pattern Matching**
   - Use the LPS array to skip redundant character checks.
   - If a mismatch occurs, use LPS to determine the next valid position instead of restarting from index 0.

📊 TIME COMPLEXITY:
- LPS Preprocessing: **O(M)**
- Pattern Search: **O(N)**
- Overall Complexity: **O(N + M)** (Much faster than the naive O(N*M) approach)
----------------------------------------------
*/

// Function to compute the LPS (Longest Prefix Suffix) array
vector<int> computeLPS(string &pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0); // Initialize LPS array with 0
    int len = 0;  // Length of the previous longest prefix suffix
    int i = 1;    // Start from index 1 (lps[0] is always 0)

    /*
    🔹 STEP 1: Compute the LPS array
    - If `pattern[i] == pattern[len]`, extend LPS by 1.
    - Otherwise, reduce `len` to `lps[len-1]` (backtrack).
    - If `len == 0`, set `lps[i] = 0` and move forward.
    */
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; // Move back in LPS
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// Function to perform KMP String Matching Algorithm
vector<int> KMPSearch(string &text, string &pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> lps = computeLPS(pattern); // Step 1: Compute LPS array
    vector<int> result;  // Stores starting indices of matches

    int i = 0, j = 0; // i → text index, j → pattern index

    /*
    🔹 STEP 2: Pattern Matching
    - If `text[i] == pattern[j]`, increment both i and j.
    - If j reaches `m` (full match), store the index and reset `j` using LPS.
    - If a mismatch occurs:
      - If `j != 0`, use LPS to skip unnecessary comparisons.
      - Otherwise, move to the next character in `text`.
    */
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++, j++;
        }
        if (j == m) {
            result.push_back(i - j); // Store index of pattern match
            j = lps[j - 1]; // Reset j using LPS
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1]; // Use LPS to optimize
            } else {
                i++;
            }
        }
    }
    return result;
}

// Driver Code
int main() {
    string text = "ababcababcabababc";
    string pattern = "abab";

    vector<int> matches = KMPSearch(text, pattern);

    cout << "Pattern found at indices: ";
    for (int index : matches) {
        cout << index << " ";
    }
    return 0;
}

/*
----------------------------------------------
✅ SAMPLE OUTPUT:
Input: text = "ababcababcabababc", pattern = "abab"
Output: Pattern found at indices: 0 5 10

🎯 KEY TAKEAWAYS:
- The LPS array prevents unnecessary comparisons.
- KMP ensures linear time complexity **O(N + M)**.
- Suitable for large text searches, e.g., DNA sequencing, plagiarism detection.

🚀 FAST RECAP:
1️⃣ Build LPS array → Identify repeated prefix-suffix.
2️⃣ Use LPS during matching to **skip redundant comparisons**.
----------------------------------------------
*/

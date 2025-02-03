/*
📝 **Problem Statement:**
Given two version numbers represented as strings (e.g., `"1.01"` and `"1.001"`), compare them based on their numerical values. The comparison follows these rules:
- If `version1 > version2`, return `1`.
- If `version1 < version2`, return `-1`.
- If they are equal, return `0`.

---

📌 **Why Use Tokenization?**
- Version numbers are typically **dot-separated** (e.g., `"1.0.3"`).
- We need to **split** them into individual numeric parts and **compare**.

---

💡 **Approach:**
1. **Tokenization:**
   - Split the version string into numerical components using `"."` as a delimiter.

2. **Comparison:**
   - Convert the extracted tokens into integers.
   - Compare the corresponding parts from both versions.
   - If one version has fewer parts, treat missing values as `0` (e.g., `"1.0"` and `"1.0.0"` are equal).

3. **Return appropriate result:**
   - If `version1 > version2`, return `1`.
   - If `version1 < version2`, return `-1`.
   - If they are equal, return `0`.

---

🔹 **Time Complexity:** `O(max(m, n))`  
🔹 **Space Complexity:** `O(m + n)`, where `m, n` are the number of parts in `version1` and `version2`.

*/

#include <bits/stdc++.h>
using namespace std;

// Function to tokenize a version string into parts
vector<string> getTokens(string version) {
    stringstream ss(version);
    string token = "";
    vector<string> tokens;

    while (getline(ss, token, '.')) {
        tokens.push_back(token);
    }
    return tokens;
}

// Function to compare two version numbers
int compareVersion(string &version1, string &version2) {
    vector<string> v1 = getTokens(version1);
    vector<string> v2 = getTokens(version2);
    
    int m = v1.size();
    int n = v2.size();
    int i = 0;

    while (i < m || i < n) {
        // Convert string token to integer, default to 0 if index exceeds length
        int a = (i < m) ? stoi(v1[i]) : 0;
        int b = (i < n) ? stoi(v2[i]) : 0;

        if (a < b) {
            return -1;
        } else if (a > b) {
            return 1;
        }

        i++; // Move to the next token
    }

    return 0; // Versions are equal
}

int main() {
    string version1 = "1.01";
    string version2 = "1.001";

    int result = compareVersion(version1, version2);

    if (result == 1) {
        cout << version1 << " is greater than " << version2 << endl;
    } else if (result == -1) {
        cout << version1 << " is less than " << version2 << endl;
    } else {
        cout << version1 << " is equal to " << version2 << endl;
    }

    return 0;
}

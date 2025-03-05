#include <bits/stdc++.h>
using namespace std;

/*
Approach:
1. If both strings `s1` and `s2` are already equal, return `true` immediately.
2. Identify the positions where `s1[i] != s2[i]` and store them in a vector `pos`.
3. If the number of mismatches is not exactly **2**, return `false` because:
   - If there are **more than 2 mismatches**, swapping one pair won't fix it.
   - If there is **only 1 mismatch**, swapping one character is meaningless.
4. If exactly **two mismatches** exist, check whether swapping the characters at 
   those two positions makes the strings equal.
5. Return `true` if swapping fixes the issue; otherwise, return `false`.

Time Complexity: **O(n)** (We iterate through the string once to find mismatches)
Space Complexity: **O(1)** (We store at most 2 indices)
*/

bool areAlmostEqual(string &s1, string &s2) {
    int n = s1.length();
    
    // If strings are already equal, return true
    if (s1 == s2) {
        return true;
    }

    int cnt = 0;
    vector<int> pos;  // Store positions of mismatched characters

    // Identify mismatching positions
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            cnt++;
            pos.push_back(i);
        }
    }

    // If the number of mismatches is not exactly 2, return false
    if (cnt != 2) {
        return false;
    }

    // Check if swapping the two mismatched positions makes strings equal
    return (s1[pos[0]] == s2[pos[1]] && s1[pos[1]] == s2[pos[0]]);
}

int main() {
    string s1, s2;
    
    cout << "Enter first string: ";
    cin >> s1;
    
    cout << "Enter second string: ";
    cin >> s2;
    
    if (areAlmostEqual(s1, s2)) {
        cout << "The strings can be made equal by swapping exactly one pair of characters." << endl;
    } else {
        cout << "The strings cannot be made equal with a single swap." << endl;
    }

    return 0;
}

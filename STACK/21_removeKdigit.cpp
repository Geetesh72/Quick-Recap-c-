#include <bits/stdc++.h>
using namespace std;    
string smallerDigit(string &s, int k) {
    int n = s.length();
    stack<char> st;

    // Traverse through each character of the string.
    for (int i = 0; i < n; i++) {
        // Remove larger digits from the stack if `k > 0`.
        while (!st.empty() && k > 0 && st.top() > s[i]) {
            st.pop();
            k--;
        }
        st.push(s[i]);
    }

    // Remove remaining digits if `k > 0`.
    while (k > 0 && !st.empty()) {
        st.pop();
        k--;
    }

    // Build the result from the stack.
    string ans = "";
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    // Reverse the result to restore the correct order.
    reverse(ans.begin(), ans.end());

    // Remove leading zeros.
    while (ans.size() > 1 && ans[0] == '0') {
        ans.erase(ans.begin());
    }

    // If the result is empty, return "0".
    return ans.empty() ? "0" : ans;
}

int main() {
    string s = "1432219";
    int k = 3;
    cout << "Smallest number after removing " << k << " digits: " << smallerDigit(s, k) << endl;

    s = "10200";
    k = 1;
    cout << "Smallest number after removing " << k << " digits: " << smallerDigit(s, k) << endl;

    s = "10";
    k = 2;
    cout << "Smallest number after removing " << k << " digits: " << smallerDigit(s, k) << endl;

    return 0;
}
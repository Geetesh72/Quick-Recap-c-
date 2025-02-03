#include <bits/stdc++.h>
using namespace std;

/* 
   Function: maxDepthStack
   Description:
   - Uses a stack to determine the maximum depth of nested parentheses.
   - Each '(' increases the depth, and ')' decreases it if there’s a matching '('.
   - Tracks the maximum size of the stack, which corresponds to the maximum depth.

   Input: string s (the input containing parentheses)
   Output: int (maximum depth of nested parentheses)
*/
int maxDepthStack(string &s) {
    int n = s.length(); // Length of the input string
    stack<char> st;     // Stack to track parentheses
    int maxi = 0;       // Maximum depth (initialize to 0 since depth can't be negative)
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(s[i]);                  // Push '(' onto the stack
            maxi = max((int)st.size(), maxi); // Update maximum depth
        } else if (s[i] == ')') {
            if (!st.empty() && st.top() == '(') {
                st.pop(); // Pop matching '(' from the stack
            }
        }
    }
    return maxi; // Return the maximum depth of nested parentheses
}

/*
   Function: maxDepth
   Description:
   - Optimized approach to determine the maximum depth of nested parentheses.
   - Uses a counter to track the current depth instead of a stack.
   - Updates the maximum depth when encountering ')' that closes a '('.

   Input: string s (the input containing parentheses)
   Output: int (maximum depth of nested parentheses)
*/
int maxDepth(string &s) {
    int n = s.length(); // Length of the input string
    int maxi = 0;       // Maximum depth (initialize to 0 since depth can't be negative)
    int cnt = 0;        // Counter to track the current depth
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            cnt++;               // Increase current depth when encountering '('
        } else if (s[i] == ')') {
            maxi = max(cnt, maxi); // Update maximum depth
            cnt--;                // Decrease current depth after matching ')'
        }
    }
    return maxi; // Return the maximum depth of nested parentheses
}

int main() {
    int t; // Number of test cases
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        // Call both functions and display their results
        int resultStack = maxDepthStack(s);
        int resultOptimal = maxDepth(s);

        cout << "Max Depth (Stack): " << resultStack << endl;
        cout << "Max Depth (Optimal): " << resultOptimal << endl;
    }
    return 0;
}

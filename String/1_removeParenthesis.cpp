#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
Given a valid parentheses string `s`, remove the outermost parentheses from every primitive 
valid parentheses substring. A primitive valid parentheses substring is one that cannot 
be further split into smaller valid parentheses substrings. 
For example, given s = "(()())(())", the output should be "()()()".

Approaches:
1. Stack-Based Approach:
   - Use a stack to identify when a valid primitive substring starts and ends. 
     Only add parentheses to the result when they are part of the inner valid substring.

2. Count-Based Optimal Approach:
   - Use a counter to track the balance of parentheses. Append to the result only 
     when the count indicates it is not an outer parenthesis.
*/

// Stack-Based Approach
string remove(string &s) {
    int n = s.length();
    string ans = "";       // To store the resulting string without outer parentheses
    stack<char> st;        // Stack to track parentheses

    for (int i = 0; i < n; i++) {
        // If the current character is '(', push to stack
        if (s[i] == '(') {
            // Only append to result if the stack is not empty (not outermost '(')
            if (!st.empty()) ans.push_back(s[i]);
            st.push(s[i]);
        } 
        // If the current character is ')', pop from the stack
        else if (s[i] == ')') {
            st.pop();
            // Only append to result if the stack is not empty (not outermost ')')
            if (!st.empty()) ans.push_back(s[i]);
        }
    }
    return ans;
}

// Count-Based Optimal Approach
string removeOptimal(string &s) {
    int n = s.length();
    string ans = "";  // To store the resulting string without outer parentheses
    int cnt = 0;      // Counter to track the balance of parentheses

    for (int i = 0; i < n; i++) {
        // If the current character is '(', increment the counter
        if (s[i] == '(') {
            // Only append to result if counter is greater than 0 (not outermost '(')
            if (cnt > 0) ans.push_back(s[i]);
            cnt++;
        } 
        // If the current character is ')', decrement the counter
        else if (s[i] == ')') {
            cnt--;
            // Only append to result if counter is greater than 0 after decrement (not outermost ')')
            if (cnt > 0) ans.push_back(s[i]);
        }
    }
    return ans;
}

int main() {
    string s = "(()())(())";
    cout << "Stack-Based Approach Result: " << remove(s) << endl;
    cout << "Count-Based Optimal Approach Result: " << removeOptimal(s) << endl;
    return 0;
}

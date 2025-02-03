#include <bits/stdc++.h>
using namespace std;

int myAtoi(string &s) {
    int n = s.length();
    if (n == 0) return 0;

    int i = 0; 
    // Skip leading spaces
    while (i < n && s[i] == ' ') i++;
    if (i == n) return 0;

    // Determine sign
    int sign = 1;
    if (s[i] == '-' || s[i] == '+') {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    long ans = 0; // Use long to handle overflow
    int maxi = INT_MAX, mini = INT_MIN;

    // Process numeric characters
    while (i < n && isdigit(s[i])) {
        ans = ans * 10 + (s[i] - '0');

        // Check overflow conditions
        if (sign == 1 && ans > maxi) return maxi;
        if (sign == -1 && -ans < mini) return mini;

        i++;
    }

    return (int)(sign * ans);
}

int main() {
    // Test the implementation
    string s;
    cout << "Enter the string: ";
    cin >> s;
    cout << "Converted integer: " << myAtoi(s) << endl;
    return 0;
}

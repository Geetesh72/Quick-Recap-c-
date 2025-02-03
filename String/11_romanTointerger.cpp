#include <bits/stdc++.h>
using namespace std;

int romanToInteger(string &s) {
    // Map of Roman numerals to their integer values
    unordered_map<char, int> romanMap = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
        {'C', 100}, {'D', 500}, {'M', 1000}
    };
    
    int n = s.length();
    int total = 0;

    for (int i = 0; i < n; i++) {
        // Check if the current value is smaller than the next value
        if (i + 1 < n && romanMap[s[i]] < romanMap[s[i + 1]]) {
            total -= romanMap[s[i]]; // Subtract the value
        } else {
            total += romanMap[s[i]]; // Add the value
        }
    }
    
    return total;
}

int main() {
    // Example usage
    string s;
    cout << "Enter a Roman numeral: ";
    cin >> s;
    int result = romanToInteger(s);
    cout << "The integer value is: " << result << endl;
    return 0;
}

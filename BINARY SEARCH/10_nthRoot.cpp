#include <bits/stdc++.h>
using namespace std;

/*
Helper function to calculate the nth power of mid and compare it with m.
Returns:
1 -> If mid^n == m (Exact match found)
2 -> If mid^n > m (Need to search in the left half)
0 -> If mid^n < m (Need to search in the right half)
*/
int comparePower(int mid, int n, int m) {
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= mid;
        if (ans > m) return 2; // Exceeds m
    }
    if (ans == m) return 1; // Exact match
    return 0; // Less than m
}

/*
Binary Search for nth Root
1. Apply binary search in the range [1, m].
2. For each mid, use comparePower() to decide the search direction.
3. If an exact match is found, return mid.
4. If no exact match exists, return -1 (nth root does not exist as an integer).
*/
int nthRootBinarySearch(int n, int m) {
    int low = 1;
    int high = m;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int result = comparePower(mid, n, m);

        if (result == 1) {
            return mid; // Exact nth root found
        } else if (result == 2) {
            high = mid - 1; // Search in the left half
        } else {
            low = mid + 1; // Search in the right half
        }
    }
    return -1; // No integer nth root exists
}

int main() {
    int n = 3, m = 27; // Example: Find the 3rd root of 27
    int result = nthRootBinarySearch(n, m);

    if (result != -1) {
        cout << "The " << n << "th root of " << m << " is: " << result << endl;
    } else {
        cout << "No integer " << n << "th root exists for " << m << "." << endl;
    }

    return 0;
}

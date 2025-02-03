#include <bits/stdc++.h>
using namespace std;

/*
Naive Approach:
1. Loop from 1 to n/2 to find the largest integer i such that i*i <= n.
2. If i*i == n, return i.
3. Otherwise, return the last valid i before the product exceeds n.

Limitations:
- Inefficient for large values of n.
*/

int sqrtNaive(int n) {
    if (n == 0 || n == 1) return n; // Handle edge cases for 0 and 1
    int ans = 1;
    for (int i = 1; i <= n / 2; i++) {
        if (i * i == n) {
            return i; // Perfect square case
        } else if (i * i > n) {
            break; // Break as soon as the square exceeds n
        }
        ans = i; // Update the closest valid answer
    }
    return ans;
}

/*
Optimized Approach: Using Binary Search
Steps:
1. Apply binary search in the range [1, n].
2. Calculate mid as the potential square root.
3. If mid*mid == n, return mid (perfect square case).
4. If mid*mid < n, update ans to mid and move the search to the right half.
5. If mid*mid > n, move the search to the left half.
6. Continue until low > high.
*/

int sqrtBinarySearch(int n) {
    if (n == 0 || n == 1) return n; // Handle edge cases for 0 and 1

    int low = 1;
    int high = n;
    int ans = -1; // To store the integer square root

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if mid is the perfect square root
        if (mid * mid == n) {
            return mid;
        }

        // If mid*mid < n, move to the right half
        if (mid * mid < n) {
            ans = mid; // Update the closest valid answer
            low = mid + 1;
        } else {
            high = mid - 1; // Move to the left half
        }
    }
    return ans;
}

int main() {
    int n = 36; // Example input
    cout << "Square root of " << n << " (Naive): " << sqrtNaive(n) << endl;
    cout << "Square root of " << n << " (Binary Search): " << sqrtBinarySearch(n) << endl;

    return 0;
}

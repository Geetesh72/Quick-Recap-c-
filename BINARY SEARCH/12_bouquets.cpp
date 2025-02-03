#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
- You are given an array `nums` representing the bloom days of flowers.
- You need to make `m` bouquets, where each bouquet consists of `k` adjacent flowers.
- The goal is to find the minimum number of days required to make `m` bouquets. If it is not possible, return -1.

Approach:
1. Use binary search on the answer (minimum days).
2. Range of search: [min bloom day, max bloom day].
3. Use a helper function `possible()` to determine if it is possible to make `m` bouquets within a given number of days.
4. Adjust the search range based on the result of `possible()`.

Helper Function (`possible()`):
- Checks if it is possible to make `m` bouquets within `mid` days.
- Traverse the array and count consecutive flowers blooming within `mid` days.
- If enough bouquets are formed, return true (1); otherwise, return false (0).
*/

/*
Helper Function:
Determines if it is possible to make `m` bouquets within `mid` days.
- nums: Array of bloom days.
- mid: Number of days being checked.
- k: Number of adjacent flowers required for a bouquet.
- m: Total number of bouquets required.
*/
int possible(vector<int>& nums, int mid, int k, int m) {
    int n = nums.size();
    int cnt = 0;   // Count of consecutive flowers blooming within `mid` days.
    int nofB = 0;  // Number of bouquets formed.

    for (int i = 0; i < n; i++) {
        if (nums[i] <= mid) {
            cnt++;
            if (cnt == k) { // If `k` adjacent flowers are found.
                nofB++;
                cnt = 0; // Reset the count for the next bouquet.
            }
        } else {
            cnt = 0; // Reset the count if the flower cannot bloom within `mid` days.
        }
    }
    return nofB >= m;
}

/*
Binary Search Function:
Finds the minimum number of days to make `m` bouquets.
- nums: Array of bloom days.
- m: Total number of bouquets required.
- k: Number of adjacent flowers required for a bouquet.
*/
int bouquets(vector<int>& nums, int m, int k) {
    int n = nums.size();
    int low = *min_element(nums.begin(), nums.end());
    int high = *max_element(nums.begin(), nums.end());
    int ans = -1;

    // Edge case: If total flowers required (m * k) exceed the array size, return -1.
    if (m * k > n) {
        return -1;
    }

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (possible(nums, mid, k, m)) {
            ans = mid;      // Valid solution found, try to minimize further.
            high = mid - 1; // Search in the left half.
        } else {
            low = mid + 1;  // Increase days, search in the right half.
        }
    }
    return ans;
}

int main() {
    vector<int> bloomDays = {1, 10, 3, 10, 2}; // Example input.
    int m = 3; // Number of bouquets required.
    int k = 1; // Number of adjacent flowers required for a bouquet.

    int result = bouquets(bloomDays, m, k);
    cout << "Minimum days to make " << m << " bouquets: " << result << endl;

    return 0;
}

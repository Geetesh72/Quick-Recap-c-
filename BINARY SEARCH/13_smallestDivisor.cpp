#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
- Given an array `nums` and a threshold value `k`.
- Find the minimum integer divisor `mid` such that the sum of the ceiling of each element divided by `mid` is less than or equal to `k`.

Approach:
1. Use binary search on the answer (`mid`), which represents the divisor.
2. The range of search is `[1, max(nums)]` since the divisor cannot exceed the largest element in the array.
3. Use a helper function `threshold()` to check if a given `mid` satisfies the condition.
4. Adjust the search range based on the result of `threshold()`.

Helper Function (`threshold()`):
- Checks if the sum of `ceil(nums[i] / mid)` for all elements in the array is less than or equal to `k`.
- Returns `true (1)` if the condition is met; otherwise, returns `false (0)`.
*/

/*
Helper Function:
Checks if the sum of `ceil(nums[i] / mid)` for all elements is <= `k`.
- nums: Array of integers.
- k: Threshold value.
- mid: Divisor being tested.
*/
int threshold(vector<int>& nums, int k, int mid) {
    int n = nums.size();
    int var = 0; // Sum of ceilings.

    for (int i = 0; i < n; i++) {
        var += ceil((double)nums[i] / (double)mid);
        // Early exit if the sum exceeds the threshold.
        if (var > k) {
            return 0;
        }
    }
    return 1;
}

/*
Binary Search Function:
Finds the minimum divisor `mid` such that the sum of ceilings is <= `k`.
- nums: Array of integers.
- k: Threshold value.
*/
int binarySearch(vector<int>& nums, int k) {
    int n = nums.size();
    int low = 1; // Minimum possible divisor.
    int high = *max_element(nums.begin(), nums.end()); // Maximum possible divisor.
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if the current divisor `mid` satisfies the condition.
        if (threshold(nums, k, mid)) {
            ans = mid;      // Valid divisor found, try to minimize further.
            high = mid - 1; // Search in the left half.
        } else {
            low = mid + 1;  // Increase divisor, search in the right half.
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {10, 20, 30, 40}; // Example input.
    int k = 7; // Threshold value.

    int result = binarySearch(nums, k);
    cout << "Minimum divisor to satisfy the threshold: " << result << endl;

    return 0;
}

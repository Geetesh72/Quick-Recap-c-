#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds the length of the longest strictly increasing or decreasing subarray.
 * 
 * Given an array `nums`, this function calculates the maximum length of a contiguous 
 * subarray that is either strictly increasing or strictly decreasing.
 * 
 * Approach:
 * - Use two counters:
 *   1. `incCount` → Tracks the length of the current increasing subarray.
 *   2. `decCount` → Tracks the length of the current decreasing subarray.
 * - Iterate through `nums`, updating `incCount` and `decCount` based on the conditions:
 *   - If `nums[i] > nums[i-1]`: Increment `incCount`, reset `decCount` to 1.
 *   - If `nums[i] < nums[i-1]`: Increment `decCount`, reset `incCount` to 1.
 *   - Update `maxLen` with the larger of `incCount` or `decCount`.
 * 
 * @param nums The input array of integers.
 * @return The length of the longest strictly increasing or decreasing subarray.
 */
int longestMonotonicSubarray(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;  // Edge case: empty array

    int incCount = 1, decCount = 1, maxLen = 1;

    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1]) {  // Strictly increasing sequence
            incCount++;
            decCount = 1;  // Reset decreasing counter
        } 
        else if (nums[i] < nums[i - 1]) {  // Strictly decreasing sequence
            decCount++;
            incCount = 1;  // Reset increasing counter
        }

        // Update max length found so far
        maxLen = max(maxLen, max(incCount, decCount));
    }
    return maxLen;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input! Array size must be greater than 0.\n";
        return 0;
    }

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = longestMonotonicSubarray(nums);
    cout << "The length of the longest monotonic subarray is: " << result << endl;

    return 0;
}

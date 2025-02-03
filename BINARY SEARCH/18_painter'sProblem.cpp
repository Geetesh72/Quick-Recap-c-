#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
- Given an array `nums` of non-negative integers and an integer `k`,
  split the array into `k` non-empty subarrays such that the maximum sum
  of any subarray is minimized.

Approach:
- Binary search on the possible maximum sum of subarrays.
- Key insight: The search space is [max(nums), sum(nums)].
- Use a helper function to check if a given maximum sum (`maxSum`) allows splitting into `k` subarrays.
*/

/*
Helper Function:
- Check if it is possible to split the array into `k` or fewer subarrays,
  such that the sum of each subarray is <= `maxSum`.
*/
bool isValidSplit(vector<int>& nums, int maxSum, int k) {
    int subarrayCount = 1; // Start with one subarray.
    int currentSum = 0;

    for (int num : nums) {
        // If adding the current number exceeds `maxSum`, start a new subarray.
        if (currentSum + num > maxSum) {
            subarrayCount++;
            currentSum = num;

            // If the number of subarrays exceeds `k`, return false.
            if (subarrayCount > k) {
                return false;
            }
        } else {
            currentSum += num;
        }
    }

    return true; // Splitting into `k` or fewer subarrays is possible.
}

/*
Main Function:
- Minimize the maximum sum of subarrays when splitting `nums` into `k` parts.
*/
int splitArray(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(), nums.end()); // Minimum possible max sum.
    int high = accumulate(nums.begin(), nums.end(), 0); // Maximum possible max sum.
    int result = high;

    // Binary search to find the minimized maximum sum.
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if the current `mid` is a valid maximum sum.
        if (isValidSplit(nums, mid, k)) {
            result = mid; // Update the result.
            high = mid - 1; // Try for a smaller maximum sum.
        } else {
            low = mid + 1; // Increase the maximum sum.
        }
    }

    return result;
}

int main() {
    vector<int> nums = {7, 2, 5, 10, 8}; // Example input array.
    int k = 2; // Number of subarrays.

    cout << "Minimized Maximum Subarray Sum: " << splitArray(nums, k) << endl;

    return 0;
}

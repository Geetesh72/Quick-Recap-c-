#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Given an array of positive integers nums, return the maximum possible sum 
 *        of an ascending subarray in nums.
 *
 * @details
 * - A subarray is a contiguous sequence of numbers in an array.
 * - A subarray is considered ascending if every element is strictly greater 
 *   than the previous one.
 * - The goal is to find the **maximum sum** among all such ascending subarrays.
 *
 * @example
 * Input: nums = [10, 20, 30, 5, 10, 50]
 * Output: 65
 * Explanation: The subarray [5, 10, 50] has the maximum sum.
 */

/**
 * @brief Brute force approach (O(N^2) time complexity)
 *
 * @details
 * - Iterate through all possible subarrays.
 * - Maintain a running sum for each valid ascending subarray.
 * - Track the maximum sum found.
 *
 * @param nums Input array of positive integers
 * @return Maximum sum of any ascending subarray
 */
int maxAscendingSumBruteForce(vector<int>& nums) {
    int n = nums.size();
    int maxi = INT_MIN;  // Stores the maximum sum found

    // Iterate over all starting points of subarrays
    for (int i = 0; i < n; i++) {
        int sum = nums[i]; // Initialize sum with the first element
        maxi = max(maxi, sum);

        // Expand the subarray while it remains strictly increasing
        for (int j = i + 1; j < n; j++) {
            if (nums[j - 1] < nums[j]) {
                sum += nums[j];  // Extend subarray sum
                maxi = max(maxi, sum); // Update maximum sum
            } else {
                break; // Stop when sequence is no longer increasing
            }
        }
    }
    return maxi;
}

/**
 * @brief Optimized approach using a single pass (O(N) time complexity) [Sliding Window]
 *
 * @details
 * - Traverse the array in a single pass.
 * - If the current element is greater than the previous one, add to `currSum`.
 * - Otherwise, reset `currSum` and start a new subarray.
 * - Maintain a running maximum of `currSum`.
 *
 * @param nums Input array of positive integers
 * @return Maximum sum of any ascending subarray
 */
int maxAscendingSumOptimized(vector<int>& nums) {
    int n = nums.size();
    int maxSum = nums[0];   // Stores maximum ascending subarray sum
    int currSum = nums[0];  // Running sum of the current ascending subarray

    // Traverse the array
    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1]) {
            currSum += nums[i];  // Extend the ascending subarray
        } else {
            currSum = nums[i];  // Start a new ascending subarray
        }
        maxSum = max(maxSum, currSum); // Update the maximum sum found
    }
    return maxSum;
}

int main() {

    int t ;
    cout<<"Enter Number the of test case: ";
    cin>>t;

    while(t--){

    int n;
    cout<<"Enter the size of array: "<<endl;
    cin>>n;
    vector<int>nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }

    cout << "Brute Force Result: " << maxAscendingSumBruteForce(nums) << endl;
    cout << "Optimized Result: " << maxAscendingSumOptimized(nums) << endl;
    }

    return 0;
}

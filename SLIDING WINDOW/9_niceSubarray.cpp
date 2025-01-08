#include <bits/stdc++.h>
using namespace std;

/*
Problem Description:
Given an integer array `nums` and an integer `k`, return the number of contiguous subarrays 
that contain exactly `k` odd numbers.

Examples:
1. Input: nums = [1, 1, 2, 1, 1], k = 3
   Output: 2
   Explanation: The subarrays are [1,1,2,1] and [1,2,1,1].

2. Input: nums = [2, 4, 6], k = 1
   Output: 0
   Explanation: There are no odd numbers in the array.

3. Input: nums = [2, 4, 6, 1, 1], k = 2
   Output: 1
   Explanation: The subarray [6, 1, 1] has exactly 2 odd numbers.
*/

// Helper Function: Count subarrays with at most `k` odd numbers
int countSubarraysWithAtMostKOddNumbers(vector<int> &nums, int k) {
    int n = nums.size();
    int right = 0, left = 0, cnt = 0, sum = 0;

    while (right < n) {
        sum += nums[right] % 2; // Increment sum if the current number is odd

        // Shrink the window until the sum is <= k
        while (sum > k) {
            sum -= nums[left] % 2; // Decrement sum if the leftmost number is odd
            left++;
        }

        // Count all subarrays ending at `right`
        cnt += (right - left + 1);
        right++;
    }

    return cnt;
}

// Main Function: Count subarrays with exactly `k` odd numbers
int countSubarraysWithExactlyKOddNumbers(vector<int> &nums, int k) {
    return countSubarraysWithAtMostKOddNumbers(nums, k) -
           countSubarraysWithAtMostKOddNumbers(nums, k - 1);
}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        int n, k;
        cout << "\nEnter the size of the array: ";
        cin >> n;

        vector<int> nums(n);
        cout << "Enter the array elements: ";
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        cout << "Enter the value of k (number of odd numbers): ";
        cin >> k;

        int result = countSubarraysWithExactlyKOddNumbers(nums, k);

        cout << "\nResult:\n";
        cout << "Number of subarrays with exactly " << k << " odd numbers: " << result << endl;
    }

    return 0;
}

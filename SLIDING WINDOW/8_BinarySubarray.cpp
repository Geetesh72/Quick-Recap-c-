#include <bits/stdc++.h>
using namespace std;

/*
Problem Description:
Given a binary array `nums` and an integer `goal`, return the number of non-empty subarrays 
with a sum equal to `goal`.

Examples:
1. Input: nums = [1, 0, 1, 0, 1], goal = 2
   Output: 4
   Explanation: The subarrays with sum equal to 2 are: [1,0,1], [0,1,0,1], [1,0,1], and [0,1,0].

2. Input: nums = [0, 0, 0, 0, 0], goal = 0
   Output: 15
   Explanation: All subarrays have sum equal to 0.
*/

// Helper Function: Count subarrays with sum less than or equal to `goal`
int countSubarraysWithSumLessThanOrEqual(vector<int> &nums, int goal) {
    if (goal < 0) {
        return 0; // If the goal is negative, no subarray can satisfy the condition
    }

    int n = nums.size();
    int right = 0, left = 0, cnt = 0, sum = 0;

    while (right < n) {
        sum += nums[right]; // Add the current number to the sum

        // Shrink the window until the sum is <= goal
        while (sum > goal) {
            sum -= nums[left];
            left++;
        }

        // Count all subarrays ending at `right`
        cnt += (right - left + 1);
        right++;
    }

    return cnt;
}

// Main Function: Count subarrays with sum exactly equal to `goal`
int countSubarraysWithSum(vector<int> &nums, int goal) {
    return countSubarraysWithSumLessThanOrEqual(nums, goal) -
           countSubarraysWithSumLessThanOrEqual(nums, goal - 1);
}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        int n, goal;
        cout << "\nEnter the size of the array: ";
        cin >> n;
        vector<int> nums(n);

        cout << "Enter the binary array elements: ";
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        cout << "Enter the goal: ";
        cin >> goal;

        int result = countSubarraysWithSum(nums, goal);

        cout << "\nResult:\n";
        cout << "Number of subarrays with sum equal to " << goal << ": " << result << endl;
    }

    return 0;
}

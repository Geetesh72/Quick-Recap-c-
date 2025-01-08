#include <bits/stdc++.h>
using namespace std;

/*
Problem Description:
Given an array of 0s and 1s, return the maximum length of a subarray containing all 1s 
by flipping at most k zeros.

Constraints:
- Input: nums (array of integers, either 0 or 1), k (integer, maximum zeros allowed to flip)
- Output: Maximum length of the subarray
*/

// Brute Force (O(n^2) complexity)
int maxConsecutive(vector<int>& nums, int k) {
    int n = nums.size();
    int len = 0;

    for (int i = 0; i < n; i++) {
        int zero = 0;
        for (int j = i; j < n; j++) {
            if (nums[j] == 0) {
                zero++;
            }
            if (zero <= k) {
                len = max(len, (j - i + 1)); // Update the maximum length
            } else {
                break; // Stop checking if zeros exceed k
            }
        }
    }

    return len;
}

// Optimal Sliding Window (O(n) complexity)
// 1 1 0 0 1 1 0 1
int maxConsecutiveOptimal(vector<int>& nums, int k) {
    int n = nums.size();
    int right = 0, left = 0;
    int maxi = 0;
    int zero = 0;

    while (right < n) {
        if (nums[right] == 0) zero++;

        // Shrink the window until the condition (zero <= k) is satisfied
        while (zero > k) {
            if (nums[left] == 0) {zero--;}
            left++;
        }

        // Update the maximum length
        maxi = max(maxi, (right - left + 1));
        right++;
    }

    return maxi;
}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        int n, k;
        cout << "\nEnter the size of the array (n) and the value of k: ";
        cin >> n >> k;

        vector<int> nums(n);
        cout << "Enter " << n << " elements of the array (0s and 1s): ";
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        // Call both implementations
        int bruteForceResult = maxConsecutive(nums, k);
        int optimizedResult = maxConsecutiveOptimal(nums, k);

        cout << "Brute Force Result: " << bruteForceResult << endl;
        cout << "Optimized Result: " << optimizedResult << endl;
    }

    return 0;
}

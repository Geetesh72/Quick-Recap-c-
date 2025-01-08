#include <bits/stdc++.h>
using namespace std;

/*
Problem Description:
Given an integer array `nums` and an integer `k`, return the number of contiguous subarrays 
that contain exactly `k` distinct integers.

Examples:
1. Input: nums = [1, 2, 1, 2, 3], k = 2
   Output: 7
   Explanation: The subarrays with exactly 2 distinct integers are: 
   [1, 2], [2, 1], [1, 2], [2, 3], [1, 2, 1], [2, 1, 2], [1, 2, 3].

2. Input: nums = [1, 2, 1, 2, 3], k = 3
   Output: 2
   Explanation: The subarrays with exactly 3 distinct integers are: 
   [1, 2, 3], [2, 1, 2, 3].

3. Input: nums = [1, 2, 1, 2, 3], k = 1
   Output: 4
   Explanation: The subarrays with exactly 1 distinct integer are: 
   [1], [2], [1], [2].
*/

// Brute Force Approach to count subarrays with exactly `k` distinct integers
int kdifferentInteger(vector<int>& nums, int k) {
    int n = nums.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        unordered_map<int, int> umap;
        for (int j = i; j < n; j++) {
            umap[nums[j]]++;
            if (umap.size() == k) {
                cnt++;
            }
            else if (umap.size() > k) {
                break;
            }
        }
    }
    return cnt;
}

// Optimal Approach using Sliding Window to count subarrays with at most `k` distinct integers
int integerDifferent(vector<int>& nums, int k) {
    int n = nums.size();
    int right = 0, left = 0;
    int cnt = 0;
    unordered_map<int, int> umap;

    while (right < n) {
        umap[nums[right]]++;  // Add the current number to the map

        // Shrink the window until there are at most `k` distinct integers
        while (umap.size() > k) {
            umap[nums[left]]--;
            if (umap[nums[left]] == 0) {
                umap.erase(nums[left]);
            }
            left++;
        }

        // Count the number of subarrays with at most `k` distinct integers
        cnt += (right - left + 1);
        right++;
    }

    return cnt;
}

// Final Function to calculate subarrays with exactly `k` distinct integers
int finalFunction(vector<int>& nums, int k) {
    return integerDifferent(nums, k) - integerDifferent(nums, k - 1);
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

        cout << "Enter the value of k (number of distinct integers): ";
        cin >> k;

        int result = finalFunction(nums, k);

        cout << "\nResult:\n";
        cout << "Number of subarrays with exactly " << k << " distinct integers: " << result << endl;
    }

    return 0;
}

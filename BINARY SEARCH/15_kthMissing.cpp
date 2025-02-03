#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
- Given a sorted array `nums` (1-indexed), find the `k`-th missing positive integer.

Approach:
1. Brute Force:
   - Iterate through the array and simulate finding the missing numbers one by one.
   - Complexity: O(n).

2. Optimal Approach (Binary Search):
   - Use binary search to locate the range where the k-th missing number lies.
   - At any index `mid`, calculate the count of missing numbers using:
     `missing = nums[mid] - (mid + 1)`.
   - Adjust the search range based on the count of missing numbers compared to `k`.
   - Complexity: O(log n).
*/

/*
Brute Force Solution:
Find the k-th missing positive integer by simulating the process.
- nums: Sorted input array.
- kth: The k-th missing number to find.
*/
int kthMissingBrute(vector<int>& nums, int kth) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] <= kth) {
            kth++; // Increment k for every number present in the array.
        } else {
            break; // Stop once we exceed kth.
        }
    }
    return kth;
}

/*
Optimal Solution (Binary Search):
- nums: Sorted input array.
- k: The k-th missing number to find.
*/
int kthMissing(vector<int>& nums, int k) {
    int n = nums.size();
    int low = 0;
    int high = n - 1;

    // Binary search to narrow down the range where the k-th missing number lies.
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Calculate how many numbers are missing up to index `mid`.
        int missing = nums[mid] - (mid + 1);

        if (missing < k) {
            low = mid + 1; // Move right to search for more missing numbers.
        } else {
            high = mid - 1; // Move left to reduce the number of missing numbers.
        }
    }

    // At the end of the loop, `low` points to the position where the k-th missing number lies.
    return low + k;
}

int main() {
    vector<int> nums = {2, 3, 4, 7, 11}; // Example input.
    int k = 5; // Find the 5th missing number.

    // Brute force approach.
    cout << "K-th missing (Brute Force): " << kthMissingBrute(nums, k) << endl;

    // Optimal approach.
    cout << "K-th missing (Binary Search): " << kthMissing(nums, k) << endl;

    return 0;
}

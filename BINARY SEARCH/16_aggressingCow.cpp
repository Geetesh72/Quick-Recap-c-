#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
- Given a sorted array `nums` representing the positions of stalls, place `cows` such that
  the minimum distance between any two cows is maximized.

Approach:
1. Sort the array to ensure the stalls are arranged in increasing order.
2. Use binary search to determine the maximum possible minimum distance.
   - Range for binary search: [1, max(nums) - min(nums)].
3. Use a helper function `canWePlace` to check if it is possible to place the cows
   with at least `mid` distance between them.

Key Idea:
- The goal is to maximize the minimum distance, which can be solved using binary search on the possible distances.

*/

/*
Helper Function:
- Check if it is possible to place `cows` with at least `dis` distance between them.
- nums: Sorted array of stall positions.
- dis: Minimum distance to check.
- cows: Number of cows to place.
*/
bool canWePlace(vector<int>& nums, int dis, int cows) {
    int n = nums.size();
    int cntCows = 1;        // Place the first cow in the first stall.
    int lastCow = nums[0];  // Position of the last placed cow.

    for (int i = 1; i < n; i++) {
        // Place a cow if the distance between the current stall and the last cow is >= dis.
        if (nums[i] - lastCow >= dis) {
            cntCows++;
            lastCow = nums[i]; // Update the position of the last placed cow.
        }
    }

    // Check if we were able to place all cows.
    return cntCows >= cows;
}

/*
Main Function:
- Determine the largest minimum distance to place `cow` cows in stalls at `nums`.
- nums: Array of stall positions (not necessarily sorted).
- cow: Number of cows to place.
*/
int aggressiveCow(vector<int>& nums, int cow) {
    int n = nums.size();
    sort(nums.begin(), nums.end());  // Sort the stall positions.

    int low = 1;                           // Minimum possible distance.
    int high = nums[n - 1] - nums[0];      // Maximum possible distance.
    int ans = -1;

    // Binary search to find the maximum minimum distance.
    while (low <= high) {
        int mid = low + (high - low) / 2;  // Midpoint of the current range.

        if (canWePlace(nums, mid, cow)) {
            ans = mid;  // Update the answer to the current mid.
            low = mid + 1;  // Try for a larger distance.
        } else {
            high = mid - 1;  // Try for a smaller distance.
        }
    }

    return ans;  // The largest minimum distance.
}

int main() {
    vector<int> nums = {1, 2, 8, 4, 9};  // Example input (stall positions).
    int cows = 3;  // Number of cows to place.

    cout << "Largest Minimum Distance: " << aggressiveCow(nums, cows) << endl;

    return 0;
}

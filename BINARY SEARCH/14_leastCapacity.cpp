#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
- Given an array `nums` where each element represents the weight of a package.
- Find the minimum ship capacity (`cap`) such that all packages can be shipped within `days` days.

Approach:
1. Use binary search to find the minimum capacity.
2. The range for binary search is `[max(nums), sum(nums)]`.
   - `max(nums)`: The ship must at least accommodate the heaviest package.
   - `sum(nums)`: The ship capacity cannot exceed the total weight of all packages.
3. Use a helper function `shipCapacity()` to calculate the number of days required for a given ship capacity.
4. Adjust the search range based on the result of `shipCapacity()`.

Helper Function (`shipCapacity()`):
- Calculates the number of days required to ship all packages with a given capacity (`cap`).
*/

/*
Helper Function:
Calculates the number of days required to ship all packages with a given capacity.
- nums: Array of package weights.
- cap: Ship capacity being tested.
*/
int shipCapacity(vector<int>& nums, int cap) {
    int n = nums.size();
    int day = 1;  // At least one day is required.
    int load = 0; // Current load on the ship.

    for (int i = 0; i < n; i++) {
        // If adding the current package exceeds capacity, move to the next day.
        if (load + nums[i] > cap) {
            day++;
            load = nums[i]; // Start new day with the current package.
        } else {
            load += nums[i]; // Add package to current day's load.
        }
    }
    return day;
}

/*
Binary Search Function:
Finds the minimum ship capacity such that all packages can be shipped within `days`.
- nums: Array of package weights.
- days: Maximum number of days allowed to ship all packages.
*/
int noOfDays(vector<int>& nums, int days) {
    int n = nums.size();
    int low = *max_element(nums.begin(), nums.end());       // Minimum capacity (heaviest package).
    int high = accumulate(nums.begin(), nums.end(), 0);     // Maximum capacity (sum of all packages).
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // Midpoint of the current capacity range.
        int daysReq = shipCapacity(nums, mid); // Calculate days required for capacity `mid`.

        if (daysReq <= days) {
            ans = mid;      // Valid capacity found, try to minimize further.
            high = mid - 1; // Search in the left half.
        } else {
            low = mid + 1;  // Increase capacity, search in the right half.
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Example input.
    int days = 5; // Maximum number of days.

    int result = noOfDays(nums, days);
    cout << "Minimum ship capacity to ship all packages in " << days << " days: " << result << endl;

    return 0;
}

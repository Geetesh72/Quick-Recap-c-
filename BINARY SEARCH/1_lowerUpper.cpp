#include <bits/stdc++.h>
using namespace std;

// Function to find the lower bound (first index where element >= target)
// TC: O(log N), SC: O(1)
int lowerBound(vector<int>& nums, int target) {
    int n = nums.size();
    int ans = -1; // Store the result index
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Avoid potential overflow
        if (nums[mid] >= target) {
            ans = mid;      // Potential lower bound found
            high = mid - 1; // Move left to find the first occurrence
        } else {
            low = mid + 1; // Move right
        }
    }

    // For validation with STL function
    int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    return ans == -1 ? n : ans; // Return n if no valid lower bound is found
}

// Function to find the upper bound (first index where element > target)
// TC: O(log N), SC: O(1)
int upperBound(vector<int>& nums, int target) {
    int n = nums.size();
    int ans = -1; // Store the result index
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Avoid potential overflow
        if (nums[mid] > target) {
            ans = mid;      // Potential upper bound found
            high = mid - 1; // Move left
        } else {
            low = mid + 1; // Move right
        }
    }

    // For validation with STL function
    int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
    return ans == -1 ? n : ans; // Return n if no valid upper bound is found
}

// Function to find the floor of an element (largest element <= x)
// TC: O(log N), SC: O(1)
int floor(vector<int>& nums, int x) {
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = -1; // Store the result value

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] <= x) {
            ans = nums[mid]; // Update the floor value
            low = mid + 1;   // Move right to find a larger floor
        } else {
            high = mid - 1; // Move left
        }
    }
    return ans; // Return -1 if no floor exists
}

// Function to find the ceiling of an element (smallest element >= x)
// TC: O(log N), SC: O(1)
int ceil(vector<int>& nums, int x) {
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = -1; // Store the result value

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= x) {
            ans = nums[mid]; // Update the ceiling value
            high = mid - 1;  // Move left to find a smaller ceiling
        } else {
            low = mid + 1; // Move right
        }
    }
    return ans; // Return -1 if no ceiling exists
}

/* 
 * Managing dynamic array changes (when array size changes after searching):
 * - If we need to remove the found element after searching, use `erase`:
 *      nums.erase(nums.begin() + index);
 *   This reduces the size of the array.
 * - If you need to add an element, use `insert`:
 *      nums.insert(nums.begin() + position, element);
 * - These operations change the array size and indices, so take care of subsequent operations.
 */

int main() {
    // Example usage of the functions
    vector<int> nums = {1, 3, 5, 7, 9};
    int target = 5;

    // Lower bound
    int lb = lowerBound(nums, target);
    cout << "Lower Bound Index: " << lb << endl;

    // Upper bound
    int ub = upperBound(nums, target);
    cout << "Upper Bound Index: " << ub << endl;

    // Floor
    int floorValue = floor(nums, target - 1);
    cout << "Floor Value: " << floorValue << endl;

    // Ceiling
    int ceilValue = ceil(nums, target + 1);
    cout << "Ceil Value: " << ceilValue << endl;

    return 0;
}

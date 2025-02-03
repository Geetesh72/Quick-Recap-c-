#include <bits/stdc++.h>
using namespace std;

/*
Logic:
1. The array is rotated and sorted, so the smallest element will be the point of rotation.
2. In each iteration, determine which part of the array (left or right) to explore.
   - If `nums[low] <= nums[mid]`, the left part is sorted. The smallest element must either be `nums[low]` or in the right part.
   - Otherwise, the right part is unsorted, and the smallest element lies in the right part, so adjust `high = mid - 1`.
3. Update the `mini` variable to keep track of the smallest element encountered so far.
4. Continue until `low > high`.

Key Points to Remember:
- The smallest element is the point of rotation.
- In a sorted (non-rotated) array, the smallest element is at `nums[0]`.
- Time Complexity: O(log N), as the binary search halves the search space at each step.
- Space Complexity: O(1), since no extra space is used.

Edge Cases:
- The array is not rotated (already sorted).
- Single element in the array.
- All elements are identical (handle gracefully).
*/

int miniRotated(vector<int>& nums) {
    int n = nums.size();
    int mini = INT_MAX; // Variable to store the minimum element
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // If the left part is sorted
        if (nums[low] <= nums[mid]) {
            // Update mini with the smallest element in the left sorted part
            mini = min(mini, nums[low]);
            low = mid + 1; // Move to the right part
        } else { // Otherwise, the right part is unsorted
            // Update mini with the mid element (potential minimum)
            mini = min(mini, nums[mid]);
            high = mid - 1; // Move to the left part
        }
    }

    return mini; // Return the smallest element found
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    // Find the minimum element in the rotated sorted array
    int minElement = miniRotated(nums);
    cout << "The minimum element in the rotated sorted array is: " << minElement << endl;

    return 0;
}

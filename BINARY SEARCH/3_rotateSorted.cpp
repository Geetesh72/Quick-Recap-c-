#include <bits/stdc++.h>
using namespace std;

/*
Logic:
1. The array is rotated and sorted. This means one part (either left or right of the pivot) will always be sorted.
2. Identify the sorted part of the array at each iteration using the `nums[mid]` and `nums[low]` or `nums[high]` comparison.
   - If `nums[mid] >= nums[low]`, the left part is sorted.
   - Otherwise, the right part is sorted.
3. Once the sorted part is identified:
   - If the target lies within the sorted range, reduce the search space to that range.
   - Otherwise, explore the unsorted part.
4. Repeat until `low > high` or the target is found.
5. The binary search is applied iteratively, ensuring O(log N) time complexity.

Key Points to Remember:
- The array is rotated, so it might have two separate increasing sequences.
- Always check which part of the array is sorted before deciding the next search space.
- Handle duplicates carefully (if present, not covered here).
- Time Complexity: O(log N), as we halve the search space at every step.
- Space Complexity: O(1), as it uses iterative binary search.

Edge Cases:
- Target not found in the array.
- The array is not rotated (simple sorted array).
- Single element in the array.
- Target equals the pivot element.
*/

int rotatedSorted(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // If the target is found
        if (nums[mid] == target) {
            return mid;
        }

        // Check if the left part is sorted
        if (nums[mid] >= nums[low]) {
            // If the target lies in the sorted left part
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1; // Search in the left part
            } else {
                low = mid + 1;  // Search in the right part
            }
        } else { // Otherwise, the right part is sorted
            // If the target lies in the sorted right part
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;  // Search in the right part
            } else {
                high = mid - 1; // Search in the left part
            }
        }
    }

    // If the target is not found
    return -1;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int result = rotatedSorted(nums, target);
    if (result != -1) {
        cout << "Target " << target << " found at index " << result << endl;
    } else {
        cout << "Target " << target << " not found in the array." << endl;
    }

    return 0;
}

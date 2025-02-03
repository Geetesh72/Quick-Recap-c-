#include <bits/stdc++.h>
using namespace std;

/*
Logic:
1. The number of rotations in a rotated sorted array corresponds to the index of the minimum element.
2. To find the index of the minimum element:
   - If the array segment is already sorted (`nums[low] <= nums[high]`), the smallest element is at `nums[low]`.
   - Otherwise, use binary search to determine the unsorted part (where the minimum lies).
3. Keep track of the smallest element and its index (`ans`) during the search.
4. The final value of `ans` gives the number of rotations (index of the smallest element).

Key Points to Remember:
- A rotation means that the smallest element moves to a new position, and its index corresponds to the number of rotations.
- Time Complexity: O(log N), as binary search reduces the search space by half in each step.
- Space Complexity: O(1), since no additional space is used.

Edge Cases:
- The array is not rotated (already sorted).
- Single element in the array.
- All elements are identical (handle gracefully).
*/

int findKRotation(vector<int>& nums) {
    int n = nums.size();
    int mini = INT_MAX; // Variable to store the minimum element
    int ans = 0;        // Variable to store the index of the minimum element
    int low = 0, high = n - 1;

    while (low <= high) {
        // If the current segment is already sorted
        if (nums[low] <= nums[high]) {
            if (nums[low] < mini) {
                mini = nums[low];
                ans = low;
            }
            break; // No need to search further
        }

        int mid = low + (high - low) / 2;

        // If the left part is sorted
        if (nums[low] <= nums[mid]) {
            if (nums[low] < mini) {
                mini = nums[low];
                ans = low;
            }
            low = mid + 1; // Move to the right part
        } else { // Otherwise, the right part is unsorted
            if (nums[mid] < mini) {
                mini = nums[mid];
                ans = mid;
            }
            high = mid - 1; // Move to the left part
        }
    }

    return ans; // Return the index of the minimum element (number of rotations)
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    // Find the number of rotations in the rotated sorted array
    int rotations = findKRotation(nums);
    cout << "The array is rotated " << rotations << " times." << endl;

    return 0;
}

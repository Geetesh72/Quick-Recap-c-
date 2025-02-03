#include <bits/stdc++.h>
using namespace std;

/*
Logic:
1. A peak element in the array is greater than its neighbors.
2. If the array has only one element, that is the peak.
3. If the first element is greater than the second, it is a peak.
4. If the last element is greater than the second last, it is a peak.
5. For other cases, use binary search:
   - If the middle element is greater than its neighbors, it is the peak.
   - If the left neighbor is greater, move to the left half.
   - Otherwise, move to the right half.

Key Points:
- Binary search ensures the time complexity is O(log N).
- The array is not necessarily sorted, but binary search works because at least one peak always exists in a contiguous array.

Edge Cases:
- Single-element array.
- Array of size two.
- The peak is at the start or end of the array.
*/

int peakElement(vector<int>& nums) {
    int n = nums.size();
    int low = 1;       // Start from the second element
    int high = n - 2;  // End before the last element

    // Handle edge cases
    if (n == 1) {
        return nums[0]; // Single element is the peak
    }
    if (nums[0] > nums[1]) {
        return nums[0]; // Peak at the start
    }
    if (nums[n - 1] > nums[n - 2]) {
        return nums[n - 1]; // Peak at the end
    }

    // Binary search for the peak element
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if the current element is a peak
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
            return nums[mid];
        }

        // Move to the side that might contain the peak
        if (nums[mid - 1] > nums[mid]) {
            high = mid - 1; // Peak is in the left half
        } else {
            low = mid + 1; // Peak is in the right half
        }
    }

    return -1; // Should not reach here if input is valid
}

int main() {
    // Example usage
    vector<int> nums = {1, 2, 3, 1};
    cout << "The peak element is: " << peakElement(nums) << endl;

    return 0;
}

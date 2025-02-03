#include <bits/stdc++.h>
using namespace std;

/*
Logic:
1. The array is sorted, and all elements except one appear exactly twice. The goal is to find the single element.
2. Key observation: 
   - Pairs of duplicate elements divide the array into left and right halves.
   - If `mid` is even and `nums[mid] == nums[mid + 1]`, the single element is in the right half.
   - If `mid` is odd and `nums[mid] == nums[mid - 1]`, the single element is in the right half.
   - Otherwise, the single element is in the left half.
3. Using binary search, the search space is halved in each step to efficiently locate the single element.

Key Points to Remember:
- This approach works because the array is sorted, and the property of even-odd indices helps to identify the halves.
- Time Complexity: O(log N), as binary search is used.
- Space Complexity: O(1), as no additional space is used.

Edge Cases:
- Single-element array.
- The single element is at the start or end of the array.
*/

int singleElement(vector<int>& nums) {
    int n = nums.size();
    int low = 1;      // Start searching from the second element
    int high = n - 2; // End before the last element

    // Edge cases: single-element array or the single element is at the boundary
    if (n == 1) return nums[0];
    if (nums[0] != nums[1]) return nums[0];
    if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

    // Binary search to find the single element
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if the current mid element is the single element
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
            return nums[mid];
        }

        // Determine which half to search based on the pairing property
        if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || 
            (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
            low = mid + 1; // Single element is in the right half
        } else {
            high = mid - 1; // Single element is in the left half
        }
    }

    return -1; // Should not reach here if the input is valid
}

int main() {
    // Example usage
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5, 5};
    cout << "The single element is: " << singleElement(nums) << endl;

    return 0;
}

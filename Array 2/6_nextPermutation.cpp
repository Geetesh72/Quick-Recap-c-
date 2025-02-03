#include <bits/stdc++.h>
using namespace std;

/* 
Function: nextGreaterPermutation
Uses the STL `next_permutation` function to find the next greater permutation.
Approach:
- `next_permutation` automatically modifies the array to the next lexicographically greater permutation.
- If the array is already in descending order, it transforms it into ascending order (smallest permutation).
*/
vector<int> nextGreaterPermutation(vector<int>& nums) {
    int n = nums.size();
    next_permutation(nums.begin(), nums.end());
    return nums;
}

/* 
Function: nGp (Custom Implementation)
Approach and Logic:
1. Find the "break point" (from the end, where nums[i] < nums[i+1]) — this is the first index where we can rearrange to make a larger permutation.
2. If no break point exists (array is in descending order), reverse the array to get the smallest permutation.
3. Find the smallest element larger than nums[breakIdx] to the right of the break point.
4. Swap nums[breakIdx] with that element.
5. Reverse the subarray to the right of the break point to make it the smallest lexicographical order.
*/
vector<int> nGp(vector<int>& nums) {
    int n = nums.size();
    int breakIdx = -1;

    // Step 1: Find the break point
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            breakIdx = i;
            break;
        }
    }

    // Step 2: If no break point, reverse the array (smallest permutation)
    if (breakIdx == -1) {
        reverse(nums.begin(), nums.end());
        return nums;
    }

    // Step 3: Find the smallest element larger than nums[breakIdx] to the right
    for (int i = n - 1; i > breakIdx; i--) {
        if (nums[i] > nums[breakIdx]) {
            swap(nums[i], nums[breakIdx]);
            break;
        }
    }

    // Step 4: Reverse the elements to the right of the break point
    reverse(nums.begin() + breakIdx + 1, nums.end());
    return nums;
}

int main() {
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--) {
        int n;
        cout << "Enter the size of the array: ";
        cin >> n;

        vector<int> nums(n);
        cout << "Enter the elements of the array: " << endl;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        // Test the STL-based next greater permutation
        cout << "Next Greater Permutation (STL): ";
        vector<int> result1 = nextGreaterPermutation(nums);
        for (int num : result1) {
            cout << num << " ";
        }
        cout << endl;

        // Test the custom next greater permutation function
        cout << "Next Greater Permutation (Custom): ";
        vector<int> result2 = nGp(nums);
        for (int num : result2) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

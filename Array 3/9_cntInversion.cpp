#include<bits/stdc++.h>
using namespace std;

/*
Problem: Count Inversions in an Array
An inversion is a pair (i, j) such that i < j and nums[i] > nums[j].
*/

/*
Approach 1: Brute Force
1. Use nested loops to compare each pair of elements.
2. Increment count if nums[i] > nums[j].
3. Time Complexity: O(n^2) - Nested loops.
   Space Complexity: O(1) - No extra space used.
*/
int countInversionBrute(vector<int>& nums) {
    int n = nums.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[i]) {
                cnt++;
            }
        }
    }
    return cnt;
}

/*
Approach 2: Optimal (Using Merge Sort)
1. Merge sort divides the array into smaller arrays.
2. During the merge step, count inversions by checking the left and right arrays.
3. If nums[i] > nums[j], all elements after nums[i] in the left array form inversions.
4. Time Complexity: O(n log n) - Due to merge sort.
   Space Complexity: O(n) - Temporary arrays used in merging.
*/
int mergeAndCount(vector<int>& nums, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;
    int cnt = 0;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp.push_back(nums[i++]);
        } else {
            temp.push_back(nums[j++]);
            cnt += (mid - i + 1); // All elements from i to mid are greater than nums[j].
        }
    }

    // Add remaining elements from both halves.
    while (i <= mid) temp.push_back(nums[i++]);
    while (j <= right) temp.push_back(nums[j++]);

    // Copy sorted elements back to the original array.
    for (int k = left; k <= right; k++) {
        nums[k] = temp[k - left];
    }

    return cnt;
}

int countInversionOptimal(vector<int>& nums, int left, int right) {
    if (left >= right) return 0;

    int mid = left + (right - left) / 2;
    int cnt = 0;

    // Count inversions in the left and right halves.
    cnt += countInversionOptimal(nums, left, mid);
    cnt += countInversionOptimal(nums, mid + 1, right);

    // Count inversions during the merge step.
    cnt += mergeAndCount(nums, left, mid, right);

    return cnt;
}

int main() {
    int t;
    cout << "\nEnter Number of Test Cases: ";
    cin >> t;

    while (t--) {
        cout << "\nEnter size of array: ";
        int n;
        cin >> n;
        vector<int> nums(n);

        cout << "\nEnter the elements of the array:\n";
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        // Brute force method
        int bruteCount = countInversionBrute(nums);
        cout << "\nNumber of Inversions (Brute Force): " << bruteCount;

        // Optimal method using merge sort
        vector<int> numsCopy = nums; // Copy original array for independent processing
        int optimalCount = countInversionOptimal(numsCopy, 0, n - 1);
        cout << "\nNumber of Inversions (Optimal): " << optimalCount << "\n";
    }

    return 0;
}

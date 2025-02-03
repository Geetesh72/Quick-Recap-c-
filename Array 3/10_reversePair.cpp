#include<bits/stdc++.h>
using namespace std;

/*
Problem: Count Reverse Pairs
A reverse pair is defined as a pair (i, j) such that i < j and nums[i] > 2 * nums[j].
*/

/*
Approach 1: Brute Force
1. Use nested loops to compare each pair of elements.
2. Increment count if nums[i] > 2 * nums[j].
3. Time Complexity: O(n^2) - Nested loops.
   Space Complexity: O(1) - No extra space used.
*/
int reversePairBrute(vector<int>& nums) {
    int n = nums.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] > 2LL * nums[j]) { // Use long long to prevent overflow
                cnt++;
            }
        }
    }
    return cnt;
}

/*
Approach 2: Optimal (Using Merge Sort)
1. During the merge step of merge sort, count the reverse pairs.
2. For each element in the left array, find the first index in the right array such that nums[i] <= 2 * nums[j].
3. Time Complexity: O(n log n) - Due to merge sort.
   Space Complexity: O(n) - Temporary arrays used in merging.
*/

int mergeAndCount(vector<int>& nums, int left, int mid, int right) {
    int cnt = 0;
    int j = mid + 1;

    // Count reverse pairs
    for (int i = left; i <= mid; i++) {
        while (j <= right && nums[i] > 2LL * nums[j]) {
            j++;
        }
        cnt += (j - mid - 1);
    }

    // Merge the two halves
    vector<int> temp;
    int i = left, k = mid + 1;
    while (i <= mid && k <= right) {
        if (nums[i] <= nums[k]) {
            temp.push_back(nums[i++]);
        } else {
            temp.push_back(nums[k++]);
        }
    }

    // Add remaining elements
    while (i <= mid) temp.push_back(nums[i++]);
    while (k <= right) temp.push_back(nums[k++]);

    // Copy sorted elements back to the original array
    for (int p = left; p <= right; p++) {
        nums[p] = temp[p - left];
    }

    return cnt;
}

int reversePairOptimal(vector<int>& nums, int left, int right) {
    if (left >= right) return 0;

    int mid = left + (right - left) / 2;
    int cnt = 0;

    // Count reverse pairs in the left and right halves
    cnt += reversePairOptimal(nums, left, mid);
    cnt += reversePairOptimal(nums, mid + 1, right);

    // Count reverse pairs during the merge step
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
        int bruteCount = reversePairBrute(nums);
        cout << "\nNumber of Reverse Pairs (Brute Force): " << bruteCount;

        // Optimal method using merge sort
        vector<int> numsCopy = nums; // Copy original array for independent processing
        int optimalCount = reversePairOptimal(numsCopy, 0, n - 1);
        cout << "\nNumber of Reverse Pairs (Optimal): " << optimalCount << "\n";
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

/*
Problem: Merge Two Sorted Arrays Without Extra Space
*/

/*
Approach 1: Using Extra Space (Brute Force)
1. Use a new array to store the elements from both arrays.
2. Compare elements of both arrays and merge them into the new array.
3. Time Complexity: O(n + m) - Linear traversal of both arrays.
   Space Complexity: O(n + m) - Additional space for storing the merged array.
*/
void mergeTwoSortedOne(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    vector<int> ans; // To store the merged array.
    int left = 0, right = 0;

    // Merge the arrays.
    while (left < n && right < m) {
        if (nums1[left] <= nums2[right]) {
            ans.push_back(nums1[left]);
            left++;
        } else {
            ans.push_back(nums2[right]);
            right++;
        }
    }

    // Add remaining elements from nums1.
    while (left < n) {
        ans.push_back(nums1[left]);
        left++;
    }

    // Add remaining elements from nums2.
    while (right < m) {
        ans.push_back(nums2[right]);
        right++;
    }

    // Print merged array.
    cout << "\nMerged Array (Using Extra Space): ";
    for (auto& num : ans) cout << num << " ";
    cout << endl;
}

/*
Approach 2: Swap and Sort (Optimal - Variation 1)
1. Swap elements between the two arrays if needed.
2. Sort both arrays after swapping.
3. Time Complexity: O(n log n + m log m) - Sorting dominates the complexity.
   Space Complexity: O(1) - In-place sorting.
*/
void mergeOptimal_1(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    int left = n - 1, right = 0;

    // Swap elements to correct positions.
    while (left >= 0 && right < m) {
        if (nums1[left] > nums2[right]) {
            swap(nums1[left], nums2[right]);
            left--;
            right++;
        } else {
            break;
        }
    }

    // Sort both arrays after swapping.
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
}

/*
Approach 3: Gap Method (Optimal - Variation 2)
1. Use the Shell Sort technique to compare elements with a gap.
2. Reduce the gap by half after each iteration.
3. Time Complexity: O((n + m) log(n + m)) - Based on the number of gap comparisons.
   Space Complexity: O(1) - In-place merging.
*/
void mergeOptimal_2(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    int len = n + m;
    int gap = (len / 2) + (len % 2); // Initial gap value.

    while (gap > 0) {
        int left = 0, right = left + gap;

        while (right < len) {
            // Compare elements in nums1 and nums2.
            if (left < n && right >= n) {
                if (nums1[left] > nums2[right - n]) {
                    swap(nums1[left], nums2[right - n]);
                }
            }
            // Compare elements within nums2.
            else if (left >= n) {
                if (nums2[left - n] > nums2[right - n]) {
                    swap(nums2[left - n], nums2[right - n]);
                }
            }
            // Compare elements within nums1.
            else {
                if (nums1[left] > nums1[right]) {
                    swap(nums1[left], nums1[right]);
                }
            }

            left++;
            right++;
        }

        if (gap == 1) break;
        gap = (gap / 2) + (gap % 2); // Update gap.
    }
}

int main() { 
    int t;
    cout << "\nEnter Number of Test Cases: ";
    cin >> t;

    while (t--) {
        cout << "\nEnter size of first array: ";
        int n;
        cin >> n;
        vector<int> nums1(n);
        cout << "Enter elements of the first array:\n";
        for (int i = 0; i < n; i++) {
            cin >> nums1[i];
        }

        cout << "\nEnter size of second array: ";
        int m;
        cin >> m;
        vector<int> nums2(m);
        cout << "Enter elements of the second array:\n";
        for (int i = 0; i < m; i++) {
            cin >> nums2[i];
        }

        // Example: Call the gap method for testing.
        mergeOptimal_2(nums1, nums2);

        // Print merged arrays.
        cout << "\nMerged Arrays (After Gap Method):\n";
        cout << "Array 1: ";
        for (auto& num : nums1) cout << num << " ";
        cout << "\nArray 2: ";
        for (auto& num : nums2) cout << num << " ";
        cout << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

/*
Optimal Solution for Median of Two Sorted Arrays:
1. Use binary search on the smaller array for efficiency.
2. Partition the arrays into left and right halves.
3. Use the concept of valid partitioning:
   - maxLeft1 <= minRight2
   - maxLeft2 <= minRight1
4. Calculate the median based on odd/even total size.
Time Complexity: O(log(min(n1, n2)))
Space Complexity: O(1)
*/

double median(vector<int> &a, vector<int> &b) {
    int n1 = a.size();
    int n2 = b.size();

    // Ensure binary search is performed on the smaller array
    if (n1 > n2) 
        return median(b, a);

    int low = 0, high = n1;
    int totalElements = n1 + n2;
    int half = (totalElements + 1) / 2;  // Left half size

    while (low <= high) {
        int mid1 = (low + high) >> 1;  // Partition for array a
        int mid2 = half - mid1;        // Remaining partition for array b

        // Left and right values from both arrays
        int left1 = (mid1 > 0) ? a[mid1 - 1] : INT_MIN;
        int left2 = (mid2 > 0) ? b[mid2 - 1] : INT_MIN;
        int right1 = (mid1 < n1) ? a[mid1] : INT_MAX;
        int right2 = (mid2 < n2) ? b[mid2] : INT_MAX;

        // Check for valid partitioning
        if (left1 <= right2 && left2 <= right1) {
            // Odd total elements
            if (totalElements % 2 == 1) 
                return max(left1, left2);

            // Even total elements
            return (double)(max(left1, left2) + min(right1, right2)) / 2.0;
        } 
        else if (left1 > right2) {
            high = mid1 - 1;  // Move partition left
        } 
        else {
            low = mid1 + 1;   // Move partition right
        }
    }

    return 0.0;  // This case should never occur
}

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    // Test case
    cout << "Median: " << median(nums1, nums2) << endl;  // Output: 2.0

    return 0;
}


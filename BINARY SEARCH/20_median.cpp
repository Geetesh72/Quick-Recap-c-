#include<bits/stdc++.h>
using namespace std;
/* What is median 

*/


/* 
Brute Force Approach:
1. Merge both sorted arrays into a single sorted array.
2. Calculate the median from the merged array.
Time Complexity: O(n + m) (merge step).
Space Complexity: O(n + m) (merged array).
*/
double medianBrute(vector<int>& nums, vector<int>& mums) {
    int n = nums.size();
    int m = mums.size();
    vector<int> merged;
    int i = 0, j = 0;

    // Merge the two sorted arrays
    while (i < n && j < m) {
        if (nums[i] < mums[j]) 
            merged.push_back(nums[i++]);
        else 
            merged.push_back(mums[j++]);
    }
    while (i < n) 
        merged.push_back(nums[i++]);
    while (j < m) 
        merged.push_back(mums[j++]);

    // Calculate the median
    int size = n + m;
    if (size % 2 == 1) 
        return merged[size / 2];
    else 
        return (double)(merged[size / 2] + merged[size / 2 - 1]) / 2.0;
}



// optimal 


/*
Optimal Approach:
1. Use two pointers to track the progress through both arrays.
2. Find the two middle elements required for the median calculation
   directly without merging the arrays.
Time Complexity: O(n + m) (one pass through both arrays).
Space Complexity: O(1) (no extra space used).
*/
double medianOptimal(vector<int>& nums, vector<int>& mums) {
    int n = nums.size();
    int m = mums.size();
    int totalSize = n + m;

    int medianIdx1 = totalSize / 2;           // Middle index
    int medianIdx2 = (totalSize % 2 == 0) ? medianIdx1 - 1 : medianIdx1; // Second middle index (for even-sized arrays)

    int i = 0, j = 0, count = 0;
    int median1 = 0, median2 = 0;

    // Traverse through both arrays to find the medians
    while (i < n || j < m) {
        int current;
        if (i < n && (j >= m || nums[i] <= mums[j])) {
            current = nums[i++];
        } else {
            current = mums[j++];
        }

        // Update the required median values
        if (count == medianIdx1) 
            median1 = current;
        if (count == medianIdx2) 
            median2 = current;

        count++;
        if (count > medianIdx1) 
            break;
    }

    // Calculate the final median
    return (totalSize % 2 == 0) ? (double)(median1 + median2) / 2.0 : (double)median1;
}

int main() {
    vector<int> nums = {1, 3, 8};
    vector<int> mums = {7, 9, 10, 11};

    // Brute Force
    cout << "Median (Brute Force): " << medianBrute(nums, mums) << endl;

    // Optimal
    cout << "Median (Optimal): " << medianOptimal(nums, mums) << endl;

    return 0;
}

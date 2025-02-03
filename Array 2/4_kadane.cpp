#include <bits/stdc++.h>
using namespace std;

// Brute-force approach to find the maximum subarray sum
int subArraySum(vector<int>& nums) {
    int n = nums.size();
    int maxiSum = INT_MIN; // Initialize to the smallest integer value

    // Traverse all subarrays using two loops
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];            // Calculate the sum of the current subarray
            maxiSum = max(maxiSum, sum); // Update the maximum sum
        }
    }
    return maxiSum;
}

/* Kadane's Algorithm: Optimal approach for maximum subarray sum
   Intuition:
   1. If the sum becomes negative at any point, reset it to 0 because including that
      portion will only decrease the sum.
   2. Keep track of the maximum sum encountered during the traversal.
*/
int kadane(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;          // Current subarray sum
    int maxi = INT_MIN;   // Maximum subarray sum found so far

    // Traverse the array
    for (int i = 0; i < n; i++) {
        sum += nums[i];         // Add the current element to the sum
        maxi = max(maxi, sum);  // Update the maximum sum if the current sum is greater

        // Reset sum to 0 if it becomes negative
        if (sum < 0) {
            sum = 0;
        }
    }
    return maxi;
}

/* Kadane's Algorithm (with Path): Find the subarray that gives the maximum sum
   Additional Tracking:
   1. Start index of the current subarray (`start`).
   2. Start and end indices of the maximum subarray (`ansStart` and `ansEnd`).
*/
vector<int> kadanePath(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;            // Current subarray sum
    int maxi = INT_MIN;     // Maximum subarray sum
    int start = -1;         // Start index of the current subarray
    int ansStart = -1;      // Start index of the maximum subarray
    int ansEnd = -1;        // End index of the maximum subarray

    // Traverse the array
    for (int i = 0; i < n; i++) {
        if (sum == 0) {
            start = i;      // Update the start index for a new subarray
        }
        sum += nums[i];     // Add the current element to the sum

        if (sum > maxi) {   // Update maximum sum and the indices of the subarray
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        if (sum < 0) {      // Reset the sum and the start index if the sum becomes negative
            sum = 0;
            start = -1;
        }
    }

    // Extract the subarray from `ansStart` to `ansEnd`
    vector<int> subArray(nums.begin() + ansStart, nums.begin() + ansEnd + 1);
    return subArray;
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

        // Call Kadane's Algorithm to get the maximum subarray sum
        cout << "Maximum Subarray Sum (Kadane's Algorithm): " << kadane(nums) << endl;

        // Call Kadane's Algorithm with path to get the subarray
        vector<int> result = kadanePath(nums);
        cout << "Maximum Subarray: ";
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

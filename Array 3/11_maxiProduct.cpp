#include<bits/stdc++.h>
using namespace std;

/*
Approach 1: Brute Force
1. Use nested loops to calculate the product of every possible subarray.
2. Update the maximum product found.
3. Time Complexity: O(n^2) - Due to nested loops.
   Space Complexity: O(1) - No extra space used.
*/
int maxProductBrute(vector<int>& nums) {
    int n = nums.size();
    int maxi = INT_MIN; // Initialize to the smallest possible integer
    for (int i = 0; i < n; i++) {
        int prod = 1; // Initialize product for each subarray
        for (int j = i; j < n; j++) {
            prod *= nums[j];
            maxi = max(maxi, prod); // Update the maximum product
        }
    }
    return maxi;
}

/*
Approach 2: Optimal (Using Prefix and Suffix Products)
1. Traverse the array twice: once from left to right and once from right to left.
2. Maintain the prefix and suffix product, resetting to 1 if 0 is encountered.
3. Update the maximum product found.
4. Time Complexity: O(n) - Single traversal for prefix and suffix.
   Space Complexity: O(1) - No extra space used.
*/
int maxProductOptimal(vector<int>& nums) {
    int n = nums.size();
    int ans = INT_MIN;
    int pre = 1, suff = 1;

    for (int i = 0; i < n; i++) {
        if (pre == 0) pre = 1;  // Reset prefix product if 0 is encountered
        if (suff == 0) suff = 1; // Reset suffix product if 0 is encountered

        pre *= nums[i];           // Prefix product
        suff *= nums[n - i - 1];  // Suffix product
        ans = max(ans, max(pre, suff)); // Update the maximum product
    }
    return ans;
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
        int bruteResult = maxProductBrute(nums);
        cout << "\nMaximum Product Subarray (Brute Force): " << bruteResult;

        // Optimal method
        int optimalResult = maxProductOptimal(nums);
        cout << "\nMaximum Product Subarray (Optimal): " << optimalResult << "\n";
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

/* Brute Force Approach:
   - Iterate through all subarrays of the array.
   - Calculate the sum of each subarray and check if it equals `k`.
   - Time Complexity: O(n^2) for nested loops.
   - Space Complexity: O(1).
*/
int subarrayCountBrute(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            if (sum == k) {
                count++;
            }
        }
    }

    return count;
}

/* Optimal Approach using Hash Map:
   - Maintain a running prefix sum (`preSum`) while iterating through the array.
   - Use a hash map to store the frequency of prefix sums encountered so far.
   - For each element:
       1. Compute the current `preSum`.
       2. Check if `preSum - k` exists in the hash map.
          If it exists, it means there is a subarray with a sum of `k`.
       3. Increment the count by the frequency of `preSum - k`.
       4. Add the current `preSum` to the hash map.
   - Time Complexity: O(n) for a single traversal.
   - Space Complexity: O(n) for the hash map.
*/
int subarrayCountOptimal(vector<int>& nums, int k) {
    int n = nums.size();
    int preSum = 0;            // Current prefix sum
    int count = 0;             // Count of subarrays with sum = k
    unordered_map<int, int> umap;  // Hash map to store prefix sum frequencies

    // Base case: to handle subarrays starting at index 0
    umap[0] = 1;

    for (int i = 0; i < n; i++) {
        preSum += nums[i];       // Update the prefix sum

        // Check if there exists a prefix sum such that preSum - k exists
        int remove = preSum - k;
        if (umap.find(remove) != umap.end()) {
            count += umap[remove];
        }

        // Update the frequency of the current prefix sum
        umap[preSum]++;
    }

    return count;
}

int main() {
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--) {
        int n, k;
        cout << "Enter the size of the array: ";
        cin >> n;

        cout << "Enter the sum k to find subarrays: ";
        cin >> k;

        vector<int> nums(n);
        cout << "Enter the elements of the array: " << endl;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        // Brute Force Result
        int bruteResult = subarrayCountBrute(nums, k);
        cout << "Brute Force Result: " << bruteResult << endl;

        // Optimal Result
        int optimalResult = subarrayCountOptimal(nums, k);
        cout << "Optimal Result: " << optimalResult << endl;
    }

    return 0;
}

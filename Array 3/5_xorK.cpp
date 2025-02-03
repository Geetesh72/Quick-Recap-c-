#include<bits/stdc++.h>
using namespace std;

/* 
Problem: Count the number of subarrays whose XOR equals a given value `k`.
*/

/* 
Brute Force Approach:
1. Use two nested loops to iterate through all possible subarrays.
2. Compute the XOR of each subarray.
3. Check if the XOR of the subarray equals `k`. If yes, increment the count.
Time Complexity: O(n^2) - Two nested loops to generate all subarrays.
Space Complexity: O(1) - No extra space is used.
*/
int xorSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int xorr = 0; // Initialize XOR for each starting index.
        for (int j = i; j < n; j++) { // Subarray ending index.
            xorr ^= nums[j];
            if (xorr == k) {
                cnt++;
            }
        }
    }
    return cnt;
}

/* 
Optimal Approach:
1. Use an unordered map (hashmap) to store the frequency of XOR values encountered so far.
2. For each element in the array:
   - Compute the cumulative XOR up to the current element.
   - Calculate the required XOR (`req`) that would make the subarray XOR equal to `k`: `req = k ^ cumulativeXOR`.
   - If `req` exists in the hashmap, add its frequency to the count (this represents the number of valid subarrays ending at the current index).
   - Update the hashmap with the current cumulative XOR value.
3. Return the count of subarrays.
Time Complexity: O(n) - Single traversal of the array with constant-time hashmap operations.
Space Complexity: O(n) - Space used by the hashmap to store XOR frequencies.
*/
int xorOptimal(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> umap;
    int cnt = 0;
    int xorr = 0;
    umap[0] = 1; // Handle cases where a prefix XOR equals `k`.

    for (int i = 0; i < n; i++) {
        xorr ^= nums[i]; // Compute cumulative XOR.
        int req = k ^ xorr; // Calculate the required XOR to form a valid subarray.
        if (umap.find(req) != umap.end()) {
            cnt += umap[req];
        }
        umap[xorr]++; // Update the frequency of the current XOR.
    }
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
        cout << "\nEnter the elements of the array: ";
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        cout << "\nEnter the target XOR value: ";
        int k;
        cin >> k;

        // Example: Call the optimal solution for testing
        int result = xorOptimal(nums, k);
        cout << "Number of subarrays with XOR equal to " << k << ": " << result << endl;
    }

    return 0;
}

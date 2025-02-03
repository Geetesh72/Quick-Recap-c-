#include<bits/stdc++.h>
using namespace std;

// Brute force approach: Find the longest subarray with sum k (only for positive numbers)
int longestSumArray(vector<int>& nums, int k) {
    int n = nums.size();
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        int len = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
          if (sum == k) {
                len = j - i + 1;
                maxi = max(maxi, len);
            }
        }
    }
    return maxi;
}

// Better approach: Works for arrays with both positive and negative numbers
int longestSub(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> umap; // Map to store prefix sums and their first occurrence index
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];

        // Check if the entire subarray from 0 to i has sum k
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // Check if there exists a prefix sum equal to (sum - k)
        int rem = sum - k;
        if (umap.find(rem) != umap.end()) {
            maxLen = max(maxLen, i - umap[rem]);
        }

        // Store the prefix sum only if it is not already present
        if (umap.find(sum) == umap.end()) {
            umap[sum] = i;
        }
    }
    return maxLen;
}

// Optimal approach: Sliding window (only for positive numbers or with zeros)
int lenOfSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    int maxLen = 0;
    int left = 0;
    int right = 0;
    int sum = 0;

    while (right < n) {
        sum += nums[right];

        // Shrink the window if the sum exceeds k
        while (sum > k && left <= right) {
            sum -= nums[left];
            left++;
        }

        // Check if the current window has sum k
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    return maxLen;
}

int main() {
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;
    while (t--) {
        int n, k;
        cout << "Enter the size of the array: ";
        cin >> n;
        vector<int> nums(n);

        cout << "Enter the elements of the array: \n";
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        cout << "Enter the target sum (k): ";
        cin >> k;

        cout << "Brute force solution (longest subarray sum = k): " << longestSumArray(nums, k) << endl;
        cout << "Hashmap solution (works for positive and negative numbers): " << longestSub(nums, k) << endl;
        cout << "Sliding window solution (only for positives and zeros): " << lenOfSubarray(nums, k) << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

/*
    ===========================================
    ||   FIND K MAX SUM COMBINATIONS        ||
    ===========================================

    📝 **Problem Statement**:
    Given two integer arrays `nums` and `mums` of size `N`, find the `K` maximum sum 
    combinations, where one element is taken from `nums` and one from `mums`.

    ✅ **Approach (Using Max Heap & Set for Uniqueness)**:
       - Sort both arrays in **ascending order**.
       - Use a **max heap** (priority queue) to store sum combinations.
       - Start with the largest possible sum (last elements from both arrays).
       - Use a **set** to track visited index pairs to avoid duplicates.
       - Extract **K maximum sums** using heap operations.

    🔥 **Time Complexity**: `O(K log K)`, since we insert and remove `K` elements from the heap.
*/

/**
 * Function: maxCombination
 * Finds the top K maximum sum combinations from two sorted arrays.
 */


/* coding brute forec;
*/

vector<int> maxCombinationB(vector<int>& nums, vector<int>& mums, int k) {
    int n = nums.size();
    int m = mums.size();
    vector<int> ans;

    // Generate all possible sum combinations
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sum = nums[i] + mums[j]; // Correct sum calculation
            ans.push_back(sum);
        }
    }

    // Sort sums in descending order
    sort(ans.rbegin(), ans.rend());

    // Extract the top K elements
    ans.resize(k);
    return ans;
}

vector<int> maxCombination(vector<int>& nums, vector<int>& mums, int k) {
    int n = nums.size();
    int m = mums.size();
    vector<int> ans;

    // Sort both arrays in ascending order
    sort(nums.begin(), nums.end());
    sort(mums.begin(), mums.end());

    // Max Heap to store {sum, (index1, index2)}
    priority_queue<pair<int, pair<int, int>>> pq;

    // Set to track visited pairs (i, j)
    set<pair<int, int>> st;

    // Start with the largest sum combination (last elements from both arrays)
    pq.push({nums.back() + mums.back(), {n - 1, m - 1}});
    st.insert({n - 1, m - 1});

    // Extract K maximum sum combinations
    while (k-- && !pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int sum = it.first;
        int i = it.second.first;
        int j = it.second.second;

        ans.push_back(sum); // Store the maximum sum

        // Check next possible pairs (left in nums, down in mums)
        if (i > 0 && st.find({i - 1, j}) == st.end()) {
            pq.push({nums[i - 1] + mums[j], {i - 1, j}});
            st.insert({i - 1, j});
        }
        if (j > 0 && st.find({i, j - 1}) == st.end()) {
            pq.push({nums[i] + mums[j - 1], {i, j - 1}});
            st.insert({i, j - 1});
        }
    }

    return ans;
}

// Test function
int main() {
    vector<int> nums = {4, 2, 5, 1};
    vector<int> mums = {8, 0, 3, 7};
    int k = 3;

    vector<int> result = maxCombination(nums, mums, k);
    cout << "Top " << k << " Maximum Sum Combinations: ";
    for (int sum : result) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}

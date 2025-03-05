#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Count the number of bad pairs in an array.

    Definition:
    - A pair (i, j) is a **bad pair** if:
      `j - i != nums[j] - nums[i]` (i.e., the difference in indices does not match the difference in values).

    Example 1:
    Input: nums = [4,1,3,3]
    Output: 5
    Explanation: The bad pairs are:
      (0,1), (0,2), (0,3), (1,2), (2,3)

    Example 2:
    Input: nums = [1,2,3,4,5]
    Output: 0
    Explanation: There are no bad pairs.

    Constraints:
    - 1 ≤ nums.length ≤ 10^5
    - 1 ≤ nums[i] ≤ 10^9

    **Naive Approach (Brute Force)**
    - Check every pair `(i, j)` to see if it satisfies the bad pair condition.
    - Time Complexity: **O(n^2)** → Inefficient for large inputs.

*/

long long countBadPair(vector<int>& nums) {
    int n = nums.size();
    long long ans = 0;
    
    // Brute force: Checking all pairs (i, j)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (j - i != nums[j] - nums[i]) {
                ans++;
            }
        }
    }
    return ans;
}

/*
    **Optimized Approach (Using HashMap)**
    Key Insight:
    - Rewrite the bad pair condition:
      `j - i != nums[j] - nums[i]`
      → `(nums[i] - i) != (nums[j] - j)`

    - If we compute `diff[i] = nums[i] - i` for every index,
      then a bad pair occurs when `diff[i]` is different for (i, j).

    - Use a **hashmap** to store the count of each `diff[i]` value.

    **Complexity:**
    - We traverse the array once, making `O(n)` insertions/queries.
    - Time Complexity: **O(n)**.
*/

long long countBadPair_1(vector<int>& nums) {
    int n = nums.size();
    long long badPairs = 0;
    unordered_map<int, int> umap;  // Store frequency of (nums[i] - i)

    for (int i = 0; i < n; i++) {
        int diff = nums[i] - i;

        // Number of elements seen before - count of `diff`
        // This counts the bad pairs at index i
        badPairs += i - umap[diff];

        // Update the frequency of this `diff`
        umap[diff]++;
    }
    return badPairs;
}

/*
    **Final Approach (Using Good Pairs)**
    Idea:
    - Instead of counting **bad pairs directly**, we count **good pairs** and subtract.
    - **Total pairs** in the array = `n * (n - 1) / 2`
    - **Good pairs** are those where `nums[i] - i == nums[j] - j`.
    - So, **bad pairs** = Total pairs - Good pairs.

    **Time Complexity: O(n)**
    - One pass to compute good pairs using a hashmap.
*/

long long countBadPair_2(vector<int>& nums) {
    int n = nums.size();
    long long totalPairs = (1LL * n * (n - 1)) / 2;  // Total pairs in array
    long long goodPairs = 0;
    unordered_map<int, int> umap;

    for (int i = 0; i < n; i++) {
        int diff = nums[i] - i;
        goodPairs += umap[diff];  // Count how many times this `diff` has appeared
        umap[diff]++;
    }

    // Bad pairs = Total pairs - Good pairs
    return totalPairs - goodPairs;
}

int main() {
    vector<int> nums = {4, 1, 3, 3};
    cout << "Bad Pairs (Brute Force): " << countBadPair(nums) << endl;
    cout << "Bad Pairs (Optimized): " << countBadPair_1(nums) << endl;
    cout << "Bad Pairs (Good Pair Subtraction): " << countBadPair_2(nums) << endl;
    return 0;
}

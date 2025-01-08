#include <bits/stdc++.h>
using namespace std;

/*
Problem Description:
You are given an array `nums` where each element represents the type of fruit collected from a tree.
Your task is to find the length of the longest subarray that contains at most `k` distinct types of fruits.

This is also known as the "Fruit Into Baskets" problem where each type of fruit corresponds to a unique number.

Input:
- `nums`: A vector of integers representing the types of fruits.
- `k`: An integer representing the maximum number of distinct fruits allowed in the subarray.

Output:
- Return the length of the longest subarray with at most `k` distinct elements.

Approaches:
1. **Brute Force:**
   - Use nested loops to iterate through all subarrays.
   - Check the distinct fruit types in each subarray using a set.
   - Complexity: O(n^2).

2. **Optimal Solution (Sliding Window):**
   - Use a sliding window with two pointers and an unordered_map to keep track of fruit counts.
   - Expand the window to the right and shrink it from the left when distinct fruit types exceed `k`.
   - Complexity: O(n).
*/

// Brute Force Solution
int fruitInto(vector<int> &nums, int k)
{
    int n = nums.size();
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        set<int> st;
        for (int j = i; j < n; j++)
        {
            st.insert(nums[j]);
            if (st.size() <= k)
            {
                maxi = max(maxi, (j - i + 1));
            }
        }
    }
    return maxi;
}

// Optimal Solution (Sliding Window)
int fruitIntoBasket(vector<int> &nums, int k)
{
    int n = nums.size();
    int right = 0, left = 0;
    int maxi = 0;
    unordered_map<int, int> umap; // Track the count of each fruit type

    while (right < n)
    {
        umap[nums[right]]++; // Include the current fruit in the basket

        // Shrink the window if distinct fruit types exceed `k`
        while (umap.size() > k)
        {
            umap[nums[left]]--;
            if (umap[nums[left]] == 0)
            {
                umap.erase(nums[left]); // Remove the fruit from the map
            }
            left++;
        }

        // Update the maximum length of the subarray
        if (umap.size() <= k)
        {
            maxi = max(maxi, (right - left + 1));
        }

        right++;
    }

    return maxi;
}

int main()
{
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--)
    {
        int n, k;
        cout << "\nEnter the size of the array (n) and the value of k: ";
        cin >> n >> k;

        vector<int> nums(n);
        cout << "Enter " << n << " elements of the array: ";
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        // Call both implementations
        int bruteForceResult = fruitInto(nums, k);
        int optimizedResult = fruitIntoBasket(nums, k);

        cout << "Brute Force Result: " << bruteForceResult << endl;
        cout << "Optimized Result: " << optimizedResult << endl;
    }

    return 0;
}

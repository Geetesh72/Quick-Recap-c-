#include <bits/stdc++.h>
using namespace std;

/* 
   Problem Description:
   Given an array nums of distinct positive integers, return the
   number of tuples (a, b, c, d) such that a * b = c * d,
   where a, b, c, and d are elements of nums, and a != b != c != d.

   Example 1:
   Input: nums = [2,3,4,6]
   Output: 8
   Explanation: There are 8 valid tuples:
   (2,6,3,4), (2,6,4,3), (6,2,3,4), (6,2,4,3)
   (3,4,2,6), (4,3,2,6), (3,4,6,2), (4,3,6,2)

   Constraints:
   1 <= nums.length <= 1000
   1 <= nums[i] <= 10^4
   All elements in nums are distinct.
*/

/* 
   Approach:
   - Since nums.length is at most 1000, an O(n^2) solution is feasible.
   - We calculate the product of all unique pairs (a, b) and store their frequencies in a hashmap.
   - If multiple pairs have the same product, they can be used to form valid tuples.
   - The total number of ways to select two such pairs is given by (freq * (freq - 1) / 2) [Combinations formula].
   - Each valid selection contributes exactly 8 valid permutations, hence we multiply by 8.
*/

int tupleSameProduct(vector<int> &nums)
{
    int n = nums.size();
    int cnt = 0;
    unordered_map<long long, long long> umap;

    // Compute the product of all unique pairs and store their frequency
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long long prod = (long long)nums[i] * nums[j];
            umap[prod]++;
        }
    }

    // Process the frequency map
    for (auto &[prod, freq] : umap)
    {
        if (freq > 1)
        {
            /*
               Explanation of the formula:
               - If a product appears 'freq' times in the map, it means there are 'freq' different pairs (a, b) that form the same product.
               - We need to select 2 out of these 'freq' pairs to form a valid tuple (a, b, c, d).
               - The number of ways to choose 2 pairs from 'freq' pairs is given by Combination formula: C(freq, 2) = (freq * (freq - 1) / 2).
               - Each such pair can form 8 different tuples due to different orderings (permutations of a, b, c, d).
               - So, we multiply the count by 8 to get the final contribution.
            */
            cnt += 8 * (freq * (freq - 1) / 2);
        }
    }

    return cnt;
}

int main()
{
    vector<int> nums = {2, 3, 4, 6};
    cout << "Number of valid tuples: " << tupleSameProduct(nums) << endl;
    return 0;
}

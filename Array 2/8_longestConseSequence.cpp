#include <bits/stdc++.h>
using namespace std;

/* 
Function: linearSearch
Purpose:
- Checks if a number `x` exists in the array `nums`.
Time Complexity: O(n)
Space Complexity: O(1)
*/
bool linearSearch(vector<int>& nums, int x) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] == x) {
            return true;
        }
    }
    return false;
}

/* 
Function: longestSequence
Approach:
- For each element in the array, find the length of the consecutive sequence starting from that element.
- Uses `linearSearch` to check for consecutive elements.
Time Complexity: O(n^2) (due to nested loops and linear search)
Space Complexity: O(1)
*/
int longestSequence(vector<int>& nums) {
    int n = nums.size();
    int longest = 1;

    for (int i = 0; i < n; i++) {
        int x = nums[i];
        int currentLength = 1;

        // Count the length of consecutive sequence
        while (linearSearch(nums, x + 1)) {
            x = x + 1;
            currentLength++;
        }

        longest = max(longest, currentLength);
    }
    return longest;
}

/* 
Function: longestSeq (Better Approach with Sorting)
Approach:
- Sort the array.
- Count the length of consecutive sequences while iterating.
- Avoid duplicates while counting.
Time Complexity: O(n log n) (sorting dominates)
Space Complexity: O(1)
*/
int longestSeq(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int longest = 1;
    int count = 1;

    for (int i = 1; i < n; i++) {
        if (nums[i] == nums[i - 1] + 1) {
            count++;
        } else if (nums[i] != nums[i - 1]) {
            count = 1;
        }
        longest = max(longest, count);
    }
    return longest;
}

/* 
Function: optimalSeq (Optimal Approach with Set)
Approach:
- Use a `set` to store unique elements of the array.
- For each element in the set, check if it is the start of a sequence (`num - 1` is not in the set).
- Count the length of the sequence by incrementing.
Time Complexity: O(n) (each element is processed once)
Space Complexity: O(n) (to store elements in the set)
*/
int optimalSeq(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    set<int> st(nums.begin(), nums.end());
    int longest = 1;

    for (auto num : st) {
        // Check if it is the start of a sequence
        if (st.find(num - 1) == st.end()) {
            int currentNum = num;
            int count = 1;

            // Count the length of the sequence
            while (st.find(currentNum + 1) != st.end()) {
                currentNum++;
                count++;
            }

            longest = max(longest, count);
        }
    }
    return longest;
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
        cout << "Enter the elements of the array:" << endl;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        // Brute-force approach
        cout << "Longest Consecutive Sequence (Brute-force): " << longestSequence(nums) << endl;

        // Better approach
        cout << "Longest Consecutive Sequence (Sorting): " << longestSeq(nums) << endl;

        // Optimal approach
        cout << "Longest Consecutive Sequence (Optimal): " << optimalSeq(nums) << endl;
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

/*
Problem: Find the Missing and Repeating Numbers
*/

/*
Approach 1: Brute Force
1. Count occurrences of each number using nested loops.
2. Identify the missing and repeating numbers.
3. Time Complexity: O(n^2) - Nested loop for counting.
   Space Complexity: O(1) - No extra space used.
*/
pair<int, int> missingRepeatingBrute(vector<int>& nums, int n) {
    int missing = -1, repeating = -1;

    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == i) {
                count++;
            }
        }

        if (count == 2) repeating = i;
        else if (count == 0) missing = i;

        if (missing != -1 && repeating != -1) break;
    }

    return {missing, repeating};
}

/*
Approach 2: Better (Using Hashing)
1. Use a hash array to store the frequency of each number.
2. Identify the missing and repeating numbers by their counts.
3. Time Complexity: O(n) - Single traversal to count and identify.
   Space Complexity: O(n) - Additional space for hash array.
*/
pair<int, int> missingRepeatingHashing(vector<int>& nums, int n) {
    vector<int> hashArray(n + 1, 0);
    int repeating = -1, missing = -1;

    for (int num : nums) {
        hashArray[num]++;
    }

    for (int i = 1; i <= n; i++) {
        if (hashArray[i] == 2) repeating = i;
        else if (hashArray[i] == 0) missing = i;

        if (repeating != -1 && missing != -1) break;
    }

    return {missing, repeating};
}

/*
Approach 3: Optimal (Using Mathematical Formulas)
1. Use the formula for the sum of n natural numbers (Sum_n).
2. Use the formula for the sum of squares of n natural numbers (Sum_n^2).
3. Derive equations to find missing and repeating numbers.
4. Time Complexity: O(n) - Single traversal for calculating sums.
   Space Complexity: O(1) - No extra space used.
*/
pair<int, int> missingRepeatingOptimal(vector<int>& nums) {
    long long n = nums.size();
    long long sum_n = n * (n + 1) / 2;
    long long sum_n2 = n * (n + 1) * (2 * n + 1) / 6;

    long long sum_nums = 0, sum_nums2 = 0;
    for (int i = 0; i < n; i++) {
        sum_nums += nums[i];
        sum_nums2 += (long long)nums[i] * nums[i];
    }

    long long diff = sum_nums - sum_n;           // x - y
    long long sum = (sum_nums2 - sum_n2) / diff; // x + y

    long long repeating = (sum + diff) / 2;
    long long missing = repeating - diff;

    return {(int)missing, (int)repeating};
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
        cout << "Enter the elements of the array:\n";
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        // Example: Call the optimal method for testing.
        pair<int, int> result = missingRepeatingOptimal(nums);

        // Output results.
        cout << "\nMissing Number: " << result.first;
        cout << "\nRepeating Number: " << result.second << "\n";
    }

    return 0;
}

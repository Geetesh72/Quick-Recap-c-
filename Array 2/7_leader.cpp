#include <bits/stdc++.h>
using namespace std;

/* 
Function: leader
Approach:
- Iterate through each element in the array.
- For each element, check all elements to its right.
- If no element to the right is greater, it is a leader.
Time Complexity: O(n^2)
Space Complexity: O(n) for the answer vector.
*/
vector<int> leader(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        int candidate = nums[i];
        bool isLeader = true;

        // Check if any element to the right is greater
        for (int j = i + 1; j < n; j++) {
            if (nums[j] > candidate) {
                isLeader = false;
                break;
            }
        }

        // If it remains a leader, add to result
        if (isLeader) {
            ans.push_back(candidate);
        }
    }
    return ans;
}

/* 
Function: optimalLeader
Approach:
- Traverse the array from right to left.
- Maintain the maximum element encountered so far (`maxi`).
- If the current element is greater than `maxi`, it is a leader.
- Add such elements to the result vector.
- Reverse the result vector since leaders are collected in reverse order.
Time Complexity: O(n)
Space Complexity: O(n) for the answer vector.
*/
vector<int> optimalLeader(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;
    int maxi = INT_MIN;

    for (int i = n - 1; i >= 0; i--) {
        if (nums[i] >= maxi) {
            maxi = nums[i];
            ans.push_back(nums[i]);
        }
    }

    // Reverse the result to maintain the order
    reverse(ans.begin(), ans.end());
    return ans;
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
        cout << "Leaders (Brute-force): ";
        vector<int> result1 = leader(nums);
        for (int num : result1) {
            cout << num << " ";
        }
        cout << endl;

        // Optimal approach
        cout << "Leaders (Optimal): ";
        vector<int> result2 = optimalLeader(nums);
        for (int num : result2) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

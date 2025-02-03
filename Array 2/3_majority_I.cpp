#include <bits/stdc++.h>
using namespace std;

/*
Function to find the majority element using a hashmap.
- A majority element is an element that appears more than n/2 times.
- This function uses O(n) time and O(n) space.
*/
int majEle(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> umap; // To store frequency of each element
    for (int num : nums) {
        umap[num]++;
    }

    // Check if any element has a count greater than n/2
    int majThreshold = n / 2;
    for (auto it : umap) {
        if (it.second > majThreshold) {
            return it.first; // Return the majority element
        }
    }
    return -1; // Return -1 if no majority element exists
}

/*
Optimal Moore Voting Algorithm:
- Intuition: If we pair up different elements, they cancel each other out.
- The element left unpaired is a potential majority element.
- Steps:
  1. Identify a candidate for the majority element.
  2. Verify if the candidate actually occurs more than n/2 times.
- Time Complexity: O(n)
- Space Complexity: O(1)
*/
int mooreVoting(vector<int>& nums) {
    int n = nums.size();
    int count = 0;  // Count for the potential majority element
    int majElement; // Variable to store the potential majority element

    // Step 1: Identify the majority element candidate
    for (int i = 0; i < n; i++) {
        if (count == 0) { // If count is zero, pick the current element as a candidate
            majElement = nums[i];
        }
        if (nums[i] == majElement) {
            count++;
        } else {
            count--;
        }
    }

    // Step 2: Verify if the candidate is actually the majority element
    int newCount = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == majElement) {
            newCount++;
        }
    }
    return newCount > n / 2 ? majElement : -1;
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

        // Using the hashmap-based method
        int resultHashmap = majEle(nums);
        if (resultHashmap != -1) {
            cout << "Majority element (using hashmap): " << resultHashmap << endl;
        } else {
            cout << "No majority element (using hashmap)" << endl;
        }

        // Using Moore's Voting Algorithm
        int resultMoore = mooreVoting(nums);
        if (resultMoore != -1) {
            cout << "Majority element (using Moore's Voting): " << resultMoore << endl;
        } else {
            cout << "No majority element (using Moore's Voting)" << endl;
        }
    }
    return 0;
}

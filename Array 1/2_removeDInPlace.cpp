#include <bits/stdc++.h>
using namespace std;

// Remove duplicates using a set (less optimal)
int removeDuplicates(vector<int>& nums) {
    set<int> st(nums.begin(), nums.end()); // O(n log n) time complexity
    int i = 0;
    for (auto it : st) {
        nums[i++] = it;
    }
    return i; // i represents the new size of the array
}

// Optimal two-pointer method (for sorted arrays)
int removeOptimal(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0; // Handle empty array case

    int i = 0;
    for (int j = 1; j < n; j++) {
        if (nums[j] != nums[i]) {
            nums[++i] = nums[j]; // Move unique elements forward
        }
    }
    return i + 1; // New size of the array
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
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        cout << "Choose method:\n1. Set-based (O(n log n))\n2. Two-pointer (O(n))\n";
        int choice;
        cin >> choice;

        int newSize;
        if (choice == 1) {
            newSize = removeDuplicates(nums);
        } else if (choice == 2) {
            sort(nums.begin(), nums.end()); // Ensure array is sorted for two-pointer method
            newSize = removeOptimal(nums);
        } else {
            cout << "Invalid choice." << endl;
            continue;
        }

        cout << "New array after removing duplicates: ";
        for (int i = 0; i < newSize; i++) {
            cout << nums[i] << " ";
        }
        cout << "\nNew size: " << newSize << endl;
    }

    return 0;
}

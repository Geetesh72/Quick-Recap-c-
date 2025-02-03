#include <bits/stdc++.h>
using namespace std;

void rightRotate(vector<int>& nums, int d) {
    int n = nums.size();
    d = d % n; // Handle cases where d >= n

    // Step 1: Store the last d elements in temp
    vector<int> temp(nums.end() - d, nums.end());

    // Step 2: Shift the first (n - d) elements to the right
    for (int i = n - d - 1; i >= 0; i--) {
        nums[i + d] = nums[i];
    }

    // Step 3: Place temp elements at the beginning
    for (int i = 0; i < d; i++) {
        nums[i] = temp[i];
    }
}

void rightRotate(vector<int>& nums, int d) {
    int n = nums.size();
    d = d % n; // Handle cases where d >= n

    // Step 1: Reverse the entire array
    reverse(nums.begin(), nums.end());

    // Step 2: Reverse the first d elements
    reverse(nums.begin(), nums.begin() + d);

    // Step 3: Reverse the remaining n - d elements
    reverse(nums.begin() + d, nums.end());
}

int main() {
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--) {
        int n, d;
        cout << "Enter the size of the array: ";
        cin >> n;
        cout << "Enter the number of places to rotate: ";
        cin >> d;

        vector<int> nums(n);
        cout << "Enter the elements of the array:\n";
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        rightRotate(nums, d);

        cout << "Array after right rotation by " << d << " places: ";
        for (int num : nums) {
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}

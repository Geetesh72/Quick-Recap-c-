#include <bits/stdc++.h>
using namespace std;

// Iterative Binary Search Function
// TC: O(log N), SC: O(1) - No extra space used
int binarySearch(vector<int>& nums, int target) {
    // Array is assumed to be sorted
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = -1; // Variable to store the result, -1 if not found

    while (low <= high) {
        int mid = low + (high - low) / 2; // Avoid potential overflow
        if (nums[mid] == target) {
            return mid; // Target found, return the index
        } else if (nums[mid] < target) {
            low = mid + 1; // Narrow down to the right half
        } else {
            high = mid - 1; // Narrow down to the left half
        }
    }
    return ans; // If target is not found
}

// Recursive Binary Search Function
// TC: O(log N), SC: O(log N) - Due to recursive call stack
int recursiveBinarySearch(vector<int>& nums, int low, int high, int target) {
    if (low > high) {
        return -1; // Base case: target not found
    }

    int mid = low + (high - low) / 2; // Avoid potential overflow
    if (nums[mid] == target) {
        return mid; // Target found, return the index
    } else if (nums[mid] > target) {
        return recursiveBinarySearch(nums, low, mid - 1, target); // Search in the left half
    } else {
        return recursiveBinarySearch(nums, mid + 1, high, target); // Search in the right half
    }
}

int main() {
    int t; // Number of test cases
    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--) {
        int n; // Size of the array
        cout << "Enter size of array: ";
        cin >> n;

        vector<int> nums(n); // Array to store the elements
        cout << "Enter sorted array elements: ";
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        int target;
        cout << "Enter target element: ";
        cin >> target;

        // Perform iterative binary search
        int result = binarySearch(nums, target);
        if (result != -1) {
            cout << "Iterative: Element found at index " << result << endl;
        } else {
            cout << "Iterative: Element not found" << endl;
        }

        // Perform recursive binary search
        result = recursiveBinarySearch(nums, 0, n - 1, target);
        if (result != -1) {
            cout << "Recursive: Element found at index " << result << endl;
        } else {
            cout << "Recursive: Element not found" << endl;
        }
    }

    return 0;
}

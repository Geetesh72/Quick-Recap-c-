#include <bits/stdc++.h>
using namespace std;

// Function to find the largest element
int largest(vector<int>& nums) {
    int n = nums.size();
    int larg = nums[0];
    for (int i = 1; i < n; i++) {
        if (nums[i] > larg) {
            larg = nums[i];
        }
    }
    return larg;
}

// Two-pass solution for finding the second largest element
int secondLargest(vector<int>& nums, int largestVal) {
    int n = nums.size();
    int slarge = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (nums[i] < largestVal && nums[i] > slarge) {
            slarge = nums[i];
        }
    }
    return (slarge == INT_MIN) ? -1 : slarge; // Handle edge case
}

// One-pass solution for finding the second largest element
int sLargest(vector<int>& nums) {
    int n = nums.size();
    int largest = INT_MIN;
    int sLarge = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (nums[i] > largest) {
            sLarge = largest;
            largest = nums[i];
        } else if (nums[i] < largest && nums[i] > sLarge) {
            sLarge = nums[i];
        }
    }
    return (sLarge == INT_MIN) ? -1 : sLarge; // Handle edge case
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

        if (n < 2) {
            cout << "Array must have at least 2 elements for a valid second largest." << endl;
            continue;
        }

        int lgest = largest(nums);
        cout << "Second Largest Element (Two-pass solution): " << secondLargest(nums, lgest) << endl;
        cout << "Second Largest Element (One-pass solution): " << sLargest(nums) << endl;
    }

    return 0;
}

/*
Framing my Failure 
1-> in one pass solution i have to intialize large and slarge with int_min 
also check if int min then return -1 else return ans 
2-> if n<2 return -1 directly cause if no is less than two then it doesnt make sense 
*/

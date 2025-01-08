#include <bits/stdc++.h>
using namespace std;
// brute force
int getMaxi(vector<int> &nums, int k)
{
    int n = nums.size();
    int leftSum = 0, rightSum = 0;
    int maxiSum = INT_MIN;
    // adding the left sum up to k elements
    for (int i = 0; i < k; i++)
    {
        leftSum += nums[i];
        maxiSum = leftSum;
    }
    // starting removing from the k-1th index and start adding from back
    int rIdx = n - 1;
    for (int i = k - 1; i >= 0; i--)
    {
        leftSum -= nums[i];
        rightSum += nums[rIdx];
        rIdx--;
        maxiSum = max(maxiSum, (leftSum + rightSum));
    }

    return maxiSum;
}
int main()
{
    int t; // Number of test cases
    cout << "Enter the number of test cases: ";
    cin >> t; // Input number of test cases

    while (t--) {
        int n, k; // Size of array and the value of k
        cout << "\nEnter the size of the array (n) and the value of k: ";
        cin >> n >> k;

        vector<int> nums(n); // Input array
        cout << "Enter " << n << " elements of the array: ";
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        // Call the function and print the result for each test case
        int result = getMaxi(nums, k);
        cout << "Maximum sum for k = " << k << " is: " << result << endl;
    }

    cout << "All test cases processed successfully!" << endl;
    return 0;
}
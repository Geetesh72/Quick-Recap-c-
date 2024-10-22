#include <bits/stdc++.h>
using namespace std;
int recursiveBs(vector<int> &nums, int low, int high, int target)
{
    if (low > high)
    {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (nums[mid] == target)
    {
        return mid;
    }
    if (nums[mid] < target)
    {
        return recursiveBs(nums, mid + 1, high, target);
    }

    return recursiveBs(nums, low, mid - 1, target);
}
int main()
{
    vector<int> nums{4, 5, 8, 170, 9, 5, 8};
    int low = 0;
    int n = nums.size();
    int high = n - 1;
    int target = 170;
    int index = recursiveBs(nums, low, high, target);
    cout << index;

    return 0;
}
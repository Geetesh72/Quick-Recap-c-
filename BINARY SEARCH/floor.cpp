#include <bits/stdc++.h>
using namespace std;
int floor_BS(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0;
    int ans = -1;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] <= target)
        {
            ans = nums[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1; // i did the mistake i dont write in else block so it execute every time
        }
    }
    return ans;
}
int main()
{
    vector<int> nums{10, 20, 30, 40, 50};
    int target = 25;
    int ans = floor_BS(nums, target);
    cout << ans;
    return 0;
}
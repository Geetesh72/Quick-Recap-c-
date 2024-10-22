#include <bits/stdc++.h>
using namespace std;
int binarySeach(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums{85, 7, 17, 1, 7, 1, 7};
    int x = 8; //        nums.begin()+2  nums.begin()+4
    int lb = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
    return 0;
}
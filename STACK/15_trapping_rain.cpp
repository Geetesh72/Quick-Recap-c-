#include <bits/stdc++.h>
using namespace std;
/*Logic
 */
vector<int> leftMax(vector<int> &nums)
{
    int n = nums.size();
    vector<int> prefixSum(n);
    prefixSum[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = max(prefixSum[i - 1], nums[i]);
    }
    return prefixSum;
}

vector<int> rightMax(vector<int> &nums)
{
    int n = nums.size();
    vector<int> suffixSum(n);
    suffixSum[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffixSum[i] = max(suffixSum[i + 1], nums[i]);
    }
    return suffixSum;
}

int trapWater(vector<int> &nums)
{
    int n = nums.size();
    if (n < 3)
        return 0;
    int total = 0;
    vector<int> left = leftMax(nums);
    vector<int> right = rightMax(nums);
    for (int i = 0; i < n; i++)
    {
        if (nums[i] < left[i] && nums[i] < right[i])
        {
            total += max(0, min(left[i], right[i]) - nums[i]);
        }
    }
    return total;
}

// need the smaller one smaller - nums[i];
/** Optimal one  */
int trapWaterOptimal(vector<int> &nums)
{
    int n = nums.size();
    if (n < 3)
        return 0;
    int left = 0;
    int right = n - 1;
    int leftMax = 0, rightMax = 0;
    int total = 0;
    while (left <= right)
    {
        if (nums[left] <= nums[right])
        {
            if (nums[left] >= leftMax)
            {
                leftMax = nums[left];
            }
            else
            {
                total +=leftMax-nums[left];
            }
          left++;
        }else{
            if(nums[right]>=rightMax){
                rightMax= nums[right];
            }else{
                total +=rightMax -nums[right];
            }
            right--;
        }
        
    }
    return total;
}

int main()
{
    vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Trapped Water: " << trapWaterOptimal(nums) << endl;
    return 0;
    
}
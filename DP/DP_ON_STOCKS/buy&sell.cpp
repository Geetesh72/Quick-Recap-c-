#include <bits/stdc++.h>
using namespace std;


/*
given array 
>
*/
int maxiProfit(vector<int>&nums){
    int n = nums.size();
    int profit = 0;
    int mini = nums[0];
    for(int i = 1;i<n;i++){
        int cost = nums[i]-mini;
        profit = max(profit,cost);
        mini = min(mini,nums[i]);
    }
    return profit;
}
int main()
{
    vector<int>nums  = {7,8,1,2,3,6,7,9};
    cout<<maxiProfit(nums);
    return 0;
}
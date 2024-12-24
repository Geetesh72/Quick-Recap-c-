#include <bits/stdc++.h>
using namespace std;


/*
given array buy once and sell once 

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
    int n;
    cin>>n;
   cout<<"Enter Arr elemets "<<endl;
    vector<int>nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }
    cout<<maxiProfit(nums);
    return 0;
}
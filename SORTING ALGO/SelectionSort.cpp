#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>&nums){
    int n  = nums.size();
    for(int i = 0;i<n-1;i++){
        int mini = i ;
        for(int j = i+1;j<n;j++){
            if(nums[j]<nums[mini]){
                mini = j;
            }
        }
        swap(nums[i],nums[mini]);
    }
}

void print(vector<int>&nums){
    int n= nums.size();
    for(int i = 0;i<n;i++)
    {
        cout<<nums[i]<<" ";
    }
}
int main()
{
    vector<int>nums = {4,3,4,6,7,5,6};
    selectionSort(nums);
    print(nums);
    return 0;
}
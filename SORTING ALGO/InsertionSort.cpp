#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>&nums){
    int n = nums.size();
    for(int i = 0;i<n;i++){
        int j = i;
        while(j>0 && nums[j]<nums[j-1]){
            swap(nums[j],nums[j-1]);
            j--;
        }
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
    insertionSort(nums);
    print(nums);
    return 0;
}
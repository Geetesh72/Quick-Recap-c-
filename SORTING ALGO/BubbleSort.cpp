#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>&nums){
    int n = nums.size();
    for(int i = n-1;i>=1;i--){
        bool swapped = false;
        for(int j = 1;j<=i;j++){
            if(nums[j]<nums[j-1]){
                swap(nums[j],nums[j-1]);
                swapped = true;
            }
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
    bubbleSort(nums);
    print(nums);
    return 0;
}
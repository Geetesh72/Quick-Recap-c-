#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&nums,int low , int high){
    int pivot = nums[low];
    int i = low ;
    int j = high;
    while(i<j){
        while(nums[i]<=pivot && i<=high-1){
            i++;
            
        }
        while(nums[j]>pivot && j>=low+1){
            j--;

        }
        if(i<j){
            swap(nums[i],nums[j]);
        }
    }
    swap(nums[low],nums[j]);
    return j;

}

void quickSort(vector<int>&nums,int low , int high){

    if(low<high){
        int pIndex = partition(nums,low,high);
        quickSort(nums,low,pIndex-1);
        quickSort(nums,pIndex+1,high);
    }

}

void print(vector<int>&nums){
    int n = nums.size();
    for(int i = 0;i<n;i++){
        cout<<nums[i]<< " ";
    }cout<<endl;
}
 
int main(){
    vector<int>nums = {10,7,8,9,0,1,5,2,3,6,4};
    quickSort(nums,0,nums.size());
    print(nums);
    return 0;
}
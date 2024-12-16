#include <bits/stdc++.h>
using namespace std;

void merging(vector<int>&nums,int left ,int mid, int right){
    int n1 = mid-left+1;
    int n2  = right-mid;
    
    vector<int>leftArr(n1) ,rightArr(n2);

    for(int i =0;i<n1;i++){
        leftArr[i] = nums[left+i];

    }
    for(int i = 0;i<n2;i++){
        rightArr[i]=nums[mid+1+i];
    }
    int i = 0,j=0,k=left;
    while(i<n1 && j<n2){
        if(leftArr[i]<=rightArr[j]){
            nums[k]=leftArr[i];
            i++;
        }
        else{
            nums[k]=rightArr[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        nums[k]=leftArr[i];
        i++;
        k++;
    }
    while(j<n2){
        nums[k] = rightArr[j++];
        k++;
    }







}


void mergeSort(vector<int>&nums){
    int n = nums.size();
    for(int currSize = 1;currSize<n;currSize *=2){

        for(int left = 0;left<n-1;left+=2*currSize){
            int mid = min(left+currSize-1,n-1);
            int right  = min(left+2*currSize-1,n-1);

            merging(nums,left,mid,right);
        }
    }

}
void print(vector<int>&nums){
    int n = nums.size();
    for(int i = 0;i<n;i++){
        cout<<nums[i]<< " ";
    }cout<<endl;
}

int main()
{
    vector<int>nums = {4,8,1,5,2};
    mergeSort(nums);
    print(nums);

    return 0;
}
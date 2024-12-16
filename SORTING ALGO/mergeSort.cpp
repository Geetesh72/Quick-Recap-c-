#include <bits/stdc++.h>

using namespace std;



void merging(vector<int>&nums,int low , int mid , int high){
    vector<int>temp;
    int left = low ;
    int right  = mid+1;

    while(left<=mid && right<=high){
        if(nums[left]<=nums[right]){
            temp.push_back(nums[left]);
            left++;
        }
        else{
            temp.push_back(nums[right]);
            right++;
        }
    

    }
    while(left<=mid){
        temp.push_back(nums[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(nums[right]);
        right++;
    }

    // copy the temp element to nums 
    for(int i = low;i<=high ;i++){
        nums[i] = temp[i-low];
    }

    // int m = temp.size();
    // for(int i =0;i<m;i++){
    //     nums[i]=temp[i];
    // }

}

void merge(vector<int>&nums, int low , int high){
    if(low>=high){
        return ;
    }
    int mid = (low+high)/2;
    merge (nums,low,mid);
    merge(nums,mid+1,high);

    // merging function 
    merging(nums, low, mid,high);

}


void mergeSort(vector<int>&nums){
    int n  = nums.size();
    merge(nums,0,n-1);
}

void print(vector<int>&nums){
    int n = nums.size();
    for(int i = 0;i<n;i++){
        cout<<nums[i]<< " ";
    }cout<<endl;
}
 
int main(){
    vector<int>nums = {4,8,1,5,2,4};
    mergeSort(nums);
    print(nums);
    return 0;
}
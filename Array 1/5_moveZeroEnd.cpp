#include<bits/stdc++.h>
using namespace std;

void moveZero(vector<int>&nums){
    int n  = nums.size();
    vector<int>temp;
    for(int i = 0;i<n;i++){
        if(nums[i]!=0)
        {
            temp.push_back(nums[i]);
        }

    }
    for(int i = 0;i<temp.size();i++){
        nums[i] = temp[i];
    }
    for(int i = temp.size();i<nums.size();i++){
        nums[i]  = 0;
    }

    
}
void moveZeroOptimal(vector<int>&nums){
    int n = nums.size();
    int j = -1;
    for(int i = 0;i<n;i++){
        if(nums[i]==0){
            j = i;
            break;
        }
    }

    for(int i = j+1;i<n;i++){
        if(nums[i]!=0){
            swap(nums[i],nums[j]);
            j++;
            
        }
    }

}

int main(){ 
    int t ;
    cout<<"Enter no of test case ";
    cin>>t;
    while(t--){
        int n ;
        cout<<"Enter the size of array ";
        cin>>n;
        vector<int>nums(n);
        cout<<"Enter the elements of array "<<endl;
        for(int i = 0;i<n;i++){
            cin>>nums[i];
        }
        
    }
return 0;
}
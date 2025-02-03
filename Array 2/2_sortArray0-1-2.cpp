#include<bits/stdc++.h>
using namespace std;
vector<int> sortArray(vector<int>&nums){
    int n  = nums.size();
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i = 0;i<n;i++){
        if(nums[i]==0){
            cnt0++;
        }
        else if(nums[i]==1){
            cnt1++;
        }
        else {
            cnt2++;
        }
    }
    for(int i = 0;i<cnt0;i++){
        nums[i]=0;
    }
    for(int i = cnt0 ;i<cnt0+cnt1;i++){
        nums[i]=1;
    }
    for(int i = cnt0+cnt1;i<n;i++){
        nums[i] = 2;
    }
    return nums;


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
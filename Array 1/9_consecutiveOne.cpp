#include<bits/stdc++.h>
using namespace std;
int concutive(vector<int>&nums){
    int n = nums.size();
    int cnt = 0;
    int maxi = INT_MIN;
    for(int i = 0;i<n;i++){
        if(nums[i]==1){
            cnt++;
            maxi = max(maxi,cnt);
        }else{
            cnt=0;
        }
    }
    return maxi;

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

        int ans  = concutive(nums);
        cout<<ans;
        
    }
return 0;
}
#include<bits/stdc++.h>
using namespace std;
vector<int>intersection(vector<int>nums,vector<int>mums){
    int n = nums.size();
    int m = mums.size();
    vector<int>vis(m,0);
    vector<int>ans;
    for(int i = 0;i<n;i++){
        for(int j =0;j<m;j++){
            if(nums[i]==mums[j] && vis[j]==0){
                ans.push_back(nums[i]);
                vis[j] = 1;
                break;
            }
            if(mums[j]>nums[i]){
                break;
            }

        }
    }
    return ans;
}
// optimal one 
vector<int>insert2(vector<int>&nums,vector<int>mums){
    int n = nums.size();
    int m  = mums.size();
    int i = 0;
    int j = 0;
    vector<int>ans;
    while(i<n && j<m){
        if(nums[i]<mums[j]){
            i++;
        }
        else if(mums[j]<nums[i]){
            j++;
        }
        else{
            ans.push_back(nums[i]);
            i++;
            j++;
        }

    }
    return ans;
    
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
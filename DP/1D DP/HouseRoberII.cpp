#include <bits/stdc++.h>
using namespace std;

// Top Down house robber 

/*
Logic 
last and first can not be together 
leave out the last element 
leave out the frist element 
*/
int houseRobber2(int n , vector<int>&nums){
    int prev1 = nums[0];
    int prev2 = 0;
    for(int i = 1 ;i<n;i++){
        int take = nums[i];
        if(i>1){
            take+=prev2;
        }
       int notTake =0 + prev1;
        int curr = max(take ,notTake);
        prev2 = prev1;
        prev1 = curr;


    }
    return prev1;



}

int main()
{
    int n  ;
    cin>>n;
    vector<int>nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>temp1,temp2;
    for(int i = 0;i<n;i++){
        if(i!=0)temp1.push_back(nums[i]);
        if(i!=n-1)temp2.push_back(nums[i]);
    }
    cout<<max(houseRobber2(temp1.size(),temp1),houseRobber2(temp2.size(),temp2));
    return 0;
}
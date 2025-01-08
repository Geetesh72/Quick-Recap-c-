#include<bits/stdc++.h>
using namespace std;



vector<int>pse_I(vector<int>&nums)
{
    int n= nums.size();
    vector<int>ans(n,-1);
    for(int i = 1;i<n;i++){
        for(int j= i-1;j>=0;j--){
            if(nums[j]<nums[i]){
                ans[i]=nums[j];
                break;
            }
        }
    }
    return ans;
}

// optimal one 
vector<int>pse_II(vector<int>&nums){
    int n = nums.size();
    vector<int>ans(n);
    stack<int>st;
    for(int i =0;i<n;i++){
        while(!st.empty() && st.top()>=nums[i]){
            st.pop();
        }
        if(st.empty())ans[i]=-1;
        else{
            ans[i]=st.top();
        }
        st.push(nums[i]);
    }
    return ans;
}
void photo(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl
         << endl;
}
int main(){ 
    vector<int>nums={4,5,2,10,8};
    photo(nums);
    nums = pse_II(nums);
    photo(nums);



return 0;
}
#include<bits/stdc++.h>
using namespace std;
vector<int>windowMaxi(vector<int>&nums,int k ){
    int n = nums.size();
    vector<int>ans;
    for(int  i = 0;i<=n-k;i++){
        int maxi = nums[i];
        for(int j = i;j<i+k;j++){
          if(nums[j]>maxi){
            maxi  = nums[j];
          }

        }
        ans.push_back(maxi);
    }
    return ans;
    
}

vector<int> maxiWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans;
    deque<int> dq; // Deque to store indices of potential max elements

    for (int i = 0; i < n; i++) {
        // Remove indices of elements not in the current window
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove indices of elements smaller than the current element
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        // Add the current element's index
        dq.push_back(i);

        // Add the maximum of the current window to the result
        if (i >= k - 1) {
            ans.push_back(nums[dq.front()]);
        }
    }

    return ans;
}
void photo(vector<int>&nums){
    int n = nums.size();
    for(int i = 0;i<n;i++){
        cout<<nums[i]<<" ";
    }cout<<endl;
}
int main(){ 
    vector<int>nums ={1,3,-1,-3,5,3,2,1,6};
    vector<int>temp = nums;
    int k = 3;
    nums = maxiWindow(nums,k);
    photo(nums);
    temp =windowMaxi(temp,k);
    photo(temp);



return 0;
}
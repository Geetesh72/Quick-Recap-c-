#include <bits/stdc++.h>
using namespace std;
/**About problem 
 * give the array we have to return the sum of minimum among all the subarray 
 * 3 1 2 4 
 * subarray are 3 , 3-1,3-1-2,3-1-2-4 and so on  
 * 
 *
*/
int mod = 1e9+7; 
int subArrayMinimus(vector<int>&nums){
    int n = nums.size();
    int sum = 0;
    for(int i = 0;i<n;i++){
        int mini = nums[i];
        for(int j =i;j<n;j++){
            mini = min(mini,nums[j]);
            sum = (sum+mini)%mod;
        }
    }
    return sum;
}


// optimal one 
/*
How ??
individual occ of element : how many time this elemenet is minimin in subarray's
so that we can calculate it like that 
x into y times 

idea is reusing the concept of nse , pse how ?
1 4 6 7 3 7 8 1
        _
3 next smaller element is at index 7 so how array length is 7-4  = 3  
3's prevous smaller element at index 1 so how it get length is 4-0 = 4

how many subarray then 3 as  the mini element is 3*4 = 12 
what is sum of them is 12*3  = 36 
this is the intuion 
 
*/
vector<int> findNse(vector<int>&nums){
    int n = nums.size();
    stack<int>st;
    vector<int>ans(n);
    for(int i = n-1;i>=0;i--){
        if(!st.empty() && nums[st.top()]>=nums[i]){
            st.pop();
        }
        if(st.empty())ans[i]=n;
        else{
          ans[i]=st.top();
        }
        st.push(i);
    }
    return ans;
    

}
vector<int>findPse(vector<int>&nums){
   int n = nums.size();
   vector<int>ans(n);
   stack<int>st;
   for(int i = 0;i<n;i++){
      if(!st.empty() && nums[st.top()]>nums[i]){
        st.pop();
      }
      if(st.empty())ans[i]=-1;
      else{
        ans[i]=st.top();
      }
      st.push(i);
   }
   return ans;

}

// grater
vector<int>findNge(vector<int>&nums){
   int n = nums.size();
   vector<int>ans(n);
   stack<int>st;
   for(int i = 0;i<n;i++){
      if(!st.empty() && nums[st.top()]<=nums[i]){
        st.pop();
      }
      if(st.empty())ans[i]=-1;
      else{
        ans[i]=st.top();
      }
      st.push(i);
   }
   return ans;

}

vector<int>findPge(vector<int>&nums){
   int n = nums.size();
   vector<int>ans(n);
   stack<int>st;
   for(int i = 0;i<n;i++){
      if(!st.empty() && nums[st.top()]<nums[i]){
        st.pop();
      }
      if(st.empty())ans[i]=-1;
      else{
        ans[i]=st.top();
      }
      st.push(i);
   }
   return ans;

}


 

int subarrayMini(vector<int>&nums){
    int n = nums.size();
    vector<int> nse = findNse(nums);
   vector<int> pse = findPse(nums);
    int sum = 0,mod = (int)1e9+7;
    for(int i = 0;i<n;i++ ){
        int left = i-pse[i];
        int right = nse[i]-i;
        sum = (sum + (1LL * left * right % mod) * nums[i] % mod) % mod;
    }
    return sum;

}

int subarrayMaxi(vector<int>&nums){
    int n = nums.size();
    vector<int> nse = findNge(nums);
   vector<int> pse = findPge(nums);
    int sum = 0,mod = (int)1e9+7;
    for(int i = 0;i<n;i++ ){
        int left = i-pse[i];
        int right = nse[i]-i;
         sum = (sum + (1LL * left * right % mod) * nums[i] % mod) % mod;
    }
    return sum;

}
int rangeSum(vector<int>&nums){
    int a = subarrayMini(nums);
    int b = subarrayMaxi(nums);
    return b-a;
}


int main()
{
    vector<int>nums={3,1,2,4};
    cout<<rangeSum(nums);
    return 0;
}
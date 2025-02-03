#include<bits/stdc++.h>
using namespace std;
/*About problem 3 sum 

*/
vector<vector<int>>sum_3_triplet(vector<int>&nums){
    int n = nums.size();
    set<vector<int>>st;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            for(int k = j+1;k<n;k++){
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int>temp = {nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
}

vector<vector<int>>better_sum(vector<int>&nums){
    int n = nums.size();
    set<vector<int>>ansSet; // key thing i forgot that i i not updateing for every itration 
    for(int i = 0;i<n;i++){
        set<int>st;
        for(int j = i+1;j<n;j++){
            int req = -(nums[i]+nums[j]);
            if(st.find(req)!=st.end()){
                vector<int>temp = {nums[i],nums[j],req};
                sort(temp.begin(),temp.end());
                ansSet.insert(temp);
            }
            st.insert(nums[i]);
    
        }
     
    }
    vector<vector<int>>ans(ansSet.begin(),ansSet.end());
    return ans;
}

// sorting the array 
vector<vector<int>>optimal_sum(vector<int>&nums){
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>>ans;
    for(int i = 0;i<n;i++)
    {
        if(i>0 && nums[i-1]==nums[i])continue;
        int j = i+1;
        int k = n-1;
        while(j<k){
            int sum = nums[i]+nums[j]+nums[k];
            if(sum<0){
                j++;

            }else if(sum>0){
                k--;

            }else{
                vector<int>temp = {nums[i],nums[j],nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1])j++;
                while(j<k && nums[k]==nums[k+1])k--;

            }

        }
    }
    return ans;

}



int main(){ 
    int t ;
    cout<<"\nEnter Number of Test Case: ";
    cin>>t;
    cout<<"\nEnter size of array: ";
    int n ;
    cin>>n;
    vector<int>nums(n);
    cout<<"\nEnter the elements of array:";
    for(int i  = 0;i<n;i++){
        cin>>nums[i];
    }


return 0;
}

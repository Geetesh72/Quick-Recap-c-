#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>sum_4(vector<int>&nums,int target){
    int n = nums.size();
    set<vector<int>>st;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            for(int k = j+1;k<n;k++){
                for(int l = k+1;l<n;l++){
                    if(nums[i]+nums[j]+nums[k]+nums[l]==target){
                        vector<int>temp = {nums[i]+nums[j]+nums[k]+nums[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
        vector<vector<int>>ans(st.begin(),st.end());
    return ans;
}

vector<vector<int>>sum_4Better(vector<int>&nums,int target){
    int n = nums.size();
    set<vector<int>>st;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            set<int>checkSet;
            for(int k = j+1;k<n;k++){
                int req = target-(nums[i]+nums[j]+nums[k]);
                if(checkSet.find(req)!=checkSet.end()){
                    vector<int>temp = {nums[i]+nums[j]+nums[k],req};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                checkSet.insert(nums[k]);
           
            }
        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
}

// optimal
vector<vector<int>>sum_4Optimal(vector<int>&nums,int target){
    int n  = nums.size();
    vector<vector<int>>ans;
    sort(nums.begin(),nums.end());
    for(int i = 0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1])continue;
        for(int j = i+1;j<n;j++){
            if(j>i && nums[j]==nums[j-1])continue;
            int k = j+1;
            int l = n-1;
            while(k<l){
                int sum = nums[i]+nums[j]+nums[k]+nums[l];
                if(sum<target){
                    k++;

                }
                else if(sum>target){
                    l--;

                }else{
                    vector<int>temp;
                    temp.push_back(sum);
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && nums[k]==nums[k-1])k++;
                    while(k<l && nums[l]==nums[l+1])l--;

                }
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

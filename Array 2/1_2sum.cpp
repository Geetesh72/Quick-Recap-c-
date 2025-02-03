#include<bits/stdc++.h>
using namespace std;
/* here is two varity 
one just tell target is there one in regurn the index of target 

*/
vector<int>sum_2(vector<int>&nums ,int targert){
    int n = nums.size();
    unordered_map<int,int>umap;
    vector<int>ans;
    for(int i = 0;i<n;i++){
        
        int req = targert-nums[i];
        if(umap.find(req)!=umap.end()){
            ans.push_back(i);
            ans.push_back(umap[req]);

        }
        umap[nums[i]] = i;

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
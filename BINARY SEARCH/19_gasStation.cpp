#include<bits/stdc++.h>
using namespace std;

long double miniMaxDist(vector<int>&nums,int k){
    int n = nums.size();
    vector<int>howMany(n-1,0);
    for(int i = 1 ;i<=k;i++){
        long double maxSec = -1;
        int maxInd = -1;
        for(int i = 0;i<n;i++){
            long double diff = (nums[i+1]-nums[i]);
            long double secLen = diff/(long double)(howMany[i]+1);
            if(secLen>maxSec){
                maxSec  = secLen;
                maxInd = i;
            }
        }
    howMany[maxInd]++;
    }
    long double maxAns = -1;
    for(int i = 0;i<n-1;i++){
        long double diff = (nums[i+1]-nums[i]);
        long double seclen = diff/(long double)(howMany[i]+1);
        maxAns = max(maxAns,seclen);
    }
    return maxAns;
}




int main(){ 
return 0;
}
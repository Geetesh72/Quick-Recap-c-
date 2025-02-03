#include<bits/stdc++.h>
using namespace std;

int valueAtindexOfPascalTriangle(int n ,int r){
    long long ans= 1;
    for(int i = 0;i<r;i++){
        ans = ans*(n-i);
        ans = ans/(i+1);

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

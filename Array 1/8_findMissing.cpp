#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>&nums)
{
    int n = nums.size();
    int xor1 = 0 , xor2 = 0;
    int N = n-1;
    for(int i = 0;i<N-1;i++){
        xor2  = xor2^nums[i];// element xor 
        xor1 = xor1^(i+1);
    }
    xor1 = xor1^n;
    return xor1^xor2;
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
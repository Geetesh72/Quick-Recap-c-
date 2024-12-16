#include <bits/stdc++.h>
using namespace std;
int printDivisor(int n ){
    int cnt =0;
    for(int i = 1;i<=n;i++){
        if(n%i==0){
            cnt++;
            cout<<i<<" ";
        }
    }
    return cnt;
}

void divisor2(int n){
    int cnt =0;
    vector<int>ans;
    for(int i = 0;i<sqrt(n);i++){
        if(n%i==0){
            ans.push_back(i);
            if(n%i!=i){
                ans.push_back(n/i);

            }
        }
        
    }
    sort(ans.begin(),ans.end());
    for(auto it:ans)cout<<it<<" ";
}
int main()
{
    int n ;
    cin>>n;
    divisor2(n);
    // cout<<ans;


    return 0;
}
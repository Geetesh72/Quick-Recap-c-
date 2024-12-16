#include <bits/stdc++.h>
using namespace std;

// prime no ->  the exactly two factor one and itself 
int isPrime(int n ){
    int cnt = 0;
    for(int i  = 1;i<=n;i++){
        if(n%i==0){
            cnt++;
        }
    }
    if(cnt==2){
        return cnt;
    }
    else return 0;

}

int isPrimeSqrt(int n ){
    int cnt = 0;
    for(int i = 1;i*i<=n;i++){
        if(n%i==0){
            cnt++;
            if(n%i!=i){
            cnt++;
        }
        }
        
    }
    if(cnt==2){
        return cnt;
    }
    else return 0;
}
int main()
{
    int n = 17;
    int ans = isPrimeSqrt(n);
    if(ans ==2)cout<<"Prime Number";
    else cout<<"Not Prime";
    
    return 0;
}
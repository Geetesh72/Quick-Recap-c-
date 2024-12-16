#include <bits/stdc++.h>
using namespace std;
int methodOne (int n , int m ){
    int gcd = 1;
    for(int i = 1;i<=n;i++){
        if(n%i==0 && m%i==0){
            gcd = i;
        }
    }
    return gcd;
}

int methodTwo(int n , int m){
    int gcd=1;
    for(int i = 1;i<=min(n,m);i++){
        if(n%i==0 && m%i==0){
            gcd = i;
        }
    }
    return gcd;
}


int methodThree(int n , int m ){
    int gcd = 1;
    for(int i = min(n,m);i>=1;i--){
        if(n%i==0 && m%i==0){
            gcd = i;
        }
    }
    return gcd;
}
// E algo 
int method4 (int a , int b){
    while (a>0 && b>0){
        if(a>b) a  = a%b;
        else b = b%a;

    }
    if(a==0)return b;
    else return a;
}

int main()
{
    int n = 40,m=20;
    cout<<__gcd(m,n);
    return 0;
}
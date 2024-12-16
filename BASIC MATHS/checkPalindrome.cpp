#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 121;
    int m = n;
    int revNum = 0;
    while(n>0){
        int lastDigit = n%10;
        n = n/10;
        revNum = (revNum*10)+lastDigit;
    }
    if(m==revNum)cout<<'1';
    else cout<<"0";


    return 0;
}
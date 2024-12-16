#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n  = 343534;
    int cnt =0;
    while(n>0){
        int lastDigit = n%10;
        cnt++;
      
        n = n/10;


    }
    cout<<cnt;


    return 0;
}

/*
LOG BASE 10 
LOG BASE 2 N 
LOG BASE 5 N
*/
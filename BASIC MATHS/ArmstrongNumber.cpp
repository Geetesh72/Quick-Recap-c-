#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 1634;
    int m = n;
    int sum = 0;
    int numDigits = to_string(n).length();
    while(n>0){
        int lastDigit = n%10;
        sum += (lastDigit*lastDigit*lastDigit*lastDigit);
        n= n/10;
         


    }
    if(sum==m)cout<<"Armstrong Number";
    else cout<<"Not Armstrong Number";
    return 0;
}
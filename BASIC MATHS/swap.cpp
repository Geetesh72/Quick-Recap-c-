#include<bits/stdc++.h>
using namespace std;
 
void reverse(string &s ){
    int i =0;
    int n = s.length();
    int j = n-1;
    while(i<=j){

       
        char temp = s[i];
        s[i]=s[j];
        s[j]=temp;
        i++;
        j--;
    }

}

int main(){ 
return 0;
}
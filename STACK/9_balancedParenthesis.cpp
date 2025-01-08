#include <bits/stdc++.h>
using namespace std;

bool isBalancedParenthisis(string &s){
    int n = s.length();
    stack<char>st;
    for(int i = 0;i<n;i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);

        }else{
            if(st.empty())return false;
            char ch =st.top();
            st.pop();
            if(s[i]==')' && ch!='(' 
               || s[i]=='}' && ch!='{'
               || s[i]==']' && ch!='[' ){
                return false;
               }
        }
    }
    return st.empty();

}



int main()
{
    string test1 = "({[]})";  // Balanced
    string test2 = "({[})";   // Not Balanced

    cout << (isBalancedParenthisis(test1) ? "Balanced" : "Not Balanced") << endl;
    cout << (isBalancedParenthisis(test2) ? "Balanced" : "Not Balanced") << endl;
    return 0;
}
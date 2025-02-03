#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string &s,string &t){
    if(s.length()!=t.length()){
        return false;
    }
    vector<int>hash(26,0);
    for(int i =0;i<s.length();i++){
        hash[s[i]-'a']++;
        hash[t[i]-'a']--;
    }
    for(int cnt :hash){
        if(cnt!=0){
            return false;
        }
    }
    return true;
}

int main(){ 
return 0;
}
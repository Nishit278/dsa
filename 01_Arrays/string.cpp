#include <bits/stdc++.h>

using namespace std;

int main(){
    int I=1;
    int ans = 0;
    string s = "IV";
    for(int i=0;i<s.length();i++){
        if(s[i] == 'I' && (s[i+1]!='V' || s[i+1]!='X')){
            s[i] = '1';
        }
    }
    cout << s;
    string str = "hello";
    cout << str.find("w")<<endl;
   
    return 0;
   
}
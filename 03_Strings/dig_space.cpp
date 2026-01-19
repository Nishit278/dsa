#include <bits/stdc++.h>
using namespace std;

int main(){
    char ch;
    ch = cin.get();
    int alpha = 0;
    int digits = 0;
    int spaces = 0;

    while(ch!='\n'){
        if(ch>='0' and ch<='9'){
            digits++;
        }
        else if((ch>='a' and ch<='z') or (ch>='A' and ch<='Z')){
            alpha++;
        }
        else if(ch ==' ' or ch =='\t')
            spaces++;

        ch = cin.get();
    }
    cout << "Alphabets: " << alpha << endl;
    cout << "digits: " << digits << endl;
    cout << "spaces: " << spaces << endl;
    
}
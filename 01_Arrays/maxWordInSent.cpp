#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();

    char a[n+1];
    cin.getline(a, n);
    // cin.ignore();

    int maxLen = 0;
    int currLen = 0, i =0;
    while(1){
       if(a[i] == ' ' || a[i]=='\0'){
           maxLen = max(currLen, maxLen);
           currLen = 0;
       } else {
           currLen ++;
       }

       if(a[i] == '\0') break;
       i++;
    }
    cout << maxLen << endl;


}
#include <bits/stdc++.h>
using namespace std;

int main(){
    // palindrome 
    int n;
    cin >> n;
    char arr[n+1];
    cin >> arr;
    int i=0, j=n-1;
    bool check = 1;
    while(i!=j){
        if(arr[i]!=arr[j]){
            check = 0;
            break;
        }
        i++;
        j--;
    }
    if(check == 1){
        cout << "Palindrome"<< endl;
    }
    
}
#include <bits/stdc++.h>
using namespace std;

void print(int n){
    if(n==0)
        return;
    print(n - 1);
    cout << n << " ";
}
int main(){
    int n = 20;
    print(n);
    cout << endl;
    return 0;
}
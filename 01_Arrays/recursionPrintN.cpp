#include <bits/stdc++.h>
using namespace std;

void print(int n){
    if(n==100){
        cout << 100 << " ";
        return;
    }
    print(n+1);
    cout <<n<<" ";

}

int main(){
    int n = 1;
    print(n);
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char s, char d, char h){
    if(n==1){
        cout << "Moving " << n << " from " << s << " to " << d << endl;
        return;
    }
    towerOfHanoi(n - 1, s, h, d);
    cout << "Moving " << n << " from " << s << " to " << d << endl;
    towerOfHanoi(n - 1, h, d, s);

}

int main(){
    int n = 3;
    // cin >> n;
    char s = 'A', h = 'B', d = 'C'; //source, helper and destination
    towerOfHanoi(n, s, d, h);
    return 0;
}
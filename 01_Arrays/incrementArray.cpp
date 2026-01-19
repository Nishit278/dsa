#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 9;
    int array[] = {1,2,3,4,5,6,7,8,9};
    for(int i=0;i<n; i++){
        cout << array[i++]<< " ";
    }
    cout << endl;
    for(int i=0;i<n; i++){
        cout << array[i]++ << " ";
    }
    cout << endl;
}


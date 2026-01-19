#include <bits/stdc++.h>
using namespace std;

int main(){
    int a = 10;
    int *ptr = &a;
    cout << ptr <<endl;

    ptr++;
    cout << ptr << endl;

    int **q = &ptr;
    cout << **q << endl;

    int b[] = {10, 20, 30, 40};
    cout << *b << endl;
    int *aptr = b;
    for(int i =0;i<4;i++){
        cout << *aptr << endl;
        aptr++;
    }
    
    for(int i =0;i<4;i++){
        cout << *(b+i) << endl;
    }
    

    
}

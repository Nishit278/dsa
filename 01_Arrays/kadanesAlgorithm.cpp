#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int max_sum = INT_MIN;
    int sum =0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum<0){
            sum=0;
        }
        max_sum = max(sum, max_sum);
    }
    cout << max_sum << endl;
}
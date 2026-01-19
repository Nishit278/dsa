#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans =0;
    for(int i=0;i<n;i++){
        int sum = 0;
        int max_sum = INT_MIN;
        for(int j=i;j<n;j++){
            sum+=a[j];
            max_sum = max(sum, max_sum);
        }
        ans = max(ans, max_sum);
    }
    cout<<ans <<endl;
}
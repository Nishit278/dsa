#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int32_t M=1e9+7;

signed main(){
	int n; cin>>n;
	vector<int> a(n);
	int cnt = 0;
	for(auto &i: a){
		cin >> i;
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if((a[i]+a[j])%M >= (a[i]*a[j])%M){
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
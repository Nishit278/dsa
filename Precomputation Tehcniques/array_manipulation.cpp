#include <bits/stdc++.h>
using namespace std;

const int N = 1e7+10;
long long int a[N];

int main(){
	int n, m; cin >> n >> m;
	while(m--){
		int p, q, r;
		cin >> p >> q >> r; // Time complexity = O(M) + O(N) + O(N) = O(2N+M) = O(N)
		a[p]+=r;
		a[q+1]-=r;
	}
	for(int i=1;i<=n;i++){
		a[i]+=a[i-1];
	}
	long long mx = INT_MIN;
	for(int i=1;i<=n;i++){
		mx = max(mx, a[i]);
	}
	cout << mx << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b){
	if(b == 0) return a; // or if(a%b == 0) return b;
	return gcd(b,a%b);
}

int main(){
	int t; cin >> t;
	while(t--){
		int n,q;
		cin >> n >> q;
		int a[n+10];
		int f[n+10];
		int b[n+10];
		f[0] = b[n+1] = 0;
		for(int i=1; i<=n; ++i){
			cin >> a[i];
		}
		for(int i=1; i<=n; ++i){
			f[i] = gcd(f[i-1], a[i]);
		}
		for(int i=n;i>=1;i--){
			b[i] = gcd(b[i+1], a[i]);
		}
		while(q--){
			int l,r;
			cin >> l >> r;
			cout << gcd(f[l-1], b[r+1]) << endl;
		}
	}
	return 0;
}
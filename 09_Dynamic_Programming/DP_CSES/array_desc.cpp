#include "bits/stdc++.h"
using namespace std;
#define int               long long
#define rep(i,a,b)        for(int i=a;i<b;i++)

const int32_t M=1e9+7;


void solve(){
	int n, m; cin >> n >> m;
	vector<int> a(n+1);
	rep(i,1,n+1) cin >> a[i]; // 1 based indexing
	vector<int> p(m+2, 0), c(m+2, 0);
	rep(i,1,n+1){
		rep(x,1,m+1){
			if(i == 1){
				c[x] = (a[i] == 0 or a[i] == x) ? 1 : 0;
			}
			else {
				c[x] = (a[i] == 0 or a[i] == x) ? ((p[x-1]+p[x])%M+p[x+1]) : 0;
			}
		}
		p = c;
	}
	
	int ans = 0;
	rep(x,1,m+1) ans = (ans+p[x])%M;
	cout << ans << "\n";
	
}

signed main(){
	solve();
	return 0;
}
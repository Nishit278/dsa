#include "bits/stdc++.h"
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll


const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=0;

void solve(){
	int n; cin >> n;
	cout << (n-6)/3  << endl;
	// if(n < 8){
	// 	cout << 0 << endl;
	// 	return;
	// }
	// int res = INT_MIN;
	// int l = 2, h = n-2;
	// while(h-l-1 >= 3){
	// 	int mid = l + (h-l)/2;
	// 	int g1=l-1ll,g2=mid-l-1ll,g3=h-mid-1ll, mn = INT_MAX;
	// 	if(g2 > 0 and g3 > 0){
	// 		mn = min(g1, min(g2,g3));
	// 		res = max(res, mn);
	// 		l++;
	// 	} else {
	// 		break;
	// 	}
	// }
	// cout << res << endl;

}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
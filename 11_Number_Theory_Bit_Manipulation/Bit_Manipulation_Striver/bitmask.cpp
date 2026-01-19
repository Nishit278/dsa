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

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif


const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=0;

void print_mask(int bitmask){
	for(int i=0;i<64;i++){
		if((bitmask & (1<<i))) cout << 1;
		else cout << 0;
	}
	cout << endl;
}
void solve(){
	int n; cin >>n;
	vector<int> a(n);
	for(int &i: a) cin >> i;

	// int l = reduce(all(a), 0);
	// cout << l << endl;
	long long bitmask = 0;
	rep(i,0,n){
		bitmask = (bitmask | (1 << a[i]));
	}
	rep(i,0,32){
		if((bitmask & (1<<i))) cout << i << endl;
	}
}


// int fibo(int n){
// 	vector<int> dp(n+1);
// 	dp[0]=0; dp[1]=1;
// 	for(int i=2;i<=n;i++){
// 		dp[i]=dp[i-1]+dp[i-2];
// 	}
// 	return dp[n];
// }
// void solve(){
// 	string s; cin >> s;
// 	int n = s.size();
// 	int res = 0;
// 	for(auto i: s){
// 		res += fibo(i-'A');
// 	}
// 	cout << res << endl;
// }

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
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
	vector<string> a(n),b(n),c(n);
	map<string, int> mp;
	rep(i,0,n){
		cin >> a[i];
		mp[a[i]]++;
	}
	rep(i,0,n){
		cin >> b[i];
		mp[b[i]]++;
	}
	rep(i,0,n){
		cin >> c[i];
		mp[c[i]]++;
	}
	int s1=0,s2=0,s3=0;
	// for(auto i: mp){
	// 	cout << i.fr << " -> " << i.sc << endl; 
	// }

	rep(i,0,n){
		s1 = (mp[a[i]] == 1) ? s1+3 : s1+3-mp[a[i]];
		s2 = (mp[b[i]] == 1) ? s2+3 : s2+3-mp[b[i]];
		s3 = (mp[c[i]] == 1) ? s3+3 : s3+3-mp[c[i]];
		// cout << s1 << " ";
	}
	cout << s1 << " " << s2 << " " << s3 << endl;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
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
vector<vector<int>> v(102, vector<int>(20001,0));

int n, ans;

void dfs(int idx, int x, int y, vector<int> &a, vector<int> &b){
	if(idx == n+1){
		ans = max(ans, min(x,y));
		return;
	}
	if(v[idx][x] >=y && v[idx][x]!=0) return;
	v[idx][x] = y;
	dfs(idx+1,x+a[idx],y,a,b);
	dfs(idx+1,x,y+b[idx],a,b);
}

void solve(){
	cin >> n;
	ans = 0;

	rep(i,1,n+1){
		rep(j,0,20001)
			v[i][j] = 0;
	}
	vector<int> a(102);
	vector<int> b(102);
	rep(i,1,n+1) cin>>a[i];
	rep(i,1,n+1) cin >> b[i];
	dfs(1,0,0,a,b);
	cout << ans << endl;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
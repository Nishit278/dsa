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

const int N=1e7+7;

int parent[N];
int rnk[N];

int find(int i){
	if(i == parent[i]) return i;
	return parent[i] = find(parent[i]);
}

void unionn(int u, int v){
	u = find(u);
	v = find(v);
	if(rnk[u]<rnk[v]){
		parent[u] = v;
	} else if(rnk[v] < rnk[u]){
		parent[v] = u;
	} else {
		parent[u] = v;
		rnk[u]++;
	}

}

	void solve(){
		int n; cin >> n;
		vector<char> v(2*n);
		rep(i,0,2*n){
			cin >> v[i];
		}
		int res = n;
		rep(i,0,2*n-1){
			// cout << i << " " << i+1 << endl;
			if(v[i] == ')' and v[i+1] == '(')
				res--;
		}
		cout << res << endl;
		


	}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
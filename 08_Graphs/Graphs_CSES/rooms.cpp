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

int dfs(vector<vector<char>> &map, int i, int j){
	int n = map.size(), m = map[0].size();
	if(i<0 or j<0 or i>=n or j>=m or map[i][j]!='.')
		return 0;
	map[i][j] = '$';
	dfs(map, i+1, j);
	dfs(map, i-1, j);
	dfs(map, i, j+1);
	dfs(map, i, j-1);
	return 1;
}

void solve(){
	int n, m; cin >> n >> m;
	vector<vector<char>> map(n, vector<char>(m));
	for(auto &i: map){
		for(auto &j: i) cin>>j;
	}
	int res = 0;
	rep(i, 0, n){
		rep(j, 0, n){
			if(map[i][j] == '.'){
				res += dfs(map, i ,j);
			}
		}
	}
	cout << res << endl;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
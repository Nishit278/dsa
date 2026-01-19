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

// vector<vector<int>> dp;
// int f(int i, int j, int n, vector<vector<char>> &grid){
// 	if(i>=n or j>=n or grid[i][j] =='*') return 0;
// 	if(i==n-1 and j==n-1) return 1;
// 	if(dp[i][j] != -1) return dp[i][j];
// 	int down = f(i+1, j, n, grid)%M;
// 	int right = f(i, j+1, n, grid)%M;
// 	return dp[i][j] = (down+right)%M;
// }
void solve(){
	int n; cin >> n;
	vector<vector<char>> grid(n, vector<char>(n));
	rep(i,0,n){
		rep(j,0,n)
			cin >> grid[i][j];
	}
	// dp.resize(n, vector<int> (n,-1));
	// cout << f(0,0,n,grid);
	vector<vector<int>> dp(n+1, vector<int>(n+1));
	dp[0][1] = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j] = grid[i-1][j-1] == '*'? 0 : dp[i-1][j]+dp[i][j-1];
			dp[i][j] %= M;
		}
	}
	cout << dp[n][n];
			
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
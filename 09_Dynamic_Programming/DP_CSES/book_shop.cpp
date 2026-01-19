#include "bits/stdc++.h"
using namespace std;
// #define int               long long
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

// int f(int n, int x, vector<int> &price, vector<int> &pages, vector<vector<int>> &dp){
// 	if(n < 0 or x==0) return 0;
// 	if(dp[n][x]!=-1) return dp[n][x];
// 	if(x-price[n]>=0)
// 		return dp[n][x] = max(pages[n]+f(n-1, x-price[n], price, pages, dp), f(n-1, x, price, pages, dp));
// 	else return dp[n][x] = f(n-1, x, price, pages, dp);
	
	
// }

void solve(){
	int n, x; cin >> n >> x;
	vector<int> pages(n), price(n);
	
	rep(i,0,n) cin >> price[i];
	rep(i,0,n) cin >> pages[i];
	vector<vector<int>> dp(n+1, vector<int> (x+1, 0));
	// cout << f(n-1, x, price, pages, dp);			
	for(int i=1;i<=n;i++){
		for(int j=1;j<=x;j++){
			if(price[i-1]<=j)
				dp[i][j] = max(pages[i-1]+dp[i-1][j-price[i-1]], dp[i-1][j]);
			else 
				dp[i][j] = dp[i-1][j];
		}
	}
	cout <<  dp[n][x] << endl;
	
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
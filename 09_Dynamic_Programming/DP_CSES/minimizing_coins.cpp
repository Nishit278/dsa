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
// int f(int n, int target, vector<int> &arr){
// 	if(n<0 or target < 0) return 0;
// 	// if(dp[n-1][target] != -1) return dp[n-1][target];
	
// 	if(target-arr[n]>=0)
// 		return 1+f(n, target-arr[n], arr);
// 	else f(n-1, target, arr);
// }
void solve(){
	int n, target;
	cin >> n >> target;
	vector<int> arr(n);
	rep(i,0,n) cin>> arr[i];

	// dp.resize(n, vector<int>(target, -1));
	// cout << f(n-1, target, arr);
	vector<int> dp(target+1, MM);
	dp[0] = 0; // for target = 0 select 0 coins
	for(int i=1;i<=target;i++){ // i is target
		for(int j=0;j<n;j++){
			if(arr[j] > i) continue;
			dp[i] = min(dp[i], 1 + dp[i-arr[j]]);
			dp[i] %= M;
		}
	}
	// for(auto i: dp) cout << i <<" ";
	if(dp[target] == MM) cout << -1 << endl;
	else cout << dp[target]%M;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	solve();
	return 0;
}
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
	int n, target;
	cin >> n >> target;
	vector<int> arr(n);
	rep(i, 0, n) cin >> arr[i];
	// vector<vector<int>> dp(n+1, vector<int> (target+1, 0));
	vector<int> dp(target+1, 0);
	dp[0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=target;j++){
			if(arr[i-1]<=j){
				dp[j] = dp[j] + dp[j-arr[i-1]];
				dp[j] %= M;
			}
		}
	}
	// for(auto i: dp) cout << i << " ";
	cout << dp[target]%M;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
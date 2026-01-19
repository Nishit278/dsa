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
	int n; cin>>n;
	vector<int> nums(n);
	for(auto &i: nums) cin >> i;
	if(nums.size() == 1){
		cout << 0 << endl;
		return;
	}

	// rotating the entire array 
	int ans = INT_MIN;
	for(int i=0;i<n-1;i++){
		ans = max(ans, nums[i]- nums[i+1]);
	}
	// keeping the first element
	for(int i = 1;i<n;i++){
		ans = max(ans, nums[i]-nums[0]);
	}
	// keeping the last eleement
	for(int i=0;i<n-1;i++){
		ans = max(ans, nums[n-1]-nums[i]);
	}
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
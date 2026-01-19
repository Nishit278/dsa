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
	vector<int> nums(n), prefix(n);
	for(auto &i: nums) cin >> i;
	sort(nums.begin(), nums.end());
	int sum = nums[0] + nums[n-1];
	int res = 0;
	int i=0, j=n-1;
	bool flag = false;
	while(i<j){
		if(nums[i] + nums[j] != sum){
			flag = true;
			break;
		}
		res = (res+(nums[i++] * nums[j--])%INF)%INF;
	}
	if(flag){
		cout << -1 << endl;
	} else {
		cout << res << endl;		
	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
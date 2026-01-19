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
	int n;cin>>n;
	vector<int> arr(n);
	for(auto &i: arr) cin>>i;
	int target = 0;
	int low = 0, high = n;
	while(low<=high){
		int mid = (low+high)/2;
		// cout << mid << endl;
		int l = mid == 0 ? INT_MIN : arr[mid-1];
		int r = mid == n ? INT_MAX : arr[mid];
		// cout << l <<" " <<r << endl;     

		if(l == r){
			target = arr[mid];
			break;
		} else if(l>r){
			high = mid-1;
		} else {
			low = mid+1;
		}
	}

	int first = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
	int last = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
	cout << first << " " << last << endl;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
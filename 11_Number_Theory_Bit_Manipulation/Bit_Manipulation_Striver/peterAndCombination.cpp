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
	vector<int> a(n);
	for(auto &i: a) cin >> i;
	int sz = (1<<n)-1;
	
	bool flag = false;
	for(int i=0;i<sz;i++){
		int sum = 0;
		for(int bit = 0;bit<n;bit++){
			int mask = (1<<bit);
			if(i & mask) sum -= a[bit];
			else sum+=a[bit];
		}
		if(sum % 360 == 0){
			flag = true;
			break;
		}
	}
	if(flag) cout << "YES" << endl;
	else cout << "NO" << endl;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}

/***
 * https://codeforces.com/problemset/problem/1097/B
 * create the power set for the input 
 * where 0 can be denoted as - and 1 can be denoted for +
 * 0 0 0 -> all rotations anti- clockwise
 * 0 0 1 -> first 2 anti and last one clockwise
 * 0 1 0 -> first anti then clock then anti again
 * 
 * after all three rotations check if res % 360 == 0 or res == 0 then ans = YES
 * else ans = NO
 ***/
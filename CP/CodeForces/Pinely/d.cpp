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
int power(int x, int y, int p)
{
	int res = 1;
	while (y > 0) {
		if (y % 2 == 1)
			res = (res * x);
		y = y >> 1;	
	x = (x * x);
	}
	return res % p;
}

void solve(){
	int n, k;
	cin >> n >> k;
	map<int,int> mp;
	int dest = power(2,n,M);
	cout << dest << endl;
	rep(i,0,dest){
		int x = ppc(i);
		mp[i] = x;
	}
	int res = 0;
	rep(i,1,dest){
		rep(j,1,dest/2){
			int x = mp[i]+mp[j]-mp[i+j];
			if(x == k){
				res = (i == j) ? res + 1 : res + 2; 
			}
		}
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

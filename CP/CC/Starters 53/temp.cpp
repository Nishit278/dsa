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
	int n, k;
	cin >> n >> k;
	int ri=k, r1=ri, r2=0, r3=0;
	for(int i=0;i<n;i++){
		int temp = ri;
		int temp2 = r3;
		ri = ri + (2*r1+3*r2-r3);
		r3=r2;
		r2=r1;
		r1=ri-temp+temp2;
	}
	cout << "White rats: " << ri << endl;

	int bi=k, b1=k, b2=0;
	for(int i=0;i<n;i++){
		int t1=bi, t2=b2;
		bi = bi+(3*b1 - b2);
		b2 = b1;
		b1 = bi - t1 + t2; 
	}
	cout << "Black rats: " << bi << endl;

	cout << abs(ri-bi) << endl;
	
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
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
bool alice_win(int odd, int even){
	if(odd % 4 == 3 or odd % 4 == 0) return true;
	return ((even%4 == 1 or even%4==3) and (odd%4 == 1));
}
void solve(){
	int n; cin>>n;
	vector<int> a(n);	
	for(auto &i: a) cin >> i;
	int odd = 0, even = 0;
	for(int i: a){
		if((i&1)) odd++;
		else even++;
	}
	if(alice_win(odd, even)){
		cout << "Alice" << endl;
	} else {
		cout << "Bob" << endl;
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
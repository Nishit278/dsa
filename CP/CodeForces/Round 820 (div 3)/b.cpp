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

const int N=1e5+7;


void solve(){
	int n ; cin >> n;
	string s; cin >> s;
	string res  = "";
	for(int i=n-1;i>=0;i--){
		char temp = char('a'+ (s[i]-'0'-1));
		if(s[i]-'0' == 0){
			string str = s.substr(i-2, 3);
			int num = stoi(str)/10;
			res.pb(char('a' + num -1));
			i-=2;
		} else {
			res.pb(temp);

		}
	}
	reverse(all(res));
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
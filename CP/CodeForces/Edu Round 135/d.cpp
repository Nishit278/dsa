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
	string s; cin >> s;
	string a = "", b = "";
	int n = s.size();
	int i = 0, j = n-1;
	bool acb= true, bcb = true;
	while(i<=j){
		if(acb){
			if(s[i]>s[j]){
				a.push_back(s[j]);
				j--;
			} else {
				a.pb(s[i]);
				i++;
			}
			acb = !acb;
		}
		if(bcb){
			if(s[i]>s[j]){
				b.pb(s[j]);
				j--;
			} else {
				b.pb(s[i]);
				i++;
			}
			bcb = !bcb;
		}
		else {
			a.pb(s[j]);
			j--;
			b.pb(s[j]);
			j--;
		}	
	}
	
	reverse(all(a));
	reverse(all(b));
	cout << a << " " << b << endl;
	if(a<b){
		cout << "ALICE" << endl;
	} else if(b<a){
		cout << "BOB" << endl;
	} else {
		cout << "DRAW" << endl;
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
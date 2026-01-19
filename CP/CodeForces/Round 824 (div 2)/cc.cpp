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

int rowNbr[] = { -1, 1, 0, 0,1,1,-1,-1 };
int colNbr[] = { 0, 0, 1, -1,1,-1,1,-1 };

const double PI = 3.141592653589793238;

void solve(){
	double r, v; cin >> r >> v;
	cout << (3*v)/(2*PI*pow(r,2)) << endl;
}

// void solve(){
// 	int n; cin>> n;
// 	vector<int> v(n);
// 	for(auto &i : v) cin>>i;

// 	int sum = accumulate(all(v),0);
// 	int s=sum/2;
	
// 	vector<int> curr(s+1, 0), prev(s+1,0);
// 	for(int i=1;i<=n;i++){
// 		for(int j=1;j<=s;j++){
// 			if(v[i-1] <= j){
// 				curr[j] = max(v[i-1]+prev[j-v[i-1]], prev[j]);
// 			} else if (v[i-1] > j){
// 				curr[j] = prev[j];
// 			}
// 		}
// 		prev = curr;
// 	}
// 	cout << sum - 2*prev[s] << endl; 
// }

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
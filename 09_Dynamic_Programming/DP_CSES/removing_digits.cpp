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

// DP
// void solve(){
// 	int n; cin >> n;
// 	vector<int> dp(n+1);
// 	dp[0] = 0;
// 	for(int i=1;i<=n;i++){ // numbers between 1 and n
// 		int temp = i;
// 		int minSteps = 1e7+5;
// 		while(temp!=0){
// 			int curr = temp%10;
// 			temp/=10;
// 			if(curr == 0 )continue; // if curr = 0 it will get stuck in an infinite loop like 230, subtrating 0 from it is worthless
// 			minSteps = min(minSteps, 1+dp[i-curr]); // we want the closest to 0 way
// 			cout << "curr: " << curr << " minsteps: " << minSteps << endl;
// 		}
// 		dp[i] = minSteps;
// 	}
// 	cout << dp[n] << endl;
// }
void greedy(){
	int n; cin>> n;
	int steps = 0;
	while(n>0){
		string s = to_string(n);
		char maxDigit = '0';
		steps++;
		for(auto i: s){
			maxDigit = max(i, maxDigit);
		}
		n-=maxDigit-'0';
	}
	cout << steps << endl;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	// solve();
	greedy();
	return 0;
}
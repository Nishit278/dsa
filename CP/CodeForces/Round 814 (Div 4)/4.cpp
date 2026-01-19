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
	string s; cin >> s;
	string str = "";
	rep(i,0,n){
		if(i<n/2){
			str.pb('R');
		}else {
			str.pb('L');
		}
	}

	vector<int> p1(n), p2(n), p3(n), ans;
	int sum = 0;
	rep(i, 0, n){
		if(s[i] == 'L'){
			p1[i] = i;
		} else {
			p1[i] = n-i-1;
		}
		sum += p1[i];
	}

	rep(i,0,n){
		if(str[i] == 'L') p2[i] = i;
		else p2[i] = n-i-1;
	}
	
	rep(i,0,n){
		p3[i] = p2[i]-p1[i];
	}
	sort(all(p3), greater<int>());
	// rep(i,0,n) cout << p3[i] << " ";
	// cout << endl;

	rep(i,0,n){
		sum += p3[i];
		// ans.pb(sum);
		cout << sum << " ";
	}
	cout << endl;



	
	

}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}

// while(i<=j and k<=n){
// 		if(n-i-1 >= j and s[i]!=str[i]){
// 			sum = sum - res[i] + (n-i-1);
// 			ans.pb(sum);
// 			i++, k++;
// 		}
// 		else if(j > n-i-1 and s[j]!= str[j]){
// 			sum = sum - res[j] + j;
// 			ans.pb(sum);
// 			j--, k++;
// 		}
// 		// else if(j == n-i-1){
// 		// 	if(res[i] > res[j]){
// 		// 		sum = sum - res[j] + j;
// 		// 		ans.pb(sum);
// 		// 		j--, k++;
// 		// 	} else {
// 		// 		sum = sum - res[i] + (n-i-1);
// 		// 		ans.pb(sum);
// 		// 		i++, k++;
// 		// 	}
// 		// }
// 		else {
// 			i++;
// 			j--;
// 			k++;
// 		}
// 	}
// 	for(auto i: ans){
// 		cout << i << " ";
// 	}
// 	cout << endl;
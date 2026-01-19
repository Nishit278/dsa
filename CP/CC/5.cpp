#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
#define int long long int
#define pb push_back
#define mp make_pair
#define s second
#define f first

const int mod = 1e10+7;
signed main(){
	int t; cin >> t;
	while(t--){
		int x, m; cin >> x >> m;		
		
		int moves = ceil(log2(x))+1;
		if(moves > m){
			cout << 0 << endl;
		} else {
			cout << (m-moves+1) << endl;
		}
		

	}
	return 0;
}
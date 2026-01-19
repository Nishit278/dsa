#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
#define ll long long 
#define pb push_back
#define mp make_pair
#define s second
#define f first


int main(){
	int t; cin >> t;
	while(t--){
		int hc =1, vc =1;
		int n; cin >> n;
		unordered_set <int> s1;
		unordered_set <int> s2;
		while(n--){
			int x, y; cin >> x >> y;
			s1.insert(x);
			s2.insert(y);
		}
		cout << (s1.size()+s2.size()) << endl;
	}
	return 0;
}
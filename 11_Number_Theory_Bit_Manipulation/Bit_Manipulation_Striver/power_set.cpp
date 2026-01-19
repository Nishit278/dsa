#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> a(n);
	for(auto &i: a) cin >> i;
	int sz = (1 << n) - 1; // 2^n -1
	
	vector<vector<int>> res;
	for(int i = 0; i<sz; i++){
		vector<int> subset;
		for(int bit = 0; bit< n; bit++){
			if(i & (1 << bit)) subset.push_back(a[bit]);
		}
		for(auto i: subset){
			cout << i << " ";
		}
		cout << endl;
	}
}

int main(){		
	solve();
	return 0;
}
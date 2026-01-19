#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
#define ll long long 
#define pb push_back
#define mp make_pair
#define s second
#define f first



int mex(vector<int>a){
	int n = a.size();
	vector<int> hsh(N,0);
	int mex_ = 0;
	for(auto i: a){
		hsh[i]++;
	}
	for(int i=0;i<2*n;i++){
		if(hsh[i]==0){
			mex_ = i;
			break;
		}
	}
	// for(int i=0;i<n;i++){
	// 	cout << hsh[i] << " ";

	// }
	// cout << endl;
	return mex_;
}

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		map<int, int> mp;
		for(int i=0;i<2*n;i++){
			int x;
			cin >>x;
			mp[x]++;
		}
		
		for(int i=0;i<=n+1;i++){
			if(mp[i]==0){
				cout << "YES\n";
				break;
			} 
			if(mp[i]==1){
				cout << "NO\n";
				break;
			}
		}
	}

	return 0;
}
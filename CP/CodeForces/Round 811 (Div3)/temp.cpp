#include "bits/stdc++.h"
using namespace std;
#define int               long long

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=0;

void solve(){
	int n; cin >> n;
	vector<int> nums(n);
	vector<vector<int>> toppers(n);
	for(int i=0;i<n;i++){
		cin >> nums[i];
		toppers[nums[i]].push_back(i);
	}
	int k; cin >> k;
	sort(nums.begin(), nums.end(), greater<int>());
	for(int i=0;i<k;i++){
		for(auto nbr: toppers[nums[i]]){
			cout << nbr << " ";
		}
	}
	cout << endl;

}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
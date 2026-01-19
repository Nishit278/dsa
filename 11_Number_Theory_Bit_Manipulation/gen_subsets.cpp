#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums){
	int n = nums.size();
	int sub_count = (1<<n); // 2 to the power n 
	vector<vector<int>> subs;
	for(int mask = 0; mask < sub_count; ++mask){
		vector<int>subset;
		for( int i=0;i<n;++i){
			if((mask & (1<<i)) != 0){
				subset.push_back(nums[i]);
			}
		}
		subs.push_back(subset);
	}
	return subs;
}

int main(){
	int n; cin >> n;
	vector <int> v(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	auto all_subsets = subsets(v);
	for(auto subset : all_subsets){
		cout << "[";
		for (auto element : subset){
			cout << element << "," ;
		}
		cout << "]"<< endl;
	}

	return 0;
}
// 2^n subsets of an n size array 
// we use bit masking, each subset is represented as a bit mask 
// bitmasks for an n size array are 0 - 2^(n-1) (^ is power)
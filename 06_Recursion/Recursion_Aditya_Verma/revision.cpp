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

void printVector(vector<vector<int>> ans){
	for(auto i: ans){
		cout << "[";
		for(auto j: i){
			cout << j << ',';
		}
		cout << "] ";
	}
	cout << endl;

}

// print subsequences for an array
vector<int> res;
void subsequences(int idx, vector<int> nums){
	if(idx >= nums.size()){
		for(auto i: res){
			cout << i << " ";
		}
		cout << endl;
		return;
	}
	res.pb(nums[idx]);
	subsequences(idx+1, nums);
	res.pop_back();
	subsequences(idx+1, nums);
}

void combinationSum(int idx, vector<int> nums,int target){
	if(target==0){
		for(auto i: res){
			cout << i << " ";
		}
		cout << endl;
		return;
	}
	if(target<0 or idx >= nums.size()){
		return;
	}
	res.pb(nums[idx]);
	combinationSum(idx+1, nums, target-nums[idx]);
	res.pop_back();
	combinationSum(idx+1, nums, target);
}
int countSubSum(int idx, vector<int> nums, int target){
	if(idx == nums.size()){
		if(target == 0) return 1;
		else return 0;
	}
	return countSubSum(idx+1, nums, target-nums[idx]) 
	+ countSubSum(idx+1, nums, target);
}
set<int> subSum;
void subsetSum(int idx, vector<int> nums, int sum){
	if(idx == nums.size()){
		subSum.insert(sum);
		return;
	}
	subsetSum(idx+1, nums, sum+nums[idx]);
	subsetSum(idx+1, nums, sum);
}

void dpSolve(){
	vector<int> nums {2,1,4,3,7,6};
	int curr = 0, prev = nums[0];
	for(int i=1;i<nums.size();i++){
		curr = prev + nums[i];
		prev = curr;
	}
	cout << curr << endl;
}


vector<vector<int>> ans;
vector<int> ds;
void subsetII(int idx, vector<int> nums){
	ans.pb(ds);
	rep(i, idx, nums.size()){
		if(i>idx and nums[i]==nums[i-1]) continue;
		ds.pb(nums[i]);
		subsetII(i+1, nums);
		ds.ppb();
	}
}
vector<int> freq;
void permutations(vector<int> &nums){
	if(ds.size() == nums.size()){
		ans.push_back(ds);
		return;
	}
	rep(i,0,nums.size()){
		if(freq[i]) continue;
		freq[i] = 1;
		ds.pb(nums[i]);
		permutations(nums);
		ds.ppb();
		freq[i] = 0;
	}
}

void solve(){
	vector<int> nums = {3,1,2};
	// subsequences(0,nums);
	// int target = 3;
	// combinationSum(0, nums, target);
	// cout << "Count of possible answers: " << countSubSum(0, nums, target) << endl;
	// subsetSum(0, nums, 0);
	// for(auto i: subSum){
	// 		cout << i << " ";
	// 	}
	// cout << endl;
	// dpSolve();
	// vector<int> arr = nums;
	// sort(all(arr));
	// subsetII(0, arr);
	// printVector(res);
	freq.resize(nums.size()+1, 0);
	permutations(nums);
	printVector(ans);

	return;

}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
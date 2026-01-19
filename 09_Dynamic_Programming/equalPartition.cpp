//https://leetcode.com/problems/partition-equal-subset-sum/
//same as subset sum on gfg

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
const int N = 1e3+10;

//https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/#
int dp[N][N];
// bool isSubsetSum(vector<int>& arr, int sum, int n) {
// 	if(sum == 0) return true;
// 	if(n < 0) return false;
// 	if(dp[n][sum] != -1) return dp[n][sum];
// 	bool isPossible = isSubsetSum(arr, sum, n-1);
// 	isPossible |= isSubsetSum(arr, sum-arr[n], n-1);
// 	return dp[n][sum] = isPossible;
// }
// bool canPartition(vector<int>& nums) {
// 	memset(dp, -1, sizeof(dp));
// 	int sum = accumulate(nums.begin(), nums.end(), 0);
// 	if(sum%2!=0) return false;
// 	sum/=2;
// 	return isSubsetSum(nums, sum, nums.size()-1);        
// }

bool canPartition(vector<int> & nums){
	int n = nums.size();
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if(sum & 1 == 1) return false;
	sum /= 2;
	int dp[n+1][sum+1];
	for(int i=0;i<n+1;i++){
		for(int j=0;j<sum+1;j++){
			if(i==0) dp[i][j]==0;
			if(j==0) dp[i][j]==1;
		}
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<sum+1;j++){
			if(nums[i-1]<=j){
				dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
			} else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][sum];
}



int main(){
	int n; cin >> n;
	vector<int> nums(n);
	rep(i,0,n){
		cin >> nums[i];
	}
	
	cout << canPartition(nums) << endl;
	// for(int i=25;i<=n+1;i++){
	// 	for(int j=40;j<=target+1;j++){
	// 		cout << dp[i][j] << ", ";
	// 	}
	// 	cout << endl;
	// }

}
#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
const int N = 1e3+10;


int targetSum(vector<int>& nums, int diff) {
	int n = nums.size();
	int sum = accumulate(nums.begin(), nums.end(), 0);
	int target = (diff+sum)/2;
	if(diff > sum or (sum+diff)%2 != 0) return 0;
	int dp[n+1][sum+1];
	memset(dp, -1, sizeof(dp));

	for(int i=0;i<=n;i++){
		for(int j=0;j<=sum;j++){
			if(i==0) dp[i][j]=0;
			if(j==0) dp[i][j]=1;
		}
	}
	int c = 0;
	for(auto i: nums){
		if(i == 0) c++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(nums[i-1] > j || nums[i-1]==0){
				dp[i][j] = dp[i-1][j];
			} else {
				dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
			}
		}
	}

	for(int i=0;i<=n;i++){
		for(int j=0;j<=sum;j++){
			cout << dp[i][j] << ", ";
		}
		cout << endl;
	}

	return pow(2,c)*dp[n][target];
}



int main(){
	int n; cin >> n;
	vector<int> nums(n);
	rep(i,0,n){
		cin >> nums[i];
	}
	int diff; cin >> diff;
	
	cout << targetSum(nums, diff) << endl;
	// for(int i=25;i<=n+1;i++){
	// 	for(int j=40;j<=target+1;j++){
	// 		cout << dp[i][j] << ", ";
	// 	}
	// 	cout << endl;
	// }

}
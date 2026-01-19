#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
const int N = 1e3+10;

//https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/#

int isSubsetSum(vector<int>& arr, int sum) {
	int n = arr.size();
	int dp[n+1][sum+1];
	memset(dp, -1, sizeof(dp));

	for(int i=0;i<=n;i++){
		for(int j=0;j<=sum;j++){
			if(i==0) dp[i][j]=0;
			if(j==0) dp[i][j]=1;
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(arr[i-1]<=j){
				dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
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
	int diff; cin >> diff;
	int sum = accumulate(nums.begin(), nums.end(), 0);
	int target = (diff+sum)/2;
	cout << isSubsetSum(nums, target) << endl;
	// for(int i=25;i<=n+1;i++){
	// 	for(int j=40;j<=target+1;j++){
	// 		cout << dp[i][j] << ", ";
	// 	}
	// 	cout << endl;
	// }

}
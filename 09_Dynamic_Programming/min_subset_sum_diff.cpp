#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
const int N = 1e3+10;


int isSubsetSum(vector<int>& nums, int sum) {
	int n = nums.size();
	int dp[n+1][sum+1];
	vector<int> s;
	memset(dp, -1, sizeof(dp));
	for(int i=0;i<=n;i++){
		for(int j=0;j<=sum;j++){
			if(i==0) dp[i][j]=0;
			if(j==0) dp[i][j]=1;
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(nums[i-1]<=j){
				dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
			} else {
				dp[i][j] = dp[i-1][j];
			}
			if(i == n){
				if(dp[i][j] == 1) s.push_back(j);
			}
		}
	}
	int mn = INT_MAX;
	for(int i=0;i< s.size()/2 ; i++){
		mn = min(mn, sum-(2*s[i]));
	}

	

	return mn;
}



int main(){
	int n; cin >> n;
	vector<int> nums(n);
	rep(i,0,n){
		cin >> nums[i];
	}
	int target = accumulate(nums.begin(), nums.end(), 0);
	cout << isSubsetSum(nums, target) << endl;
	

}
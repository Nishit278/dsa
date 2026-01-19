#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
const int N = 1e3+10;

//https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/#
// since 2 variables changing, we make 2d dp
int t[N][N];
int func(vector<int> arr, int sum, int n){
	if(n<0) return 0;
	if(sum == 0) return 1;
	if(t[n][sum]!=-1) return t[n][sum];
	if(arr[n-1] <= sum){
		return t[n][sum] = func(arr, sum-arr[n-1], n-1) + func(arr, sum, n-1);
	} else {
		return t[n][sum] = func(arr, sum, n-1);
	}
}

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
	memset(t, -1, sizeof(t));
	int n; cin >> n;
	vector<int> nums(n);
	rep(i,0,n){
		cin >> nums[i];
	}
	int target; cin >> target;
	cout << isSubsetSum(nums, target) << endl;
	cout << func(nums, target, n) << endl;
	// for(int i=0;i<=n+1;i++){
	// 	for(int j=0;j<=target+1;j++){
	// 		cout << t[i][j] << ", ";
	// 	}
	// 	cout << endl;
	// }

}
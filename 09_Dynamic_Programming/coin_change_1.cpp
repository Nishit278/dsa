#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)

const int N = 1e3+10;
int dp[N][N];

// bottom up 
// int t[1002][1002];
int knap_iterative(int coins[], int sum, int n){
	for(int i=0;i<n+1;i++){
		for(int j=0;j<sum+1;j++){
			if(i == 0) dp[i][j]=0;
			if(j == 0) dp[i][j]=1;
			// else dp[i][j]=1;
		}
	}

	for(int i=1;i<n+1;i++){
		for(int j=1;j<sum+1;j++){
			if(coins[i-1]<=j)
				dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
			else if(coins[i-1]>j)
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][sum];

}

int main(){
	memset(dp, -1, sizeof(dp));
	int n; cin >> n;
	int coins[n];
	rep(i,0,n){
		cin >> coins[i];
	}
	int sum; cin >> sum;

	cout << "Bottom Up(Tabulation): "<< knap_iterative(coins, sum,  n) << endl; 
	cout << "\nTable of Bottom up method: " << endl;
	for(int i=0;i<n+1;i++){
		for(int j=0;j<sum+1;j++){
			cout << dp[i][j] << ", ";
		}
		cout << endl;
	}

}
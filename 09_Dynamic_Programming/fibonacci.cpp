#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

// 0 1 1 2 3 5 8 13 21


//using brute force recursion Time complexity = O(2^n)
int fib(int n){
	if(n==0) return 0;
	if(n==1) return 1;
	return fib(n-1)+fib(n-2);
}

//using dp (top down) memoization Time complexity = O(n), badi problem ko simplify karna
int dp[N];
int dp_td(int n){
	if(n==0) dp[n] =  0;
	if(n==1) dp[n] =  1;
	if(dp[n]!=-1) return dp[n];
	return dp[n] = dp_td(n-1)+dp_td(n-2);
}

//using dp (bottom up) memoization, chhoti problem se badi
int dp2[N];
int dp_bu(int n){
	dp2[0]=0;
	dp2[1]=1;
	for(int i=2;i<=n;i++){
		dp2[i] = dp2[i-1]+dp2[i-2];
	}
	return dp[n];
}

int main(){
	int n; cin >> n;
	cout << fib(n) << endl;
	memset(dp, -1, sizeof(dp));
	cout << dp_td(n) << endl;
	cout << dp_bu(n) << endl;

	return 0;
}

// O(2^y) = O(y)
// O(N!) = O(2^N) using bitmasking dp 
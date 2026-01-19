// https://atcoder.jp/contests/dp/tasks/dp_a

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int dp[N];

int fun(int n, int h[]){
	if(n==0) return 0;
	if(n>1){
		return min(fun(n-1,h)+abs(h[n]-h[n-1]), fun(n-2,h)+abs(h[n]-h[n-2]));
	} else{
		return fun(n-1,h)+abs(h[n]-h[n-1]);
	}
}
// Luv's solution
// int td_dp(int n, int h[]){
// 	if(n==0) return 0;
// 	if(dp[n]!=-1) return dp[n];
// 	int cost = INT_MAX;
// 	cost = min(cost, td_dp(n-1,h)+abs(h[n]-h[n-1]));
// 	if(n>1)
// 	cost = min(cost, td_dp(n-2,h)+abs(h[n]-h[n-2]));
// 	return dp[n]=cost;
// }
int t[N];
//Nishit's Solution >///< (Bruh I'm genious)
int td_dp2(int n, int h[]){
	if(n==0) return 0;
	if(t[n]!=-1) return t[n];
	if(n>1){
		return t[n] = min(fun(n-1,h)+abs(h[n]-h[n-1]), fun(n-2,h)+abs(h[n]-h[n-2]));
	} else{
		return t[n] = fun(n-1,h)+abs(h[n]-h[n-1]);
	}
}

int main(){
	memset(dp, -1, sizeof(dp));
	memset(t, -1, sizeof(t));
	int n; cin >> n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	cout << "ans: " << fun(n-1, arr) << endl;
	// cout << td_dp(n-1, arr) << endl;
	cout << td_dp2(n-1, arr) << endl;
}
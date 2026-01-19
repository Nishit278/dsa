#include <bits/stdc++.h>
using namespace std;

int level = 1;

// Brute force recursion 
// int func(int amount, vector<int>& coins){
// 	int ans = INT_MAX;

// 	if(amount==0) return 0;
	
// 	for (auto coin : coins)
// 	{
// 		if(amount-coin>=0){
// 			cout << "current-coin: "<<  coin << endl;
// 			level++;
// 			ans = min(ans + 0LL, func(amount - coin, coins) + 1LL);
// 			level--;
// 			cout << "Current Level " << level << endl;
// 			cout << " ans: " << ans << endl;
// 		}
// 	}
// 	return ans;
// }


//using dp
/***
 * the changing variable is amount
 * upper limit of amount is 10^4 so we construct an array of size 1e4+10
 * if dp[amount]!=-1 return dp[amount]
 * ans = min(ans, func(amount-cost, costs)+1;
 * return dp[amount] = ans; 
 ***/

const int N = 1e4+10;
int dp[N];

int func(int amount, vector<int>& coins){
	int ans = INT_MAX;

	if(amount==0) return 0;
	if(dp[amount]!=-1) return dp[amount];
	for (auto coin : coins)
	{
		if(amount-coin>=0){
			ans = min(ans + 0LL, func(amount - coin, coins) + 1LL);
		}
	}
	return dp[amount] = ans;
}


int coinChange(vector<int>& coins, int amount) {
	memset(dp, -1, N);
	int res = func(amount, coins);
	return res == INT_MAX ? -1 : res;    
}

int main(){
	int amount; cin >> amount;
	vector<int> v = {1,2,5};
	cout << coinChange(v, amount) << endl;
}


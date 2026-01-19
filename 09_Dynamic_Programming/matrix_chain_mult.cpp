#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b; i++)
vector<int> v;

int solve(int a[], int i, int j){
	if(i>=j) return 0;
	int mn = INT_MAX;
	rep(k,i,j){
		int temp_ans = solve(a,i,k)+solve(a,k+1,j)+a[i-1]*a[k]*a[j];
		v.push_back(temp_ans);
		mn = min(mn, temp_ans);
	}
	return mn;
}
int static t[1001][1001];
int dp(int a[], int i, int j){
	if(i>=j) return 0;
	if(t[i][j]!=-1) return t[i][j];
	int mn = INT_MAX;
	rep(k,i,j){
		int temp_ans = solve(a,i,k)+solve(a,k+1,j)+a[i-1]*a[k]*a[j];
		// v.push_back(temp_ans);
		mn = min(mn, temp_ans);
	}
	return  t[i][j] = mn;
}

int main(){
	memset(t,-1,sizeof(t));
	int n; cin >> n;
	int a[n];
	rep(i,0,n){
		cin >> a[i];
	}
	cout << solve(a,1,n-1) << endl;
	cout << dp(a,1,n-1) << endl;
	// for(auto i: v){
	// 	cout << i << endl;
	// }
}
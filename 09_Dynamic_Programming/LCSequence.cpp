#include <bits/stdc++.h>
using namespace std; 

#define rep(i,a,b) for(int i=a; i<b; i++)
const int N = 1e3+2;
int static dp[N][N];

// brute force
int lcs_bf(string s1, string s2, int m, int n){

	if(n==0 or m==0) return 0;
	if(s1[m-1] == s2[n-1])
		return 1+lcs_bf(s1,s2,n-1,m-1);
	else
		return max(lcs_bf(s1,s2,n-1,m), lcs_bf(s1,s2,n, m-1));

}

// memoization (top-down dp)

int lcs_td(string s1, string s2, int m, int n){
	if(n == 0 or m == 0) return 0;
	if(dp[m][n]!= -1) return dp[m][n];
	if(s1[m-1] == s2[n-1]) return dp[m][n] = 1+lcs_td(s1,s2,n-1,m-1);
	else return dp[m][n] =  max(lcs_td(s1,s1,n-1,m), lcs_td(s1,s2,n,m-1));
}

// Bottom-up (tabulation)
int static t[1002][1002];
string lcs_bu(string s1, string s2, int m, int n){
	for(int i=0;i<m+1;i++){
		for(int j=0;j<n+1;j++){
			if(i == 0 or j == 0) t[i][j]=0;
		}
	}
	for(int i=1;i<m+1;i++){
		for(int j=1;j<n+1;j++){
			if(s1[i-1] == s2[j-1])
				t[i][j] = 1 + t[i-1][j-1];
			else 
				t[i][j] = max(t[i-1][j], t[i][j-1]);
		}
	}
	string ans = "";
	int i=m, j=n;
	while(i>0 and j>0){
		if(s1[i-1] == s2[j-1]){
			ans.push_back(s1[i-1]);
			i--;
			j--;
		} else {
			if(t[i-1][j]<t[i][j-1]) j--;
			else i--;
		}
	}
	reverse(ans.begin(),ans.end());
	cout << dp[m][n];
	return ans;
}

// string print_lcs(string s1, string s2, int m, int n){

// }

int main(){
	string s1, s2;
	cin >> s1 >> s2;
	memset(dp, -1, sizeof(dp));
	int m = s1.size();
	int n = s2.size();

	cout << lcs_bf(s1,s2,m,n) << endl;
	cout << lcs_td(s1,s2,m,n) << endl;
	cout << lcs_bu(s1,s2,m,n) << endl;
	// for(int i=0;i<m+1;i++){
	// 	for(int j=0;j<n+1;j++){
	// 		cout << t[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	// cout << print_lcs(s1,s1,m,n) << endl;
}
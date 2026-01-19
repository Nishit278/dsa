#include <bits/stdc++.h>
using namespace std; 

#define rep(i,a,b) for(int i=a; i<b; i++)
const int N = 1e3+2;
int static dp[N][N];

// Bottom-up (tabulation)
int static t[1002][1002];
int lcs_bu(string s1, string s2, int m, int n){
	int ans = INT_MIN;
	int row, col;
	for(int i=0;i<m+1;i++){
		for(int j=0;j<n+1;j++){
			if(i == 0 or j == 0) t[i][j]=0;
		}
	}
	for(int i=1;i<m+1;i++){
		for(int j=1;j<n+1;j++){
			if(s1[i-1] == s2[j-1]){
				t[i][j] = 1 + t[i-1][j-1];
				row = i;
				col = j;				
			}

			else 
				t[i][j] = 0;
			ans = max(ans,t[i][j]);
			
		}
	}
	cout << row << " " << col << endl;
	return ans;
}

int main(){
	string s1, s2;
	cin >> s1 >> s2;
	memset(dp, -1, sizeof(dp));
	int m = s1.size();
	int n = s2.size();

	cout << lcs_bu(s1,s2,m,n) << endl;
	for(int i=0;i<m+1;i++){
		for(int j=0;j<n+1;j++){
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
}
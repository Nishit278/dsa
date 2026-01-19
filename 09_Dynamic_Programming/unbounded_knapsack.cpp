#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)

const int N = 1e3+10;
int dp[N][N];

// bottom up 
int t[1002][1002];
int knap_iterative(int wt[], int val[], int w, int n){
	for(int i=0;i<n+1;i++){
		for(int j=0;j<w+1;j++){
			if(i == 0 or j == 0) t[i][j]=0;
			// else t[i][j]=1;
		}
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<w+1;j++){
			if(wt[i-1]<=j)
				t[i][j] = max(val[i-1] + t[i][j-wt[i-1]], t[i-1][j]);
			else if(wt[i-1]>j)
				t[i][j] = t[i-1][j];
		}
	}
	return t[n][w];

}

int main(){
	memset(dp, -1, sizeof(dp));
	int n; cin >> n;
	int wt[n], val[n];
	rep(i,0,n){
		cin >> wt[i];
	}
	rep(i,0,n){
		cin >> val[i];
	}
	int w; cin >> w;

	cout << "Bottom Up(Tabulation): "<< knap_iterative(wt, val, w, n) << endl; 
	cout << "\nTable of Bottom up method: " << endl;
	for(int i=0;i<n+1;i++){
		for(int j=0;j<w+1;j++){
			cout << t[i][j] << ", ";
		}
		cout << endl;
	}

}
#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)

const int N = 1e3+10;
int dp[N][N];

// bottom up 
int t[1002][1002];
int knap_iterative(int length[], int price[], int n){
	for(int i=0;i<n+1;i++){
		for(int j=0;j<n+1;j++){
			if(i == 0 or j == 0) t[i][j]=0;
			// else t[i][j]=1;
		}
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			if(length[i-1]<=j)
				t[i][j] = max(price[i-1] + t[i][j-length[i-1]], t[i-1][j]);
			else if(length[i-1]>j)
				t[i][j] = t[i-1][j];
		}
	}
	return t[n][n];

}

int main(){
	memset(dp, -1, sizeof(dp));
	int n; cin >> n;
	int length[n], price[n];
	rep(i,0,n){
		length[i]=i+1;
	}
	rep(i,0,n){
		cin >> price[i];
	}

	cout << "Bottom Up(Tabulation): "<< knap_iterative(length, price, n) << endl; 
	cout << "\nTable of Bottom up method: " << endl;
	for(int i=0;i<n+1;i++){
		for(int j=0;j<n+1;j++){
			cout << t[i][j] << ", ";
		}
		cout << endl;
	}

}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

int solve(int a[], int n){
   vector<int> b;
   set<int> s;
   
   rep(i,0,n){
       s.insert(a[i]);
   }
   for(auto it = s.begin(); it!=s.end(); it++){
       b.push_back(*it);
   }
   int m = b.size();
   int dp[n+1][m+1];
   rep(i,0,n+1){
       rep(j,0,m+1){
           if(i==0 or j==0) dp[i][j]=0;
       }
   }
   rep(i,1,n+1){
       rep(j,1,m+1){
           if(a[i-1]==b[j-1]){
               dp[i][j] = 1+dp[i-1][j-1];
           } else {
               dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
           }
       }
   }
   return dp[n][m];
}
int main(){
	int n; cin >> n;
	int a[n];
	rep(i,0,n){
		cin >> a[i];
	}
	cout << solve(a, n);

}
/**
 * Given 2d array a of N*N integers. Given Q
 * queries and in each qiery given a , b, c and d print 
 * sum of sqare represented by (a,b) as top left point and (c,d) as
 * top bottom right point
 **/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
int a[N][N];
long long pf[N][N];

int main(){
	int n; cin >> n;
	for(int i=1;i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> a[i][j];
			pf[i][j] = a[i][j]+pf[i-1][j]+pf[i][j-1]-pf[i-1][j-1];
		}
	}
	// for(int i=0;i<=n;i++){
	// 	for(int j=0;j<=n;j++){
	// 		cout << a[i][j] << ", ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
	// for(int i=0;i<=n;i++){
	// 	for(int j=0;j<=n;j++){
	// 		cout << pf[i][j] << ", ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	int q; cin >> q;
	while(q--){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		cout << pf[c][d]-pf[a-1][d]-pf[c][b-1]+pf[a-1][b-1] << endl;
	}
}
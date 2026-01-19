/*
Given array a of N integers. Given Q queries and 
in each query given a number X, print count of that number in array.

Constraints
1 <= N <= 10^5
1 <= a[i] <= 10^7
1 <= Q <= 10^5

*/
#include <bits/stdc++.h>
using namespace std;

// int main(){
	// int n; cin >> n;
	// int a[n];
	// for(int i=0;i<n;i++){
	// 	cin >> a[i];
	// }
	// int q;
	// cin >> q;
	// while(q--){
	// 	int x; cin >> x;
	// 	int ct = 0;
	// 	for(int i=0;i<n;i++){
	// 		if(a[i] == x){
	// 			ct++;
	// 		}
	// 	}
	// 	cout << ct << endl;
	// }

// 	return 0;
// }

// O(N) + O(Q*N) = O(N^2) = 10^10 (won't work in 1 second)
// we use the concept of hashing to precompute !
// limitation is size of array should be <= 10^7, won't work if size 
// is 10^9 or something

const int N = 1e7+10;
int hsh[N]; // all global arrays are declared with all elements = 0

int main(){
	int n; cin >> n;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
		hsh[a[i]]++;
	}
	int q;
	cin >> q;
	while(q--){
		int x; cin >> x;
		
		cout << hsh[x] << endl;
	}
}

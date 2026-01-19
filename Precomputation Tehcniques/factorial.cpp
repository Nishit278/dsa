#include <bits/stdc++.h>
using namespace std;

const int M = 1e9+7;
const int N = 1e5+10;
long long fact[N];

int main(){
	int t; cin >> t;
	fact[0] = fact[1] = 1; 
	for(int i=2;i<=N;i++){ // Here we are computing and storing all the factorial values in advance.
		fact[i] = (fact[i-1]*i) % M;
	}

	while(t--){
		int n; cin >> n;
		cout << fact[n] << endl;
	}
	// for(auto i: fact){
	// 	cout << i << endl;
	// }

	return 0;
}
// Time complexity of simple factorial code = O(T*N) (T is no of test cases)
// Time Complexity of pre computed code = O(T+N) = O(N). 10^5 + 10^5 (will work in 1 second)

/***
 * Here we are creating an array to record the previously computed
 * results like we do in memoization in dynamic programming to prevent
 * the computer from computing redundant values
 ***/
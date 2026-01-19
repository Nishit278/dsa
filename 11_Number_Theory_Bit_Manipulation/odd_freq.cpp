#include <bits/stdc++.h>
using namespace std;

/***
 * Given array a of integers. All integers are present 
 * in event count except one. 
 * Find that one integer which has odd count in O(N) 
 * time complexity and O(1) space complexity
**/

int main(){
	int n; cin >> n;
	vector<int>v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	int ans = 0;
	for( auto i: v){
		ans ^= i;
	}
	cout << ans << endl;

}

// XOR 
// xor of 2 same numbers is 0! -> x^x = 0
// x ^ 0 = x
// x ^ (y ^ z) = x ^ y ^ z = x ^ z ^ y

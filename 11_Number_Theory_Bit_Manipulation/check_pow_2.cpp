#include <bits/stdc++.h>
using namespace std;


void printBinary(int a){
	int bits = 10;
	for(int i=bits; i>=0;i--){
		cout << ((a >> i) & 1 );
	}
	cout << endl;
}

int main(){
	int n; cin >> n;
	if (!(n & (n-1))) cout << "Power of 2 !" <<endl;
	else cout << "Not a pow of 2!";

	return 0;
}

// why does this work ? 
// a power of 2 number looks like 0100 001000 010000 0100000
// the number before the power of 2 is like 0011 000111 001111 0011111
// taking their AND will result in 0 !
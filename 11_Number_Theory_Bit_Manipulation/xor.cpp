#include <bits/stdc++.h>
using namespace std;


void printBinary(int a){
	int bits = 10;
	for(int i=bits; i>=0;i--){
		cout << ((a >> i) & 1 );
	}
	cout << endl;
}
void swap(int &a, int &b){
	a = (a^b);
	b = (b^a); // b = b^(b^a) ==> 0^a = a 
	a = (a^b); // a = (a^b)^a ==> a^a^b = 0^b = b
}

int main(){
	int a,b;
	cin >> a>>b;
	cout << a << ", " << b <<endl;	
	swap(a,b);
	cout << a << ", " << b <<endl;	
}

// XOR 
// xor of 2 same numbers is 0! -> x^x = 0
// x ^ 0 = x
// x ^ (y ^ z) = x ^ y ^ z = x ^ z ^ y

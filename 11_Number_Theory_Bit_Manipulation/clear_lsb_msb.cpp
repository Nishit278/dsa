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
	int a; cin >> a;
	int i; cin >> i;
	printBinary(a);
	int res = (a & ~((1<<i)-1));
	int res1 = (a & ((1<<(i+1))-1));
	printBinary(res);
	printBinary(res1);
	return 0;
}

// what we want to do it, unset all the least significant bits of a number till a position i
// for example binary of 59 is 00000111011 we want to unset the last 4 bits
// we want 00000110000, to do so we need AND with a number like 1111110000
// which is inverse of 0000001111 which is 0000010000 - 1
// suppose we want to unset the 4 lsb of 59 
// then we want to do (59 & ~((1<<4)-1))


//FOR MSB
// eg: binary of 59 is 00000111011 and we want 0000001011 (clear all the bits till the 3rd bit of the numebr)
//					  109876543210
// we need a number like 0000001111 which is 0000010000 -1 
// (59 & (1<<(i+1)-1))
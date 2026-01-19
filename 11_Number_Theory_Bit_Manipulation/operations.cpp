#include <bits/stdc++.h>
using namespace std;

// right shift the number by i
// eg: 9 -> 001001
// let bits = 5 so
// 9 >> 5 = 000000 & 1 = 0 
// 9 >> 4 = 000000 & 1 = 0 
// 9 >> 3 = 000001 & 1 = 1 
// 9 >> 2 = 000010 & 1 = 0 
// 9 >> 1 = 000100 & 1 = 0 
// 9 >> 0 = 001001 & 1 = 1 

void printBinary(int a, int bits){
	int ct = 0;
	for(int i=bits; i>=0;i--){
		cout << ((a >> i) & 1 );
		// another way to calculate set bits
		if(((a >> i) & 1) == 1) ct++;
	}
	cout  << "\n" << ct <<  endl;
}

int main(){
	int a; cin >> a;
	int bits; cin >> bits;
	printBinary(a, bits);
	
	//to check if i-th bit is set bit 
	int i = 3;
	if(a & (1<<i) != 0 ){
		cout << "Set Bit !" << endl;
	} else {
		cout << "Unset bit!"<< endl;
	}

	// to set an i-th bit 
	cout << "Set bits: " << endl;
	i = 4;
	printBinary((a | (1<<i)), bits);
	// to unset an i-th bit 
	cout << "Unset bits: " << endl;
	i = 0;
	printBinary((a & ~(1<<i)), bits);
	// to toggle bits, 1 to 0 and vice versa
	cout << "Toggle bits: " << endl;
	for (i = 4; i<=6;i++){
		printBinary((a^(1<<i)), bits);
	}

	//Bit count 
	int count = 0;
	cout << "No. of set bits" << endl;
	for(int i=31;i>=0;i--){
		if((a & (1 << i)) !=0) count++;
	}
	cout << count << endl;

	// inbuilt function to count set bits
	cout << __builtin_popcount(a) << endl; // only works with integers
	cout << __builtin_popcountll((1LL << 35)) << endl; // for long


	return 0;
}
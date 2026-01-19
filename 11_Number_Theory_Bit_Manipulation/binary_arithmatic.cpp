#include <bits/stdc++.h>
using namespace std;


void printBinary(int a, int bits){
	for(int i=bits; i>=0;i--){
		cout << ((a >> i) & 1 );
	}
	cout << endl;
}

int main(){
	for(int i=0;i<9;i++){
		printBinary(i, 10);
		if(i&1){
			cout << "Odd\n";
		} else {
			cout << "Even\n";
		}
	}

	// division and multiplication 
	// division of integers not real numbers, answer will be the floor if the ans is a real number 


	int n= 5;
	cout << (n>>1) << endl;
	cout << (n<<2) << endl;
	//convert to upper and lower case using bit manipulation
	for (char c = 'A'; c<='E'; c++){
		cout << c << endl;
		printBinary(c,10);
	}
	for (char c = 'a'; c<='e'; c++){
		cout << c << endl;
		printBinary(c,10);
	}

	char x = 'A';
	char y = (x | (1<<5));
	cout << y <<endl;
	cout << "'"<< char(1<<5) << "'" <<  endl; // prints a blank space 
	// we deduce that (1<<5) is binary for ' ' (blank space so,
	cout << char(x | ' ') << endl; // prints a

	// now for lower case to upper case 
	// Binary for a - 00001100001, if we AND it with 0000101111 (Binary for '_'(underscore))
	// we will get uppercase of a
	cout << "Binary for '_' is: " ;
	printBinary(int('_'), 10);
	char m = 'a';
	char p = char(m & ~(1<<5));
	char o = char(m & '_') ;
	cout << p << ", " << o << endl;

	return 0;
}
// least significant bit of even numbers is 0
// lsb of odd nos. is 1


// Difference between the binary representation of 'A' and 'a'
// is the 5th bit, in uppercase 5th bit is unset and in lower case 5th bit is set
// so we just need the change the 5th bit in order to convert
// up to low - char(a|' '); where a is an uppercase alphabet
// low to up - char(a & '_'); where a is a lowercase alphabet



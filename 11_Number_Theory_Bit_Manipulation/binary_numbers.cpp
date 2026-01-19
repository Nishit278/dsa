#include <bits/stdc++.h>
using namespace std;

int main(){
	cout << INT_MAX << endl; // 2147483647
	int a = (1LL<<31)-1 ;
	cout << a << endl; // 2147483647
	unsigned int b = (1LL<<32)-1 ;
	cout << b << endl; // 4294967295



	return 0;
}

// Last bit of all odd numbers is 1 
// 1 << n = 2^n
// normal int can store only a 31 bit number because 1 bit is reserved for sign bit (-ve or +ve)
// and the value of (1LL<<31)-1 is same as INT_MAX 
// we use LL there to explicity tell that 1 is a long long number 

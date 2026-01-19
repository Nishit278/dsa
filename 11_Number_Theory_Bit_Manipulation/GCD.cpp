#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	if(b == 0) return a; // or if(a%b == 0) return b;
	return gcd(b,a%b);
}
int lcm(int a, int b){
	return (a*b)/gcd(a,b);
}
// Time Complexity = O(log(N)) worst case 
int main(){
	int a,b;
	cin >> a >> b;
	cout << gcd(a,b) << endl;
	cout << gcd(18, 4) << endl; // order of number doesn't matter
	cout << gcd(18, 12) << endl;
	cout << lcm(12,18) << endl;

	return 0;
}
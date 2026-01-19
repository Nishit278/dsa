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
	return 0;

}
// least significant bit of even numbers is 0
// lsb of odd nos. is 1

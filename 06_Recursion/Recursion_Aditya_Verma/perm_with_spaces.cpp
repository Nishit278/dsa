#include <bits/stdc++.h>
using namespace std;

vector<string> permutations;

void generate(string s, string &op, int n){
	if(n > s.size()-1){
		permutations.push_back(op);
		return;
	}
	string op1 = op + " " + s[n];
	string op2 = op + s[n];
	generate(s, op1, n+1);
	op.pop_back();
	generate(s, op2, n+1);
	

}

int main(){
	string s;
	getline(cin, s);
	string op = "";
	op.push_back(s[0]);
	s.erase(s.begin()+0);
	generate(s, op, 0);
	for(auto i: permutations){
		cout << i <<endl;
	}
	cout << permutations.size() << endl;

	return 0;
}

//results = 2^n-1 where n is the length of the string
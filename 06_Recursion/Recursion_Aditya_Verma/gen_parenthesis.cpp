/***
	Given n pairs of parentheses, write a function to generate all combinations 
	of well-formed parentheses.

	Example 1:
	Input: n = 3
	Output: ["((()))","(()())","(())()","()(())","()()()"]

	Example 2:

	Input: n = 1
	Output: ["()"]
***/

#include <bits/stdc++.h>
using namespace std;

vector<string> ans;
/***
 * we are using string by reference because each time we call the 
 * generate function a copy of string s is created which further 
 * takes a time complexity of O(N) which we wanna avoid.
 ***/
void generate(string &s, int open, int close){
	if(open == 0 and close == 0){
		ans.push_back(s);
	}
	if(open > 0){
		s.push_back('(');
		generate(s, open-1, close);
		s.pop_back(); // backtracking 
	}

	if(close > 0 && close > open){
		s.push_back(')');
		generate(s, open, close-1);
		s.pop_back(); // backtracking
	}
}
/***
 * In many cases both the if statements are correct open > 0 and close > 0
 * and close > open, so, 2 recursive calls will happen, so we need to reset the result
 * from the first recursive call before making the other call 
 * that's why we pop_back before second recursive call 
 * this step is called Backtracking !
 ***/


int main(){
	string s = "";
	int n;
	cin >> n;
	generate(s,n,n);
	for(auto i: ans){
		cout << i << " ";
	}
	cout << endl;
	return 0;
}

// we keep making changes while following the chain of recursive calls
// while reseting or undoing those changes while coming back
// this is the concept behind recursion

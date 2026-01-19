#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b; i++)

vector<vector<int>> t;
vector<vector<int>> t1;

bool isPalindrome(string &s, int i , int j){
  if(i>=j) return 1;
  if(t1[i][j]!=-1) return t1[i][j];
  if(s[i]==s[j]) return t[i][j] = isPalindrome(s, i+1, j-1);
  return t[i][j] = 0;

}

int dp(string s, int i, int j){
	if(i>=j) return t[i][j] = 0;
	if(t[i][j]!=-1) return t[i][j];
	if(isPalindrome(s,i,j)) return t[i][j] = 0;
	int mn = INT_MAX;
	rep(k,i,j){
		if(isPalindrome(s,i,k)){
			mn = min(mn, 1 + dp(s,k+1,j));
		}
	}
	return  t[i][j] = mn;
}

int main(){
	string s; cin >> s;
	t.resize(s.size(), vector<int> (s.size(), -1));
	t1.resize(s.size(), vector<int> (s.size(), -1));
	cout << dp(s,0,s.size()-1);
}
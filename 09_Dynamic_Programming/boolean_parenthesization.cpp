#include <bits/stdc++.h>
using namespace std;

//Brute force
int solve2(string s, int i, int j, bool isTrue){
	if(i>j) return 1;
	if(i==j){
		if(isTrue) return s[i]=='T';
		else return s[i] == 'F';
	}
	int ans =0;
	for(int k=i+1; k<j; k+=2){
		// temporary answers
		int lt = solve2(s, i, k-1, true);
		int lf = solve2(s, i, k-1, false);
		int rt = solve2(s, k+1, j, true);
		int rf = solve2(s, k+1, j, false);
		if(s[k]=='&'){
			if(isTrue)
				ans += lt*rt;
			else 
				ans += lt*rf + lf*rt + lf*rf; 
		}
		if(s[k]=='|'){
			if(isTrue)
				ans += lt*rt + lf*rt + lt*rf;
			else 
				ans += lf*rf; 
		}
		if(s[k]=='^'){
			if(isTrue)
				ans += lt*rf + lf*rt;
			else 
				ans += lt*rt + lf*rf; 
		}
	}
	return ans;
}

//using memoization 
unordered_map<string, long long int> mp; // or a 3D dp
int dp[205][205][2];

int solve(string s, int i, int j, bool isTrue){
	if(i>j) return 0;
	if(i==j){
		if(isTrue) return s[i]=='T';
		else return s[i] == 'F';
	}
	string temp = to_string(i)+" "+to_string(j)+" "+to_string(isTrue);
	if(mp.find(temp)!=mp.end()){
		return mp[temp];
	}
	int ans =0;
	for(int k=i+1; k<j; k+=2){
		// temporary answers
		int lt = solve(s, i, k-1, true);
		int lf = solve(s, i, k-1, false);
		int rt = solve(s, k+1, j, true);
		int rf = solve(s, k+1, j, false);
		if(s[k]=='&'){
			if(isTrue)
				ans += lt*rt;
			else 
				ans += lt*rf + lf*rt + lf*rf; 
		}
		if(s[k]=='|'){
			if(isTrue)
				ans += lt*rt + lf*rt + lt*rf;
			else 
				ans += lf*rf; 
		}
		if(s[k]=='^'){
			if(isTrue)
				ans += lt*rf + lf*rt;
			else 
				ans += lt*rt + lf*rf; 
		}
	}
	return mp[temp] = ans%1003; // for large numbers
}
int main(){
	mp.clear();
	string s; cin >> s;
	cout << solve(s, 0, s.length()-1, true) << endl;
	cout << solve2(s, 0, s.length()-1, true) << endl;
}
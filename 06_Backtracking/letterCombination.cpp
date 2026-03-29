#include <bits/stdc++.h>
using namespace std;

vector<string> alpha = {"","", "abc", "def", "ghi", "jkl", "mno", "pqrs","tuv", "wxyz" };
    
    void solve(vector<string> &ans, string digits, int start, string op){
        if(start == digits.size()){
            ans.push_back(op);
            return;
        }
        string str = (alpha[digits[start] -'0']);
        for(auto i: str){
            solve(ans, digits, start+1, op+i);
        }

        return;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) return {};
        vector<string> ans;
        string op = "";
        int start = 0;
        solve(ans, digits, start, op);
        return ans;
    }
    int main(){
        string digits = "23";
        vector<string> res = letterCombinations(digits);
        for(auto i: res){
            cout << i << ", ";
        }
        cout << endl;
    }
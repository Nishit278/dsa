#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

string sol2(string s){
    int n = s.length();	
    int best_l = 0;
    string best_s = "";    
    for(int mid =0;mid<n;mid++){
        for(int x=0;mid-x>=0 and mid+x<n; x++){
            if(s[mid-x]!=s[mid+x]) break;
            int len = 2*x+1;
            if(len > best_l){
                best_l = len;
                best_s = s.substr(mid-x, len);
            }
        }
    }
    for(int mid =0;mid<n-1;mid++){
        for(int x=0;mid-x+1>=0 and mid+x<n; x++){
            if(s[mid-x+1]!=s[mid+x]) break;
            int len = 2*x;
            if(len > best_l){
                best_l = len;
                best_s = s.substr(mid-x+1, len);
            }
        }
    }
    return best_s;
}

string solve(string s){
	int n = s.length();
	int start=0, end=1;
	if(n==0) return "";
	bool dp[n][n];
	memset(dp,0, sizeof(dp));
	rep(i,0,n){
		dp[i][i]=1;
	}
	rep(i,0,n-1){
		if(s[i]==s[i+1]){
			dp[i][i+1]=1;
			start = i; end =2;
		}
	}

	rep(j,2,n){
		rep(i,0,n-j){
			if(s[i]==s[i+j] and dp[i+1][i+j-1]){
				dp[i][i+j]=1;
				start=i;
				end=j+1;
			}
		}
	}
	rep(i,0,n){
		rep(j,0,n){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	return s.substr(start,end);
}
int main(){
	
	string s;
	cin >> s;
	cout << solve(s) << endl;
	cout << sol2(s) << endl;
	
}
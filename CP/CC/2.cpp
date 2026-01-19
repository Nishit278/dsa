#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
#define ll long long 
#define pb push_back
#define mp make_pair
#define s second
#define f first


int main(){
	int t; cin >> t;
	while(t--){
		int x, y; cin >> x >> y;
		cout << y % (x+1) << endl;
	}
	return 0;
}
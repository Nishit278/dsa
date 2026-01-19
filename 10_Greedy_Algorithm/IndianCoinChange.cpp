#include <bits/stdc++.h>
using namespace std;

int solve(int *a, int amt, int n){
	
	int ans = 0;
	while(amt>0){
		int start = upper_bound(a,a+n,amt)-1-a; //upper_bound(a,a+n,amt)-1 gives the address and then we subtract a from it
		// cout << a[start] << "+";
		amt = amt - a[start];
		ans++;
	}
	cout << endl;
	return ans;

}
int main(){
	int a[] = {1,2,5,10,20,50,100,200,500,2000};
	int amt; cin >> amt;
	int n = sizeof(a)/sizeof(int);
	cout << solve(a, amt, n);
}
#include <bits/stdc++.h>
using namespace std;

double eps = 1e-9;

double multiply(double mid, int n){
	double ans = 1;
	for(int i=0;i<n;i++){
		ans*=mid;
	}
	return ans;
}
//this is the code for square root
int main(){
	double x; cin >> x;
	int n; cin >> n;
	double lo = 1, hi = x, mid;
	while(hi-lo > eps){
		mid = (hi+lo)/2;
		if(multiply(mid,n) < x){
			lo = mid;
		}else {
			hi = mid;
		}
	}
	cout << setprecision(10) << lo << endl;
	cout << setprecision(10) << hi << endl;

	return 0;
}
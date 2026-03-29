#include <bits/stdc++.h>
using namespace std;

int sum(vector<int>v, int n){
	if(n < 0) return 0;
	return sum(v, n-1) + v[n]; 
}

int main(){
	int n; cin >> n;
	vector<int> v(n);
	for(int i =0;i<n;i++){
		cin >> v[i];
	}
	cout << sum(v, n-1);

}
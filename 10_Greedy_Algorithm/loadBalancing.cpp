#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, val, diff;
	int a[90000];
	while(1){
		cin >> n;
		int max_load = 0, load=0;
		if(n==-1) break;
		for(int i=0;i<n;i++){
			cin >> a[i];
			load+=a[i];
		}
		// finding load to be divided
		if(load%n != 0){
			cout << -1 << endl;
			continue;
		}
		load=load/n;
		diff = 0;
		for(int i=0;i<n;i++){
			diff += (a[i]-load);
			int ans = max(diff, -diff);
			max_load = max(max_load, ans);
		}
		cout << max_load << endl; 

	}
}
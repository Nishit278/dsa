#include <bits/stdc++.h>
using namespace std;

int main(){
	int t,n,x,y; cin>> t;
	while(t--){
		cin >> n;
		vector<pair<int,int>> time;
		for(int i=0;i<n;i++){
			cin >> x >> y;
			time.push_back({x, y});

		}
		
		sort(time.begin(), time.end(), [&](pair<int,int> a, pair<int,int>b){
			return (a.second < b.second);
		});
		int count = 1;
		int fin = time[0].second;
		
		for(int i=1;i<n;i++){
			if(time[i].first >= fin){
				fin = time[i].second;
				count++;
			}
		}
		time.clear();
		
		cout << count << endl;
	}
}
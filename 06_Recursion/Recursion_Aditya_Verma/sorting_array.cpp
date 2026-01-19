#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &v, int curr){
	if(v.size()==0 or curr >= v[v.size()-1]){
		v.push_back(curr);
		return;
	}
	int temp = v[v.size()-1];
	v.pop_back();
	insert(v, curr);
	v.push_back(temp);
}
void r_sort(vector<int> &v){ //O(N^2)
	if(v.size()==1){
		return;
	}
	int temp = v[v.size()-1];
	v.pop_back();
	r_sort(v);
	insert(v,temp); //O(N)
	// v.push_back(temp);
}

int main(){
	int n; cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	r_sort(v);
	for(auto i: v){
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int parent[N];
int rnk[N];


void makeSet(int n){
	for(int i=0;i<=n;i++){
		parent[i] = i;
		rnk[i]=0;
	}
}

int findPar(int node){
	if(node == parent[node])
		return node;
	return parent[node] = findPar(parent[node]); // path compression
}

void Union(int u, int v){
	u = findPar(u);
	v = findPar(v);
	if(rnk[u]<rnk[v]){
		parent[u] = v;
	} else if(rnk[v] < rnk[u]){
		parent[v] = u;
	} else {
		parent[u] = v;
		rnk[u]++;
	}
}

int main(){
	int n, k; 
	cin >> n >> k;
	makeSet(n);
	while(k--){
		int u, v;
		cin >> u >> v;
		Union(u,v);	
	}	
	int conn_comp = 0;
	for(int i=0;i<n;i++){
		if(findPar(i) == i) conn_comp++;
	}
	cout << conn_comp << endl;
}
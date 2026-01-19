#include <bits/stdc++.h>
using namespace std;

const int N = 10e5+2;

vector<int> g[N];
bool visited[N];

// void dfs(int vertex){
// 	// take action on vertex after entering the vertex
// 	for(int child: g[vertex]){
// 		//take action on child before entering the child node
// 		visited[child]=1;
// 		dfs(child);
// 		//take action on child after exiting child node 
// 	}
// 	//take action on vertex before exiting the vertex
// }
void dfs(int vertex){
	visited[vertex]=1;
	cout << vertex  << " ";
	// cout << vertex << endl;
	for(int child: g[vertex]){
		// cout << " par: " << vertex << " child: " << child << endl;
		if(visited[child]) continue;
		dfs(child);
		// visited[child]=0;
	}
	// cout << vertex << " ";
}

int main(){
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int v1, v2;
		cin >> v1 >> v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}	
	for(int i = 1;i<=n;i++){
		cout << i << "-> ";
		for(auto j : g[i]){
			cout << j << " ";
		}
		cout << endl;
	}
	dfs(1);
}

// 6 9 
// 1 3
// 1 5
// 3 5
// 3 4
// 3 6
// 3 2
// 2 6
// 4 6
// 5 6

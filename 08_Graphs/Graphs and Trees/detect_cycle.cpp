// Program to detect cycle in a graph.

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
bool vis[N]; // visited array 
vector<int> g[N]; //array of vectors


bool dfs(int vertex, int par){
	vis[vertex]=1;
	bool isLoopExists = false;
	// cout << vertex  << " ";
	for(int child: g[vertex]){
		// cout << " par: " << vertex << " child: " << child << endl;
		if(vis[child] and child==par) continue; // if child of the current vertex is parent then do nothing
		if(vis[child]) return true; //otherwise there is a loop in the graph
		isLoopExists |= dfs(child, vertex); // if 1 child says there is a loop and other says no loop, then consider loop, that is why we use or
		// isLoopExists is always false but dfs can return true, so we take or of true and false
	}
	return isLoopExists;

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
	bool isLoopExists = false;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(dfs(i, 0)){
				isLoopExists = true;
				break;
			}
		}
	}
	cout << isLoopExists << endl;
}
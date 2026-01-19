#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<int> adj[], int src, int parent, vector<bool> &vis){
	queue<pair<int,int>> q;
	q.push({src, parent});
	vis[src] = true;
	while(!q.empty()){
		pair<int,int> u = q.front();
		q.pop();
		if(!vis[u.first]) vis[u.first] = true;
		for(int nbr: adj[u.first]){
			if(!vis[nbr]){
				vis[nbr];
				q.push({nbr, u.first});
			} else if(nbr != u.second){
				return true;
			}
		}
	}
	return false;
}


// bool dfs(vector<int> adj[], int src, int parent, vector<bool> &vis){
// 	vis[src] = true;
// 	for(auto nbr: adj[src]){
// 		if(!vis[nbr]){
// 			if(dfs(adj, nbr, src, vis)) return true;
// 		} else if(nbr != parent) return true;
// 	}
// 	// If nbr == parent that means we continue searching
// 	return false;
// }

// bool hasCycle(vector<int> adj[], int V){
// 	vector<bool> vis(V+1, 0);
// 	for(int i=1;i<=V;i++){
// 		if(dfs(adj, i, -1, vis))
// 			return true;
// 	}
// 	return false;
// }
bool hcycle_bfs(vector<int> adj[], int V){
	vector<bool> visited(V+1, 0);
	for(int i=1;i<=V;i++){
		if(bfs(adj, i, -1, visited)) return true;
	}
	return false;
}
int main(){

	int n, m; cin >> n >> m;
	vector<int> adj[n+1];

	for(int i=0;i<m;i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	// DFS
	// cout << hasCycle(adj, n) << endl;
	// BFS
	cout << hcycle_bfs(adj, n) << endl;
}
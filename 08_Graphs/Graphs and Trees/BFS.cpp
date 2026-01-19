// BFS is done using queue and a visited array 

#include <bits/stdc++.h>
using namespace std;

const int N = 10e5+2;

vector<int> g[N];
int visited[N];
int level[N];

void bfs(int src){
	queue<int> q;
	q.push(src);
	visited[src]=1;
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		cout << curr << " ";
		for(int child: g[curr]){
			if(!visited[child]){
				q.push(child);
				visited[child]=1;
				level[child]=level[curr]+1;
			}
		}
	}
}
// void dfs(int vertex){
	
// }

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

	bfs(1);
}
// Time Complexity - O(V+2E) = O(v+E)
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

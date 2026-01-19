#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> g[], int i, bool *visited, vector<int> &stack){
	visited[i] = true;

	for(auto nbr:  g[i]){
		if(!visited[nbr]){
			dfs(g,nbr,visited,stack);
		}
	}
	stack.push_back(i);
}

void dfs2(vector<int> g[], int i, bool *visited){
	visited[i] = true;
	cout << i << " ";
	for(auto nbr:  g[i]){
		if(!visited[nbr]){
			dfs2(g,nbr,visited);
		}
	}
	
}

void solve(vector<int> g[], vector<int> rg[], int n){
	bool visited[n];
	memset(visited, 0 ,n);
	vector<int> stack;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			dfs(g, i, visited, stack);
		}
	}
	memset(visited, 0, n);
	char component = 'A';

	for(int x = stack.size()-1; x>=0; x--){
		int node = stack[x];
		if(!visited[node]){
			cout << "Component " << component << "-->" ;
			dfs2(rg, node, visited);
			cout << endl;
			component++;
		}
	}

}

int main(){
	int N;
	cin >> N;
	vector<int> graph[N];
	vector<int> rev_graph[N];

	int m;
	cin >> m;

	while(m--){
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		rev_graph[y].push_back(x);
	}
	solve(graph, rev_graph, N);

}
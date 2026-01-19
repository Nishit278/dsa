#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
void addEdge(int x, int y){
	graph[x].push_back(y);
}

int dfs(vector<int> g[], int s, int d, vector<bool> vis){
	if(s==d) return 1;
	vis[s] = true;
	int ans = 0;
	for(int nbr: graph[s]){
		if(!vis[nbr])
			ans += dfs(g, nbr, d, vis);
	}
	vis[s] = false;
	return ans;
}

int main(){
	int n, s, d;
	cin >> n >> s >> d;
	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		addEdge(x,y);
	}
	vector<bool> vis(n, false);
	cout << dfs(graph, s, d, vis);

}
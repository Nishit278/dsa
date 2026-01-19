// Program to count connected components in a forest.

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
bool vis[N]; // visited array 
vector<int> g[N]; //array of vectors

vector<vector<int>> cc;
vector<int> current_cc;

void dfs(int vertex){
	current_cc.push_back(vertex);

	vis[vertex]=1;
	// cout << vertex  << " ";
	for(int child: g[vertex]){
		// cout << " par: " << vertex << " child: " << child << endl;
		if(vis[child]) continue;
		dfs(child);

	}

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
	int count = 0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			current_cc.clear();
			dfs(i);
			cc.push_back(current_cc);
			count++;
		}
	}
	for(auto i: cc){
		for(auto j: i){
			cout << j <<" ";
		}
		cout << endl;
	}
	cout << count << endl;
}
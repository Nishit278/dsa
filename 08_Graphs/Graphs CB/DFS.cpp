#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph{
	map <T,list <T> > l;
public:
	vector<int> vis;
	void addEdge(int x, int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void DFS_helper(T src, map<T,bool> &visited){
		cout << src << " ";
		visited[src]=true;
		for(T nbr: l[src]){
			if(!visited[nbr]){
				DFS_helper(nbr, visited);
			}
		}
	}

	void DFS(T src){
		map<T, bool> visited;
		//Mark all nodes as not visited
		for(auto p: l){
			T node = p.first;
			visited[node] = false;
		}
		DFS_helper(src, visited);

	}
};

int main(){
	Graph<int> g;
	
	g.addEdge(0,1);
	g.addEdge(0,3);
	g.addEdge(2,1);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.DFS(0);
	return 0;
}
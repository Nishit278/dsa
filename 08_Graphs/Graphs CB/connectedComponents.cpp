#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph{
	map <T,list <T> > l;
public:
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

	void DFS(){
		map<T, bool> visited;
		//Mark all nodes as not visited
		for(auto p: l){
			T node = p.first;
			visited[node] = false;
		}
		int count = 0;
		for(auto p: l){
			T node = p.first;
			if(!visited[node]){
				cout << "Component: " << count+1 << endl;
				DFS_helper(node, visited);
				cout << endl;
				count++;
			}
		}
		cout << count << endl;		

	}
};

int main(){
	Graph<int> g;
	g.addEdge(0,1);
	g.addEdge(0,3);
	g.addEdge(2,1);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(6,7);
	g.addEdge(7,8);
	g.addEdge(9,10);
	g.addEdge(12,13);

	g.DFS();
	return 0;
}
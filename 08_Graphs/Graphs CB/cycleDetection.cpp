#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph{
	int V;
	vector <int> *g;
public:
	Graph(int V){
		this->V = V;
		g = new vector<int>[V];
	}
	void addEdge(int x, int y){
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	//bfs
	bool isTree(T src){
		vector<bool> visited(V,0);
		vector<int> parent(V);
		for(int i=0;i<V;i++){
			parent[i]=i;
		}
		queue<int> q;
		q.push(src);
		visited[src]=1;
		while(!q.empty()){
			auto node = q.front();
			q.pop();
			for(auto nbr: g[node]){
				if(visited[nbr] and parent[node]!=nbr){
					return false;
				}
				else if(!visited[nbr]){
					visited[nbr] = 1;
					parent[nbr] = node;
					q.push(nbr);
				}
			}
		}
		return true;
	}

	//dfs
	bool cycle_helper(int node, vector<bool> visited, int parent){
		visited[node]=true;
		for(int nbr: g[node]){
			if(!visited[nbr]){
				visited[nbr] = true;
				bool found_cycle = cycle_helper(nbr, visited, node);
				if(found_cycle) return true;
			}
			else if(nbr!=parent){
				return true;
			}
		}
		return false;

	}
	bool has_cycle(T src){
		vector<bool> visited(V,0);
		return cycle_helper(src, visited, -1);
	}
};

int main(){
	Graph<int> g(6);
	// g.addEdge(0,1);
	// g.addEdge(0,3);
	// g.addEdge(2,1);
	// g.addEdge(2,3);
	// g.addEdge(3,4);
	// g.addEdge(4,5);
	g.addEdge(0,1);
	g.addEdge(0,2);
	// g.addEdge(2,3);
	// g.addEdge(3,4);
	// g.addEdge(4,0);

	if(g.isTree(0)){
		cout << "No cycle is present, hence it is a tree."<<endl;
	} else {
		cout << "Cycle is present, hence not a tree." << endl;
	}
	if(g.has_cycle(0)){
		cout << "Yes, graph contains cycle." << endl;
	} else {
		cout << "Graph does not contain cycle." << endl;
	}
	// g.DFS(0);
	return 0;
}
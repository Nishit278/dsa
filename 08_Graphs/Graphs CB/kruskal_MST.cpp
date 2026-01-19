//Cycle Detection in undirected graph using DSU

#include <bits/stdc++.h>
using namespace std;

class DSU{
	int *parent;
	int *rank;

public:
	DSU(int n){
		parent = new int[n];
		rank = new int[n];

		for(int i=0;i<n;i++){
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	//Find function
	int find(int i){
		if(parent[i]==-1){
			return i;
		}
		return parent[i] = find(parent[i]);
	}

	//Unite(union) function
	void unite(int x, int y){
		int s1 = find(x);
		int s2 = find(y);

		if(s1!=s2){
			//union by rank
			if(rank[s1]<rank[s2]){
				parent[s1] = s2;
				rank[s2]+=rank[s1];
			} else {
				parent[s2] = s1;
				rank[s1]+=rank[s2];
			}
		}
	}

};

class Graph{
	vector<vector<int>> edgeList;
	int V;
public:
	Graph(int V){
		this-> V = V;
	}
	void addEdge(int x, int y, int w){
		edgeList.push_back({w,x,y});
	}
	int kruskal(){
		sort(edgeList.begin(), edgeList.end());
		int ans = 0;

		DSU s(V);
		for(auto edge: edgeList){
			int w = edge[0];
			int x = edge[1];
			int y = edge[2];

			if(s.find(x) != s.find(y)){
				s.unite(x,y);
				ans+=w;
			}

		}
		return ans;
	}
};

int main(){
	Graph g(4);
	g.addEdge(0,1,1);
	g.addEdge(1,3,2);
	g.addEdge(3,2,4);
	g.addEdge(2,0,2);
	g.addEdge(0,3,2);
	g.addEdge(1,2,2);
	cout << "Cost of the minimum spanning tree is: " << g.kruskal() << endl;
	return 0;
}
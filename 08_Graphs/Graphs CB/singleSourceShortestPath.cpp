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

	void BFS(T src){
		map<T, int> dist;
		queue<T> q;
		for(auto i: l){
			T node = i.first;
			dist[node] = INT_MAX;
		}
		q.push(src);
		dist[src] = 0;

		while(!q.empty()){
			T node = q.front();
			q.pop();
			for(auto nbr: l[node]){
				if(dist[nbr] == INT_MAX){
					q.push(nbr);
					dist[nbr] = 1 + dist[node];
				}
			}
		}
		for(auto i: l){
			T node = i.first;
			int distance = dist[node];
			cout << "Node " << node << " dist from src is: " << distance << endl;
		}
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
	g.BFS(0);
	return 0;
}
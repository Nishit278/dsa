//Cycle Detection in undirected graph using DSU

#include <bits/stdc++.h>
using namespace std;

class Graph{
	int v;
	vector<pair<int,int>> *l; // {{1,2},{2,3},{3,4}} - edge list
	
	public:
		Graph(int v){
			this->v = v;
			l = new vector<pair<int,int>> [v]; // array of vector of pairs
		}
		int addEdge(int x, int y, int w){
			l[x].push_back(make_pair(y,w));
			l[y].push_back(make_pair(x,w));
		}
		int prim(){
			priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> q;
			bool *vis = new bool[v]{0};
			int ans = 0;

			q.push({0,0});
			while(!q.empty()){
				auto best = q.top();
				q.pop();

				int to = best.second;
				int weight = best.first;

				if(vis[to]){
					continue;
				}
				ans += weight;
				vis[to] = 1;

				//add new edges in queue
				for(auto x: l[to]){
					if(vis[x.first]==0){
						q.push({x.second, x.first});
					}
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
	cout << "Cost of the minimum spanning tree is: " << g.prim() << endl;
	return 0;
}
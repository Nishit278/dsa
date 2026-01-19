//Cycle Detection in undirected graph using DSU

#include <bits/stdc++.h>
using namespace std;

class Graph{
	int v;
	list<pair<int,int>> l; // {{1,2},{2,3},{3,4}} - edge list
	
	public:
		Graph(int v){
			this->v = v;
		}
		int addEdge(int u, int v){
			l.push_back(make_pair(u,v));
			return 0;
		}

		int findSet(int i, vector<int> &parent){
			if(parent[i] == -1){
				// parent[i] = i;
				return i;
			}
			if(parent[i]!=-1) return parent[i];
			return parent[i] = findSet(parent[i], parent);
		}
		void unionSet(int x, int y, vector<int> &parent, vector<int>& rank){
			int s1 = findSet(x, parent);
			int s2 = findSet(y, parent);
			if(s1!=s2){
				if(rank[s1]<rank[s2]){
					parent[s1]= s2;
					rank[s2]+=rank[s1];
				} else {
					parent[s2] = s1;
					rank[s1]+=rank[s2];
				}
			}
		}

		bool contains_cycle(){ //DSU Logic to check - find 2 nodes belonging to the same set
			vector<int> parent(v+1,-1);
			vector<int> rank(v+1, 1);
			// iterate ove edge list
			/**
			 * parent[] = [-1,-1,-1,-1,-1]
			 * Itr 1: (1,2) 1 becomes the parent of 2 - parent[] = [-1,-1,1,-1,-1]
			 * Itr 2: (2,3) 1 becomes the parent of 3 - parent[] = [-1,-1,1,1,-1]
			 * Itr 3: (3,4) 1 becomes the parent of 4 - parent[] = [-1,-1,1,1,1]
			 * Itr 4: (4,1) parent[4] = 1 parent[1] = 1 hence there is a loop
			**/
			for(auto edge: l){
				int i = edge.first;
				int j = edge.second;

				int s1 = findSet(i, parent);
				int s2 = findSet(j, parent);

				if(s1!=s2){
					unionSet(s1,s2,parent, rank);
				} else {
					for(auto i: parent){
						cout << i << ", ";
					}
					cout << endl;
					for(auto i: rank){
						cout << i << ", ";
					}
					cout << endl;
					cout << "Cycle detected!" << endl;
					return true;
				}
			}
			for(auto i: parent){
				cout << i << ", ";
			}
			cout << endl;
			return false;
		}

};

int main(){
	Graph g(4);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,1);
	cout << g.contains_cycle() << endl;
	return 0;
}
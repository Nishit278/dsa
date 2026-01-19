#include <bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	unordered_map<string, list<pair<string,int>>> g;
	
public:
	void addEdge(string x, string y, bool bidr, int wt){
		g[x].push_back(make_pair(y,wt));
		if(bidr){
			g[y].push_back({x,wt});
		}
	}
	void print(){
		for(auto s: g){
			string city = s.first;
			cout << city << "->";
			list<pair<string,int>> nbrs = s.second;
			for(auto nbr: nbrs){
				string dest = nbr.first;
				int dist = nbr.second;
				cout << dest << " " << dist <<", ";

			}
			cout << endl;
		}
	}
};

int main(){
	Graph g;
	g.addEdge("A", "B", true, 20);
	g.addEdge("B", "D", true, 30);
	g.addEdge("A", "C", true, 50);
	g.addEdge("C", "D", true, 20);
	g.addEdge("A", "D", false, 40);


	g.print();
}
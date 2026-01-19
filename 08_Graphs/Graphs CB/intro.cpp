#include <bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list <int> *l; // we could have used list<int> l[V]; to create array of lists but V is not know on compile time but only on runtime
	// so we make a pointer to l and create it dynamically 
public:
	Graph(int V){
		this->V = V;
		l = new list<int>[V]; // array of V lists
	}
	void addEdge(int x, int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void print(){
		for(int i=0;i<V;i++){
			cout << i << " -> ";
			for(int x:l[i]){
				cout << x << ", ";
			}
			cout << endl;
		}
	}
};

int main(){
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.print();
}
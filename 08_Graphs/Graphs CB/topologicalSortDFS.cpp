#include <bits/stdc++.h>
using namespace std;

template <typename T>
/***
 * Templates act like template for class
 * just like class act like template for object
 * suppose I need the class Graph for int, string and char
 * I would have to make 3 different classes 
 * but using templates 
 * we make 1 class
 * and pass data type for that class while creating the object
***/

class Graph{
	unordered_map <T,list <T> > l;
public:
	unordered_map<T,list <T>> get(){
		return l;
	}
	void addEdge(T x, T y){
		l[x].push_back(y);
		
	}
	void DFS_helper(T src, map<T,bool> &visited, list<T> &ordering){
		// cout << src << " ";
		visited[src]=true;
		for(T nbr: l[src]){
			if(!visited[nbr]){
				DFS_helper(nbr, visited, ordering);
			}
		}
		ordering.push_front(src);
		return;
	}

	// just a bit different from connected components
	void DFS(){
		map<T, bool> visited;
		list<T> ordering;
		//Mark all nodes as not visited
		for(auto p: l){
			T node = p.first;
			visited[node] = false;
		}

		for(auto p: l){
			T node = p.first;
			// cout << node << " ";
			if(!visited[node]){
				DFS_helper(node, visited, ordering);
			}
		}
		cout << endl;
		for(auto node: ordering){
			cout << node << ", " << endl;
		}

	}
};

int main(){
	Graph<int> g1;
	Graph<string>g;
	g.addEdge("Python", "DataProcessing");
	g.addEdge("Python", "PyTorch");
	g.addEdge("Python", "ML");
	g.addEdge("DataProcessing", "ML");
	g.addEdge("PyTorch", "DL");
	g.addEdge("ML", "DL");
	g.addEdge("DL", "FaceRecognition");
	g.addEdge("DataSet", "FaceRecognition");

	g1.addEdge(5,0);
	g1.addEdge(4,1);
	g1.addEdge(3,1);
	g1.addEdge(5,2);
	g1.addEdge(2,3);
	g1.addEdge(4,0);
	
	auto l = g1.get();
	for(auto i: l){
		cout << i.first << ": ";
		for(auto j: l[i.first]){
			cout << j << ", ";
		}
		cout << endl;
	}

	g.DFS();
	g1.DFS();
	return 0;
}
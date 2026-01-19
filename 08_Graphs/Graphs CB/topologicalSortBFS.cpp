#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

template <typename T>
class Graph{
	map<T, list<T>> l;
	int e;
public:
	Graph(int e){
		this -> e = e;
	}
	void addEdge(T x, T y){
		l[x].push_back(y);
	}
	void topologicalSort(){
		vector<int> indegree(e,0);
		for(auto i: l){
			for(auto j: l[i.first]){
				indegree[j]++;
			}
		}

		// bfs
		queue<int> q;
		// pushing the nodes to q where indegree is 0, independent nodes
		for(int i=0;i<e;i++){
			if(indegree[i]==0)
				q.push(i);
		}
		while(!q.empty()){
			int node = q.front();
			// cout << node << endl;
			ans.push_back(node);
			q.pop();
			for(auto nbr : l[node]){
				// reducing the indegree of all the neighbours of the popped node
				indegree[nbr]--;
				if(indegree[nbr]==0){
					q.push(nbr);
				}
			}
		}
	}
};

int main(){
	Graph<int> g1(6);
	g1.addEdge(5,0);
	g1.addEdge(4,1);
	g1.addEdge(3,1);
	g1.addEdge(5,2);
	g1.addEdge(2,3);
	g1.addEdge(4,0);
	g1.topologicalSort();
	for(auto i: ans){
		cout << i << ", ";
	}

	return 0;
}
// Representation of graphs and trees
/***
 * There are 2 ways to represent a graph-
 * 	Adjacency list
 * 	Adjacency Matrix
 ***/

#include <bits/stdc++.h>
using namespace std;


//Adjacency Matrix

const int N = 1e3+10;
int G[N][N];
vector<pair<int,int>> G2[N];

int main(){
	int v,e; cin >> v >> e;
	for(int i=0;i<e;i++){
		int v1, v2, wt; cin >> v1 >> v2 >> wt;
		// Adjacency Matrix
		G[v1][v2] = wt;
		G[v2][v1] = wt;

		// Adjacency List
		G2[v1].push_back({v2, wt});
		G2[v2].push_back({v1, wt});
	}
}
// Adjacency Matrix
// Cons:
// problem with this approach is 
// space complexity is very high 
// requires O(N^2) space complexity
// for N = 10^5 or more 
// we cannot construct a matrix

// Pros:
// walking an adj matrix is O(1)


// Adjacency List
// Pros:
// Space complexity - O(V+E) = O(N)

// Cons:
// walking an adj list is O(N)

//Input
// 6 9
// 1 3
// 1 5
// 3 5
// 3 4
// 3 6
// 3 2
// 2 6
// 4 6
// 5 6

//with weights
// 6 9
// 1 3 4
// 1 5 3 
// 3 5 3 
// 3 4 2
// 3 6 5
// 3 2 1
// 2 6 3 
// 4 6 6
// 5 6 4
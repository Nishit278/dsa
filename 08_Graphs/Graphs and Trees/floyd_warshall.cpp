#include <bits/stdc++.h>
using namespace std;

const int N = 510;
const int INF = 1e9+10;

int dist[N][N]; // main distance array or dp array 


int main(){
	// initializing all values with INF except the left diagonal which is 0 because distance of a node to itself is always 0.
	for(int i=0;i<N;++i){
		for(int j=0;j<N;j++){
			if(i==j) dist[i][j] = 0;
			else dist[i][j] = 20;
		}
	}
	// Graph input
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int x,y, wt;
		cin >> x >> y >> wt;
		dist[x][y] = wt;
	}

	for(int i = 1; i<=n ; ++i){
		for(int j = 1; j<=n ; ++j){
			cout << dist[i][j] << ", ";
		}
		cout << endl;
	}
	cout << endl;

	// working

	for(int k = 1; k<=n ; ++k){ //level
		for(int i = 1; i<=n ; ++i){ // row
			for(int j = 1; j<=n ; ++j){ // col
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}
	// Printing the Adjacency Matrix
	for(int i = 1; i<=n ; ++i){
		for(int j = 1; j<=n ; ++j){
			cout << dist[i][j] << ", ";
		}
		cout << endl;
	}

}
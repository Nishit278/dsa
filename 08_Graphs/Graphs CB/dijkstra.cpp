#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

const int N = 1e5+10;
const int INF = 1e9+10;

vector<pair<int,int>> g[N];


void dijkstra(int src){
	vector<int> vis(N,0); // visited array
	vector<int> dist(N, INF); // distances of all nodes from source node, infinity initially

	set<pair<int,int>> st; // priority queue/set to store (weight, node) pair
	st.insert({0, src}); // inserting source and its weight(0) in the set
	
	dist[src] = 0;
	while(st.size() > 0){ // while set is not empty
		auto min = *st.begin(); // minimum element in pq is the first element
		int v = min.second; // vertex = min.second i.e. the node
		int v_wt = min.first; // weight is the first val in the pair
		st.erase(st.begin()); // remove the pair from the set before working
		
		if(vis[v]==1) continue; // if already visited then continue
		vis[v]=1; // else mark as visited
		
		for(auto child: g[v]){ // explore all the children of the current node
			int child_v = child.first; //vertex in graph is first element
			int wt = child.second; // wt is second in graph(not set)
			if(dist[v] + wt < dist[child_v]){ // check if we can minimized the distance
				dist[child_v] = dist[v] + wt;
				st.insert({dist[child_v], child_v});
			}
		}

	}
	for(int i=1;i<=6;i++){
		cout  << src << "-> "<< i << " = "<< dist[i] << endl;
	}
}

void dijkstra_pq(int src){
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<int> dist(N, INF);

	dist[src] = 0;
	pq.push({0, src});

	while(!pq.empty()){
		int distance = pq.top().first;
		int prev = pq.top().second;
		pq.pop();

		for(auto nbr: g[prev]){
			int next = nbr.first;
			int nextDist = nbr.second;
			if(dist[next] > dist[prev] + nextDist){
				dist[next] = dist[prev]+nextDist;
				pq.push({nextDist, next});
			}
		}
	}
	cout << "The distances from source " << src << " are: " << endl;
	for(int i=1;i<6;i++){
		cout << i << " -> " << dist[i] << endl;
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int x,y, wt;
		cin >> x >> y >> wt;
		g[x].push_back({y,wt});
		g[y].push_back({x,wt});
	}
	// dijkstra(1);
	dijkstra_pq(1);

	return 0;
}
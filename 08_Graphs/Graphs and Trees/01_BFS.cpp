#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int INF = 1e9+10;
vector<pair<int,int>> g[N];
vector<int> lev(N, INF);
int n, m ;

int bfs(){
	deque<int> q;
	q.push_back(1);
	lev[1] = 0;

	while(!q.empty()){
		int curr = q.front();
		q.pop_front();

		for(auto &child: g[curr]){
			int child_v = child.first;
			int wt = child.second;
			if(lev[curr]+wt < lev[child_v]){
				lev[child_v] = lev[curr]+wt;
				if(wt==1){
					q.push_back(child_v);
				}else{
					q.push_front(child_v);
				}
			}
		}
	}
	return lev[n]==INF ? -1: lev[n];

}

int main(){
		cin >> n >> m;
		for(int i=0;i<m;i++){
			int x,y;
			cin >> x >> y;
			if(x==y) continue;
			g[x].push_back({y,0});
			g[y].push_back({x,1});
		}
		cout << bfs() << endl;

}

/***
 * Given a directed cyclic graph
 * we need to return the min no. of edges which can be reversed 
 * to have a direct path from 1 to N.
 * so basically we gotta return the shortest path from 1 to N 
 * along with the direct edges of wt 0 we make our own edges in 
 * the opposite direction with wt 1
 * so if we go from**/
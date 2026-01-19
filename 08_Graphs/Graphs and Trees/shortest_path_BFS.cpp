// // shortest path in an unweighted graph using BFS.
// // This does not work for a weightest graph

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+10;

vector<vector<int>> vis(8, vector<int> (8,0));
vector<vector<int>> level(8, vector<int> (8,INF));

void reset(){

	fill(vis.begin(), vis.end(), vector<int>(8,0));
	fill(level.begin(), level.end(), vector<int> (8, INF));
}

pair<int, int> coords(string s){
	return {s[0]-'a', s[1]-'1'};
}

vector<pair<int,int>> movements = {
	{-1,2}, {1,2},
	{-1,-2}, {1,-2},
	{2,-1}, {2,1},
	{-2,-1}, {-2,1}
};

bool isValid(int x, int y){
	return (x>=0 and x < 8 and y >=0 and y<8);
}

int bfs(string src, string dest) {
	int srcX = coords(src).first;
	int srcY = coords(src).second;
	int destX = coords(dest).first;
	int destY = coords(dest).second;

	// cout << "Source: " << srcX << " " << srcY << endl;
	// cout << "Destination: " << destX << " " << destY << endl;

	queue<pair<int,int>> q;
	q.push({srcX, srcY});
	vis[srcX][srcY] = 1;
	level[srcX][srcY] = 0;

	while(!q.empty()){
		pair<int,int> p = q.front();
		int x = p.first, y = p.second;
		q.pop();

		for(auto move : movements){
			int childX = move.first + x;
			int childY = move.second + y;
			if(!isValid(childX, childY)) continue;
			if(!vis[childX][childY]){
				// cout << "child: " << childX << " " << childY << endl;
				q.push({childX, childY});
				level[childX][childY] = level[x][y]+1;
				vis[childX][childY] = 1;
			}
			if(level[destX][destY] != INF){
			break;
			}
		}
	} return level[destX][destY];
}

int main (){
	int t; cin >> t;
	while(t--){
		reset();
		string s1, s2;
		cin >> s1 >> s2;
		cout << bfs(s1, s2) << endl;
	}

	return 0;
}


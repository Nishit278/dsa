#include "bits/stdc++.h"
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll


const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=0;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
string stepDir = "URDL";
int prevStep[1000][1000];

void solve(){
	int n, m; cin >> n >> m;
	vector<vector<char>> map(n, vector<char>(m));
	pair<int, int> begin, end;
	rep(i,0,n){
		rep(j,0,m){
			cin >> map[i][j];
			if(map[i][j] == 'A'){
				begin = {i,j};
			}
			else if(map[i][j] == 'B'){
				end = {i,j};
			}
		}
	}
	// BFS on grid - shortest path for unit distance
	vector<vector<int>> vis(n+1, vector<int> (m+1, 0));
	queue<pair<int,int>> q;
	q.push(begin);
	vis[begin.fr][begin.sc] = 1;

	while(!q.empty()){
		pii u = q.front();
		q.pop();
		for(int k=0;k<4;k++){
			pii v = {u.fr+dx[k], u.sc+dy[k]}; // all 4 directions
			if(v.fr < 0 or v.fr >= n or v.sc < 0 or v.sc >= m) continue; // check for out of bounds
			if(map[v.fr][v.sc] == '#') continue; // check for blocked path
			if(vis[v.fr][v.sc]) continue; // check if visited
			// if valid then ...
			vis[v.fr][v.sc] = 1;
			prevStep[v.fr][v.sc] = k;
			q.push(v);
		}
	}

	if(vis[end.fr][end.sc]){ // if destination is visited
		cout << "YES" << endl;
		vector<int> steps;
		while(end!=begin){
			int p = prevStep[end.fr][end.sc];
			// cout << p << " ";
			steps.push_back(p);
			end = {end.fr - dx[p], end.sc - dy[p]}; // backtracking to the path
		}
		// cout << endl;
		reverse(all(steps));
		cout << steps.size() << endl;
		for(char c: steps){
			cout << stepDir[c];
		}
		cout << endl;
	} else {
		cout << "NO" << endl;
	}

}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
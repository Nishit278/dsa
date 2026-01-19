#include <bits/stdc++.h>
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


void print_graph(vector<int> graph[], int n){

	rep(i,0,n+1){
		cout << i <<  " -> ";
		for(auto j: graph[i]){
			cout << j << " ";
		}
		cout << endl;
	}
}
void solve(int test){
	cout << "Case #" << test << ": ";
	int n ,q;
	cin >> n >> q;
	vector<int> g[n+1];
	rep(i,0,n-1){
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	vector<int> queries(q);
	for(auto &i: queries) cin >> i;
	// print_graph(g, n);
	
	vector<vector<int>> res;
	queue<int> qu;
	vector<int> vis(n+1, 0);
	qu.push(1);
	vis[1] = 1;
	while(!qu.empty()){
		int sz = qu.size();
		vector<int> level;
		for(int i=0;i<sz;i++){
			int node = qu.front();
			qu.pop();
			for(auto nbr: g[node]){
				// cout << node << " " << nbr << endl;
				if(!vis[nbr]){

					qu.push(nbr);
					vis[nbr] =1;
				}
			}
				level.push_back(node);
		}
		res.pb(level);
	}
	int cnt = 0;
	for(auto i: res){
		if(q < i.size()){
			break;
		}
		q-=i.size();
		cnt+=i.size();
	}
	cout << cnt << endl;

	
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;
	cin>>t;
	rep(i,1,t+1) solve(i);
	
	return 0;
}
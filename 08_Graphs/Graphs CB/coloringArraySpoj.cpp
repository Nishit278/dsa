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

int parent[3000000];
int size[3000000];

int find(int v){
	if(v == parent[v]) return v;
	return parent[v] = find(parent[v]);
}

int unionn(int a, int b){
	a = find(a);
	b = find(b);
	
	if(size[a] < size[b]){
		parent[a] = b;
	} else if(size[a] > size[b]){
		parent[b] = a;
	} else {
		parent[a] = b;
		size[a]++;
	}
}

void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> l(k+5), r(k+5), c(k+5), res(n+1);
	for(int i=1;i<=n+1;i++){
		parent[i] = i;
		// res[i] = 0;
	}

	for(int i=0;i<k;i++){
		cin >> l[i] >> r[i] >> c[i];
	}
	for(int i = k-1; i>=0; i--){
		int left = find(l[i]);
		while(left <= r[i]){
			res[left] = c[i];
			unionn(left, left+1);
			left = find(left);
		}
	}
	for(int i=1;i<=n;i++){
		cout << res[i] << endl;
	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
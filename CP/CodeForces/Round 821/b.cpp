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

void solve(){
    int n,x,y;
    cin >> n >> x >> y;
    if(x<y) swap(x,y);
    if(x == 0 or y!=0){
        cout << -1 << endl;
        return;
    }
    if((n-1)%x!=0) {
        cout << -1 << endl;
        return;
    }
    for(int i=1;i<=x;i++){
        cout << 1 << " ";
    }
    int left = x + 2;
    int tm = (n-x-1)/x;
    for(int i=1;i<=tm;i++){
        for(int j=1;j<=x;j++) cout << left << " ";
        left+=x;
    }
    cout << endl;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
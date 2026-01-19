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

int check(vector<int> &v,int i) {
    int count=0;
    int p=i;
    while(p!=-1) {
        ++count;
        p=v[p];
        if(p==i) return count;
    }
    return -1;
}
// void solve() {
//     int n; cin>>n;
//     string s; cin>>s;
//     vector<int> ind(26,0), mp(26,0);

//     string op = "";
//     rep(i,0,26) mp[i]=-1,ind[i]=1;
//     rep(i,0,n){
//         if(mp[s[i]-'a']==-1)  {
//             rep(j,0,26) {
//                 if(ind[j]!=0 and j!=s[i]-'a') {
//                     mp[s[i]-'a']=j;
//                     int temp=check(mp,j);

//                     if(temp!=-1 and temp!=26)
//                     continue;
//                     else {
//                         ind[j]=0;
//                         break;
//                     }
//                 }
//             }
//         }
//         op.push_back((mp[s[i]-'a']+'a'));
//     }
//     cout << op <<endl;
// }
vector<int> dp;
int helper(int n){
    if(n<=1) return 0;
    if(dp[n]!=-1) return dp[n];
    int res = INT_MAX;
    res = min(helper(n-1ll), helper(n/2ll), helper(n/3ll));
    return dp[n] = res;
}
void solve(){
    int n; cin >> n;
    dp.resize(n+1, -1);
    int ans = helper(n);
    cout << ans << endl;
    
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
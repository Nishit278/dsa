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
int nums[2000001];

void solve() {
   int n; cin >> n;
   for(int i=1;i<=n;++i) cin >> nums[i];
   for(int i=1;i<=n;++i) {
      int x ; cin >> x;
      nums[i]=x-nums[i];
   }
   rep(i,1,n+1){
      cout << nums[i] << " ";
   }
   cout << endl;
   sort(nums+1,nums+1+n);
   rep(i,1,n+1){
      cout << nums[i] << " ";
   }
   cout << endl;
   int i=n,j=1,s=0;
   for(;;s++,i--,j++) {
      cout << i << " " << j << endl << endl;
      while(j<=n && -nums[i]>nums[j]){
         cout << -nums[i] << " " << nums[j] << endl;
         j++;
      }
      if(j>=i) break;
   }
   cout << s << endl;
}

signed main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);cout.tie(0);
   int t;
   cin>>t;
   while(t--) solve();
   return 0;
}
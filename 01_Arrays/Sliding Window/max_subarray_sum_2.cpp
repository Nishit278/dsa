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
	vector<int> nums = {1,2,3,4,5,5,5,6,7,8,8,9};
	int k = 4;
	multiset<int> s;

	vector<int> ret;

	for(int i = 0; i < k; i++){

		s.insert(nums[i]);

	}

	for(int i = k; i < nums.size(); i++){

		ret.push_back(*s.rbegin()); 
		cout << *s.rbegin() << endl;

		s.erase(s.find(nums[i-k]));

		s.insert(nums[i]);

	}

	ret.push_back(*s.rbegin());

	for(int i: ret)
		cout << i << " ";
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
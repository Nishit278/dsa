#include "bits/stdc++.h"
using namespace std;
#define int long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define sz(x) (int)((x).size())
#define fr first
#define sc second
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll

const long long INF = 1e18;
const int32_t M = 1e8 + 7;
const int32_t MM = 998244353;

const int N = 0;
// Recursion
vector<int> dp;
int catalan(int i)
{
	if (i == 0 or i == 1)
		return 1;
	if (dp[i - 1] != -1)
		return dp[i - 1];
	int ans = 0;
	for (int itr = 0; itr < i; itr++)
	{
		ans += catalan(itr) * catalan(i - itr - 1);
	}
	return dp[i - 1] = ans%M;
}
// Tabulation
int catalan_tab(int n)
{
	vector<int> t(n + 1);
	t[0] = t[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			t[i] += t[j] * t[i - j - 1];
		}
	}
	return t[n]%M;
}
void solve()
{
	int n;
	cin >> n;
	dp.resize(n, -1);
	cout << catalan(n)%M << endl;
	cout << catalan_tab(n)%M << endl;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
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
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;

int solve(vector<int> nums, int k)
{
    int n = nums.size();
    int l = 0, r = 0, res = INT_MIN, curr = 0;

    curr = accumulate(nums.begin(), nums.begin() + k, 0);
    r = k;

    while (r < n)
    {
        curr -= nums[l];
        curr += nums[r];
        cout << curr << " " << res << endl;
        res = max(res, curr);
        r++, l++;
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n = 8;
    vector<int> nums = {1, 2, 3, 51, 6, 7, 43, 9};
    int k = 3;
    int result = solve(nums, k);
    cout << result << endl;
    return 0;
}

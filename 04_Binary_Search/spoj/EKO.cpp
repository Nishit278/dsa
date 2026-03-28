#include <bits/stdc++.h>
#define ll long long int
using namespace std;


bool solve(vector<int> &nums, int height, int m){ // predicate fn
    ll sum = 0;
    for(int i: nums){
        ll diff = i-height;
        if(diff > 0) sum += diff;
    }
    return sum >= m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,m;
    cin >> n >> m;
    vector<int> nums(n, 0);
    for(int i=0;i<n;i++) cin >> nums[i];

    int lo = 0;
    int hi = *max_element(nums.begin(), nums.end());

    while(lo <= hi){
        ll mid = lo + (hi - lo) / 2;
        if(solve(nums, mid, m)){
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }
    cout << hi << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &nums, int sep, int cows){
    int prev_cow = nums[0];
    int cnt = 1;
    for(int i=1;i<nums.size();i++){
        if(abs(nums[i] - prev_cow) >= sep){
            prev_cow = nums[i];
            cnt++;
        }
        if(cnt == cows) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--){
        int n, c;
        cin >> n >> c;
        vector<int> nums(n, 0);
        for(int i=0;i<n;i++) cin >> nums[i];

        sort(nums.begin(), nums.end());

        int lo = nums[0];
        int hi = nums[n-1];

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(solve(nums, mid, c)){
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        cout << hi << endl;
    }
    

    return 0;
}
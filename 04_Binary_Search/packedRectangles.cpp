#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
using namespace std;


// ! To avoid large multiplication? 
/**
 ** We needed (size/w) * (size/h) >= n but long long might overflow
 ** So, (size/w) >= (n)/(size/h);
 ** Integer divsion is floor by default which might yield incorrect answer so 
 ** size/w >= ceil (n/(size/h)) ----> size/w >= (n + (size/h) - 1)/(size/h);
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll w,h,n;
    cin >> w >> h >> n;
 
    ll low = 0, high = max(w,h)*n;
 
    while(low < high){
        ll mid = low + (high-low)/2;
 
        if(floor(mid/h) * floor(mid/w) >= n)
            high = mid;
        else
            low = mid + 1;
    }
 
    cout << low << endl;

}
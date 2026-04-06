#include <bits/stdc++.h>
using namespace std;



// Returns survivor index in 1..n
int josephus(int n, int k)
{
    if (n == 1)
        return 1;
    return (josephus(n - 1, k) + k-1) % n + 1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t, n, k;
    cin >> t;
    while(t--){
        cin >> n >> k; // e.g. 7 3 → 4 (survivor position, 1-indexed)
        cout << josephus(n, k) << "\n";
    }
    return 0;
}


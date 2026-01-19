#include <iostream>
#include <algorithm>
using namespace std;

bool canPlaceCows(vector<int> &stalls, int n, int cows, int min_sep)
{
    int last_cow = stalls[0];
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (abs(stalls[i] - last_cow) >= min_sep)
        {
            last_cow = stalls[i];
            cnt++;
            if (cnt == cows)
                return true;
        }
    }
    return false;
}

void solve()
{
    int n, cows;
    cin >> n >> cows;
    vector<int> stalls(n);
    for (int i = 0; i < n; i++)
    {
        cin >> stalls[i];
    }
    sort(stalls.begin(), stalls.end());
    // for (auto i : stalls)
    // {
    //     cout << i << ", ";
    // }
    cout << endl;
    int s = 0, e = stalls[n - 1] - stalls[0];
    int ans = 0;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        // cout << "seperation: " << mid << endl;
        bool canPlace = canPlaceCows(stalls, n, cows, mid); // mid is the min_seperation
        if (canPlace)
        {
            ans = mid;
            // cout << "ans: " << ans << endl;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
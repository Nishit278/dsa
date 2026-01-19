// since no array is given think of a search space (Monotonic)
// Monotonic function means a function which is non increasing or non decreasing
// min square root of a number can be 1 and could be the number itself
// 1-50, take mid 25, 25^2 > 50, so 25 and all nums after that can't be square root
// this is the monotonic property

#include <bits/stdc++.h>
using namespace std;

void find_root(int n, int p)
{
    int s = 1, e = n;
    double ans = -1;
    while (s <= e)
    {
        int mid = (s + e) >> 1;
        if (double(mid) * double(mid) == double(n))
        {
            ans = mid;
            break;
        }
        else if (mid * mid > n)
            e = mid - 1;
        else
        {
            s = mid + 1;
            ans = mid;
        }
    }
    cout << ans << endl;
    float inc = 0.1;
    for(int times = 1; times <= p;times++){
        while(ans*ans<=n){
            ans = ans + inc;
        }
        ans = ans - inc;
        inc = inc/ 10;
    }
    cout << ans << endl;
}

int main()
{
    int n; cin>>n;
    int p = 2;
    find_root(n, p);
    return 0;

}
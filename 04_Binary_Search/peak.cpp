#include <bits/stdc++.h>
using namespace std;

int find_peak(vector<int> &nums, int n)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (high+low)/2;
        if ((mid == 0 or nums[mid] > nums[mid - 1]) and (mid == n - 1 or nums[mid] > nums[mid + 1]))
        {
            return mid;
        }
        else if (nums[mid] <= nums[mid + 1])
            low = mid + 1;
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
    }
   
    int ans = find_peak(arr, n);
    cout << ans << endl;
}
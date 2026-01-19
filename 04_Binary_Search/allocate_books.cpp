#include <bits/stdc++.h>
using namespace std;

bool isValid(int nums[], int n, int c, int maxPages)
{
    int student = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (sum > maxPages)
        {
            student++;
            sum = nums[i];
        }
    }
    if (student > c)
    {
        return false;
    }
    return true;
}

int findPages(int *nums, int n, int c)
{
    if (c > n)
        return -1;
    int e = 0, s = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        e += nums[i];
        s = max(s, nums[i]);
    }
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (isValid(nums, n, c, mid))
        {
            res = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return res;
}

int main()
{
    int books[] = {10, 20, 30, 40};
    int studs = 2;
    cout << findPages(books, 4, studs) << endl;
}
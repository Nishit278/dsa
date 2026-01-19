#include <bits/stdc++.h>
using namespace std;

int f_occ(vector<int> &nums, int key)
{
    int s = 0;
    int e = size(nums);
    int ans = -1;
    while (s < e)
    {
        int mid = (s + e) / 2;
        if (nums[mid] == key)
        {
            ans = mid;
            e = mid;
        }
        else if (nums[mid] > key)
            e = mid;
        else
            s = mid + 1;
    }
    return ans;
}

int l_occ(vector<int> &nums, int key)
{
    int s = 0;
    int e = size(nums);
    int ans = -1;
    while (s < e)
    {
        int mid = (s + e) / 2;
        if (nums[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (nums[mid] > key)
            e = mid;
        else
            s = mid + 1;
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 8, 9, 10};
    int n = nums.size();
    int key = 5;
    int first_occur = f_occ(nums, key);
    int last_occur = l_occ(nums, key);
    cout << first_occur << " " << last_occur << endl;
}
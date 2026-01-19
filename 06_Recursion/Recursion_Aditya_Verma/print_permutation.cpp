#include <bits/stdc++.h>
using namespace std;

void permute(vector<int> &nums, vector<vector<int>> &ans, int counter) // permutations without duplicates
{
    if (counter == nums.size())
    {
        ans.emplace_back(nums);
        return;
    }
    for (int k = counter; k < nums.size(); k++)
    {
        swap(nums[counter], nums[k]);
        permute(nums, ans, counter + 1);
        swap(nums[counter], nums[k]);
    }
    return;
}

void permute_duplicates(vector<int> nums, vector<vector<int>> &ans, int count)
{
    if(count == nums.size()-1){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> s;
        for(int i=count; i<nums.size();i++){
            if(s.find(nums[i])!=s.end()) continue;
            s.insert(nums[i]);
            swap(nums[count], nums[i]);
            permute_duplicates(nums, ans, count+1);
            
        }
        return;
}

int main()
{
    int counter = 0;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    permute(nums, ans, counter);

    for (vector<int> i : ans)
    {
        cout << "[";
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << "], ";
    }

    vector<int> arr = {1, 1, 2};
    vector<vector<int>> res;
    permute_duplicates(arr, res, counter);

    cout << endl
         << "With duplicates: " << endl;
    for (vector<int> i : res)
    {
        cout << "[";
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << "], ";
    }


    vector<vector<int>> v = {{1,2,3}, {4,5,6}};
    for(int i=0;i<size(v);i++){
        cout << v.back()[0] << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void buildTree(vector<int> &nums, vector<int> &tree, int s, int e, int index)
{
    if (s == e)
    {
        tree[index] = nums[s];
        return;
    }

    int mid = s + (e - s) / 2;

    buildTree(nums, tree, s, mid, 2 * index);
    buildTree(nums, tree, mid + 1, e, 2 * index + 1);

    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return;
}

int solveQuery(vector<int> &tree, int s, int e, int qs, int qe, int index)
{
    // For complete overlap
    if (qs >= s and qe <= e)
        return tree[index];
    // For No overlap
    if (qs > e or qe < s)
        return INT_MAX;
    int mid = s + (e - s) / 2;
    // For Partial overlap
    int left = solveQuery(tree, s, mid, qs, qe, 2 * index);
    int right = solveQuery(tree, mid + 1, e, qs, qe, 2 * index + 1);
    return min(left, right);
}

void update(vector<int> &tree, int s, int e, int i, int inc, int index)
{
    // if the index is out of bounds
    if (i < s or i > e)
        return;
    // if the index is a leaf node
    if (s == e)
    {
        tree[index] += inc;
        return;
    }
    int mid = s + (e - s) / 2;
    update(tree, s, mid, i, inc, 2 * index);
    update(tree, mid + 1, e, i, inc, 2 * index + 1);
    tree[index] =  min(tree[2*index], tree[2*index+1]);
    return;
}

int main()
{
    vector<int> nums = {1, 3, 2, -5, 6, 4};
    vector<int> tree(4 * size(nums) + 1);
    // int *tree = new int[4 * size(nums) + 1];
    int s = 0, e = nums.size() - 1, index = 1;
    buildTree(nums, tree, s, e, index);
    for (int &t : tree)
    {
        cout << t << " ";
    }
    cout << endl;

    int query;
    cin >> query;
    while (query--)
    {
        int qs, qe;
        cin >> qs >> qe;
        cout << solveQuery(tree, s, e, qs, qe, index) << endl;
    }
    int uq;
    cin >> uq;
    while (uq--)
    {
        int i, inc;
        cin >> i >> inc;
        update(tree, s, e, i, inc, index);
        for(int t: tree){
            cout << t << " ";

        }
        cout << endl;
    }

    return 0;
}
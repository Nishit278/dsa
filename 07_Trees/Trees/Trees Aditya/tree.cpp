#include "bits/stdc++.h"
using namespace std;
#define mod 1e9 + 7
#define INF 1000000000000000003

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *insert(TreeNode *root, int val)
{
    if (root == NULL)
        return new TreeNode(val);
    (root->val > val)
        ? root->left = insert(root->left, val)
        : root->right = insert(root->right, val);
}

void inorder(TreeNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int height(TreeNode *root)
{
    return !root ? 0 : max(height(root->left), height(root->right)) + 1;
}

bool isBalanced(TreeNode *root)
{
    if (root == NULL)
        return 1;
    if (isBalanced(root->left) and
        isBalanced(root->right) and
        (abs(height(root->left) - height(root->right)) <= 1))
        return 1;
    return 0;
}

vector<int> temp;
void solvePath(TreeNode *root, vector<string> &ans)
{
    if (root == NULL)
        return;
    if (root->left == NULL and root->right == NULL)
    {
        string t;
        for (auto i : temp)
            t += to_string(i) + "->";
        t += to_string(root->val);
        ans.push_back(t);
    }
    temp.push_back(root->val);
    solvePath(root->left, ans);
    solvePath(root->right, ans);
    temp.pop_back();
    return;
}

vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> ans;
    solvePath(root, ans);
    return ans;
}
void print(TreeNode *root, string indent, bool is_tail)
{
    cout << indent << "|---";
    if (root == nullptr)
    {
        cout << "NULL" << endl;
        return;
    }
    cout << root->val << endl;
    if (root->left != nullptr || root->right != nullptr)
    {
        indent.append(is_tail ? "    " : "|   ");
        print(root->right, indent, false);
        print(root->left, indent, true);
    }
}
void bst(TreeNode *root)
{
    cout << "\n****  BINARY SEARCH TREE  ****\n";
    print(root, "", false);
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    TreeNode *root = NULL;
    for (auto i : vector<int>{4, 3, 2, 1, 5, 8, 7, 6, 9})
        root = insert(root, i);
    bst(root);

    return 0;
}

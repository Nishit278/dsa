#include "bits/stdc++.h"
using namespace std;
#define mod 1e9 + 7
#define INF 1000000000000000003

struct node
{
    int data;
    node *left;
    node *right;
};

node *init(int data = 0)
{
    node *temp = new node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node *insert(node *root, int data)
{
    if (root == NULL)
        return init(data);
    (root->data > data)
        ? root->left = insert(root->left, data)
        : root->right = insert(root->right, data);
}

int search(node *root, int value)
{
    if (root == NULL)
        return 0;
    if (root->data == value)
        return 1;
    return (value < root->data)
               ? search(root->left, value)
               : search(root->right, value);
}

node *dUtil(node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

node *deletion(node *root, int value)
{
    if (root->data == value)
    {
        if (root->left != NULL and root->right != NULL)
        {
            node *temp = dUtil(root->right);
            root->data = temp->data;
            root->right = deletion(root->right, temp->data);
            return root;
        }
        if (root->left == NULL and root->right != NULL)
        {
            node *temp = root;
            root = root->right;
            delete temp;
            return root;
        }
        if (root->left != NULL and root->right == NULL)
        {
            node *temp = root;
            root = root->left;
            delete temp;
            return root;
        }
        else
        {
            delete root;
            return NULL;
        }
    }
    else if (value < root->data)
        root->left = deletion(root->left, value);
    else
        root->right = deletion(root->right, value);
}

void print(node *root, string indent, bool is_tail)
{
    cout << indent << "|---";
    if (root == nullptr)
    {
        cout << "NULL" << endl;
        return;
    }
    cout << root->data << endl;
    if (root->left != nullptr || root->right != nullptr)
    {
        indent.append(is_tail ? "    " : "|   ");
        print(root->right, indent, false);
        print(root->left, indent, true);
    }
}
void bst(node *root)
{
    cout << "\n****  BINARY SEARCH TREE  ****\n";
    print(root, "", false);
    cout << "\n";
}
void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void printInRange(node *root, int l, int r)
{
    if (root == NULL)
        return;
    if (root->data >= l and root->data <= r)
    {
        printInRange(root->left, l, r);
        cout << root->data << " ";
        printInRange(root->right, l, r);
    }
    // IMP cases
    else if (root->data < l)
        printInRange(root->right, l, r);
    else if (root->data > r)
        printInRange(root->left, l, r);
}

vector<int> temp;
void printAllPathsFromRootToLeaf(node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL and root->right == NULL)
    {
        for (auto i : temp)
            cout << i << " ";
        cout << root->data;
        cout << "\n";
    }
    temp.push_back(root->data);
    printAllPathsFromRootToLeaf(root->left);
    printAllPathsFromRootToLeaf(root->right);
    temp.pop_back();
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    node *root = NULL;
    for (auto i : vector<int>{4, 2, 6, 1, 3, 5, 7})
        root = insert(root, i);
    bst(root);
    printAllPathsFromRootToLeaf(root);

    return 0;
}

#include "bits/stdc++.h"
using namespace std;
#define mod 1e9 + 7
#define INF 1000000000000000003

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

Node *buildTree()
{
    int d;
    cin >> d;
    if (d == -1)
        return NULL;
    Node *n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

void print(Node *root, string indent, bool is_tail)
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
        indent.append(is_tail ? "     " : "|   ");
        print(root->right, indent, false);
        print(root->left, indent, true);
    }
}
void bst(Node *root)
{
    cout << "\n****  BINARY SEARCH TREE  ****\n";
    print(root, "", false);
    cout << "\n";
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelOrder(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    int lvl = 0;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        cout << "\nLevel " << ++lvl << "\n";
        while (size--)
        {
            Node *current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
    }
}

Node *levelOrderBuild()
{
    int d;
    cin >> d;
    Node *root = new Node(d);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        int c1, c2;
        cin >> c1 >> c2;
        if (c1 != -1)
        {
            current->left = new Node(c1);
            q.push(current->left);
        }
        if (c2 != -1)
        {
            current->right = new Node(c2);
            q.push(current->right);
        }
    }
    return root;
}

int height(Node *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

int diameter(Node *root)
{
    if (root == NULL)
        return 0;
    int d1 = height(root->left) + height(root->right);
    int d2 = diameter(root->left);
    int d3 = diameter(root->right);
    return max(d1, max(d2, d3));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Node *n = buildTree();
    // cout << "\n";
    // bst(n);
    // levelOrder(n);
    // cout << "\n";
    Node *root = levelOrderBuild();
    bst(root);
    return 0;
}

/*
1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

1 2 3 4 5 -1 6  -1 -1 7 -1 -1 -1 -1 -1
5 4 8 11 -1 13 4 7 2 -1 -1 5 1
*/
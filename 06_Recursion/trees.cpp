#include "bits/stdc++.h"
using namespace std;

struct node
{
	int val;
	node *left;
	node *right;
	node(int x) : val(x), left(nullptr), right(nullptr) {}
};

node *addNode(node *root, int data)
{
	if (root == NULL)
		return new node(data);
	else
		(root->val >= data) ? root->left = addNode(root->left, data) : root->right = addNode(root->right, data);
    return root;
}

void findnode(node *root, int value)
{
	if (!root)
	{
		cout << "NOT FOUND";
		return;
	}
	if (root->val == value)
		cout << "FOUND";
	else
		root->val > value ? findnode(root->left, value) : findnode(root->right, value);
}

node *deleteNode(node *root, int data)
{
	if (root == NULL)
		return root;
}

void inorder(node *root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}

void preorder(node *root)
{
	if (root == NULL)
		return;
	cout << root->val << " ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(node *root)
{
	if (root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout << root->val << " ";
}

void print1(node *root, string indent, bool is_tail)
{
	cout << indent << "|---";
	if (root == NULL)
	{
		cout << "NULL\n";
		return;
	}
	cout << root->val << "\n";
	if (root->left != NULL || root->right != NULL)
	{
		print1(root->right, indent + (is_tail ? "     " : "|   "), false);
		print1(root->left, indent + (is_tail ? "     " : "|   "), true);
	}
}

void bst(node *root)
{
	cout << "\n****  BINARY SEARCH TREE  ****\n";
	print1(root, "", false);
	cout << "\nPreorder: ";
	preorder(root);
	cout << "\nInorder: ";
	inorder(root);
	cout << "\nPostorder: ";
	postorder(root);
	cout << "\n";
}

int main()
{
	node *ROOT = NULL;
	ROOT = addNode(ROOT, 1);
	ROOT = addNode(ROOT, 4);
	ROOT = addNode(ROOT, 2);
	ROOT = addNode(ROOT, 7);
	ROOT = addNode(ROOT, 3);
	ROOT = addNode(ROOT, 6);
	ROOT = addNode(ROOT, 5);
	ROOT = addNode(ROOT, 20);
	findnode(ROOT, 0);
	bst(ROOT);
	return 0;
}
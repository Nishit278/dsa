#include <bits/stdc++.h>
using namespace std;

class node{

public:
	int data;
	node* left;
	node* right;
	node(int val): data(val), left(nullptr), right(nullptr){}
};


node* insert(node*root, int key){
	if(root==NULL){
		return new node(key);
	}
	if(key<root->data) root->left = insert(root->left, key);
	else root->right = insert(root->right, key);
	return root;
}

bool e_search(node* root, int val){
	if(!root) return false;
	if(val==root->data) return true;
	if(val<root->data) return e_search(root->left, val);
	else return e_search(root->right, val);
	return false;

}

node* find_min(node* root){
	while(root->left!=NULL){
		root = root -> left;
	}
	return root;
}

void level_order(node* root){ // BFS
	// we will use queue coz fifo and to store visited nodes
	queue<node*>q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* temp = q.front();
		if(temp==NULL){
			// cout << endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		} else {
			q.pop();
			cout << temp->data << " ";
			
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}
	}
}

node* remove(node* root, int data){
	if(!root) return NULL;
	if(data < root->data){
		root->left = remove(root->left, data);
	} 
	else if(data > root->data) root->right = remove(root->right, data);
	else{
		// if leaf node
		if(root->right == NULL and root->left == NULL){
			delete root;
			root = NULL;
		}
		// single child
		else if(root->left == NULL) {
			auto temp = root;
			root = root->right;
			delete(temp);
		}
		else if(root->right == NULL) {
			auto temp = root;
			root = root->left;
			delete(temp);
		}
		// 2 children
		else {
			node* temp = find_min(root->right);
			root->data = temp->data;
			root->right = remove(root->right, temp->data);
		}
	}
	return root;

}

void printInorder(node* root){
	if(!root) return;
	printInorder(root->left);
	cout << root->data << "->";
	printInorder(root->right);
}

int main(){
	node* root = NULL;
	int a[] = {5,3,6,2,4,7};
	for(auto x: a){
		root = insert(root,x);
	}
	// printInorder(root);
	level_order(root);
	cout << endl;
	// cout << e_search(root, 4) << endl;
	// cout << e_search(root, 5) << endl;
	// cout << e_search(root, 6) << endl;
	remove(root,3);
	level_order(root);

}


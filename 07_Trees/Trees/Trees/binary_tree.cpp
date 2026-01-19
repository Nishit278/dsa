#include <bits/stdc++.h>
using namespace std;

class node {

public:
	int data;
	node* left;
	node* right;
	node(int x) : data(x), left(nullptr), right(nullptr){}

	// other ways of writing a constructor
	/**
	 * node(int x){
	 * 	val = x;
	 * 	left = right = nullptr;
	 * }
	 * 
	 * node(int val){
	 * this.val = val;
	 * left = right= nullptr;
	 * }
	 * 
	 * **/
};
int diameter1 = 0;

node* buildTree(){ // pre-order build
	int d;
	cin >> d;
	if(d == -1) return NULL;
	node* n = new node(d);
	n->left = buildTree();
	n->right = buildTree();
	return n;
}

node* buildTreeBFS(){
	int d; cin >> d;
	node* root = new node(d);
	queue<node*> q;
	q.push(root);

	while(!q.empty()){
		node* curr = q.front();
		q.pop();
		int c1, c2;
		cin >> c1 >> c2;

		if(c1!=-1){
			curr->left = new node(c1);
			q.push(curr->left);
		}
		if(c2!=-1){
			curr->right = new node(c2);
			q.push(curr->right);
		}
	}
	return root;
}

void printPreorder(node* root){ // print in pre order
	if(root == NULL) return;
	cout << root->data << " ";
	printPreorder(root->left);
	printPreorder(root->right);
}

void printInorder(node* root){ // print in in order
	if(root == NULL) return;
	printInorder(root->left);
	cout << root->data << " ";
	printInorder(root->right);
}

void printPostorder(node* root){ // print in post order
	if(root == NULL) return;
	printPostorder(root->left);
	printPostorder(root->right);
	cout << root->data << " ";
}

void level_order(node* root){ // BFS
	// we will use queue coz fifo and to store visited nodes
	queue<node*>q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* temp = q.front();
		if(temp==NULL){
			cout << endl;
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

int height(node* root){
	if(root==NULL) return 0;
	int h1= height(root->left);
	int h2= height(root->right);
	return 1+max(h1,h2);
}

// Gen formula: if passes through root = maxdepth(left)+maxdepth(right) else  
pair<int,int> diameter(node* root){ // distance between 2 points which are farthest where dist between 7 and 6 has 5 edges
	if(root == NULL) return {0,0};
	pair<int, int> left = diameter(root->left);
	pair<int, int> right = diameter(root->right);
	int diam = max({left.first, right.first, left.second+right.second});
	return {diam, max(left.second, right.second)+1};
}

int dfs(node* root){
	if (!root) return 0;
        int left = dfs(root->left), right = dfs(root->right);
        diameter1 = max(diameter1, left + right);
        return max(left, right) + 1;
}


int main(){

 	cout << "							\n"
			"				1			\n" 
			"	  		  /   \\		\n"
			"	  		 2     3		\n"
			"	        / \\     \\		\n"
			"	  	   4   5     6		\n"
			"	           /			\n"
			"	          7 			\n" << endl;

	node* root = buildTree();
	cout << "Height of the tree is: " << height(root) << endl;
	
	cout << "\nPre-Order Traversal \n";
	printPreorder(root);
	cout << endl;
	cout << "In-Order Traversal \n";
	printInorder(root);
	cout << endl;
	cout << "Post-Order Traversal \n";
	printPostorder(root);
	cout << endl;
	cout << "Level-Order Traversal \n";
	level_order(root);
	cout << endl;

	// Building a tree in level order or BFS manner
	root = buildTreeBFS();
	level_order(root);
	
	cout << "The diameter of the tree is: ";
	int di = diameter(root).first;
	cout << di << endl;
	cout << "The diameter of the tree is: ";
	dfs(root);
	cout << diameter1 << endl;

	return 0;
}

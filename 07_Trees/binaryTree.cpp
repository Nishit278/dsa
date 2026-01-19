#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node *left;
    node *right;
    node(int x): val(x), left(NULL), right(NULL) {}
};

void levelOrderTraversal(node* root){
    if(root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        node *curr = q.front();
        q.pop();
        if(curr!=NULL){
            cout << curr->val << ", ";
            if (curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
    return;
}

int height (node* root){
    if(root == nullptr){
        return -1;
    }
    return max(height(root->left), height(root->right))+1;
}

int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    int h = height(root);
    cout << h << endl;
    levelOrderTraversal(root);
    cout << endl;
    return 0;
}
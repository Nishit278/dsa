#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node *left;
    node *right;
    node(int x): val(x), left(NULL), right(NULL) {}
};

int sumAtLevelK(node* root, int k){
    if(root == NULL)
        return -1;
    queue<node *> q;
    q.push(root);
    q.push(nullptr);
    int level = 1;
    int sum = 0;

    while(!q.empty() && level <=k){
        node *curr = q.front();
        q.pop();
        if(curr!=NULL){
            // cout << curr->val << ", ";
            sum += curr->val;
            if (curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
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
    int ans = sumAtLevelK(root,2);
    cout << ans << endl;
    return 0;
}
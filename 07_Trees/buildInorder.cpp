#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
    Node(int x): val(x), left(nullptr), right(nullptr){}
};

// Node* insert(Node* root, int val){
//     Node *node = new Node(val);
    
// }
Node* buildNodeInorder (vector<int> preorder, vector<int> inorder, int start, int end){
    if(start > end){
        return nullptr;
    }
    static int idx = 0;
    int curr = preorder[idx];
    idx++;
    Node *node = new Node(curr);
    if(start == end){
        return node;
    }
    int pos = find(inorder.begin(), inorder.end(), curr) - inorder.begin();
    node->left = buildNodeInorder(preorder, inorder, start, pos - 1);
    node->right = buildNodeInorder(preorder, inorder, pos + 1, end);
    return node;
}

void printInorder(Node* root){
    if(root==NULL)
        return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);

}
void printPreorder(Node* root){
    if(root==NULL)
        return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);

}
void printPostorder(Node* root){
    if(root==NULL)
        return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->val << " ";

}
int main(){
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
    Node *root = buildNodeInorder(preorder, inorder, 0, inorder.size() - 1);
    cout << "Inorder traversal: " << endl;
    printInorder(root);
    cout << endl;
    cout << "Preorder traversal: " << endl;
    printPreorder(root);
    cout << endl;
    cout << "Postorder traversal: " << endl;
    printPostorder(root);
    cout << endl;
    return 0;
}
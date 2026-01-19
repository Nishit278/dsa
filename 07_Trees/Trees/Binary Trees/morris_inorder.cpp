#include <bits/stdc++.h>
using namespace std;

class Tree
{
public:
    int val;
    Tree *left, *right;
    Tree(int d) : val(d), left(NULL), right(NULL) {}

    // Morris Traversal
    vector<int> morris_inorder(Tree* root){
        vector<int> inorder;
        Tree* curr = root;
        while(curr!=NULL){
            if(curr->left == NULL){
                inorder.push_back(curr->val);
                curr = curr->right;
            } else {
                Tree* prev = curr->left;
                while(prev->right && prev->right!=curr){
                    prev = prev->right;
                }
                if(!prev->right){
                    prev -> right = curr;
                    curr = curr->left;
                } else {
                    prev->right == NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};

int main()
{
    /**
     *          10
     *        /    \
     *      5       30
     *     / \    
     *    4   6   
     *     \   \
     *      2   8
     *     /
     *    1  
     * 
     * 
     **/

    Tree *t;
    Tree *root;
    root = new Tree(10);
    root->left = new Tree(5);
    root->right = new Tree(30);
    root->left->left = new Tree(4);
    root->left->right = new Tree(6);
    root->left->left->right = new Tree(2);
    root->left->right->right = new Tree(8);
    root->left->left->right->left = new Tree(1);

    vector<int> morris = t->morris_inorder(root);

    for(auto &m : morris){
        cout << m << " ";
    }
    cout << endl;
   

}
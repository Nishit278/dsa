#include <bits/stdc++.h>
using namespace std;

class Tree
{
public:
    int data;
    Tree *left, *right;
    Tree(int d) : data(d), left(NULL), right(NULL) {}

    int max_path_sum(Tree *root)
    {
        if (!root)
            return 0;
        int l = root->data + max_path_sum(root->left);
        int r = root->data + max_path_sum(root->right);
        return max(l, r);
    }
    // Zig-Zag traversal
    vector<vector<int>> zig_zag(Tree *root)
    {
        vector<vector<int>> zz;
        if (!root)
            return zz;
        queue<Tree *> q;
        q.push(root);
        int flag = 1;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> level(size);
            for (int i = 0; i < size; i++)
            {
                Tree *node = q.front();
                q.pop();
                int idx = flag ? i : size - 1 - i;
                level[idx] = node->data;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            flag = !flag;
            zz.push_back(level);
        }
        return zz;
    }
    // Vertical Order Traversal
    void vertical(Tree *root, int hd, int level, map<int, multiset<pair<int,int>>> &m)
    {
        if (root == NULL)
            return;
        m[hd].insert({level, root->data});
        vertical(root->left, hd - 1, level+1, m);
        vertical(root->right, hd + 1, level+1, m);
    }

    // Left view of a binary tree
    void left_view(Tree *root, vector<int> &res, int level)
    {
        if (!root)
            return;
        if (res.size() == level)
            res.push_back(root->data);
        left_view(root->left, res, level + 1);
        left_view(root->right, res, level + 1);
    }

    // Right view of a binary tree
    void right_view(Tree *root, vector<int> &res, int level)
    {
        if (!root)
            return;
        if (res.size() == level)
            res.push_back(root->data);
        right_view(root->right, res, level + 1);
        right_view(root->left, res, level + 1);
    }

    vector<int> topView(Tree *root)
    {   
        vector<int> res;
        if(!root) return res;
        queue<pair<Tree* , int>> q; // pair of node and level
        map<int,int> mp; // mapping node->val to level
        q.push({root, 0});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Tree* node = it.first;
            int level = it.second;
            
            if(mp.find(level) == mp.end()) mp[level] = node->data; // if not yet in map then push
            
            if(node->left) q.push({node->left, level-1});
            if(node->right) q.push({node->right, level+1});
        }
        for(auto it: mp){
            res.push_back(it.second);
        }
        return res;
    }

    vector<int> bottomView(Tree *root)
    {   
        vector<int> res;
        if(!root) return res;
        queue<pair<Tree* , int>> q; // pair of node and level
        map<int,int> mp; // mapping node->val to level
        q.push({root, 0});
        
        while(!q.empty()){ 
            auto it = q.front();
            q.pop();
            Tree* node = it.first;
            int level = it.second;
            
            // if(mp.find(level) == mp.end()) // for bottom view we omit this line
            mp[level] = node->data; // if not yet in map then push
            
            if(node->left) q.push({node->left, level-1});
            if(node->right) q.push({node->right, level+1});
        }
        for(auto it: mp){
            res.push_back(it.second);
        }
        return res;
    }
};

int main()
{
    /**
     *          1
     *        /   \
     *      3       6
     *     / \     / \
     *    8   9   4   5
     **/

    Tree *t;
    Tree *root;
    root = new Tree(1);
    root->left = new Tree(3);
    root->right = new Tree(6);
    root->left->left = new Tree(8);
    root->left->right = new Tree(9);
    root->right->left = new Tree(4);
    root->right->right = new Tree(5);

    // Max Path sum
    cout << "Max Path Sum: ";
    cout << t->max_path_sum(root);

    // Zig-Zag Traversal
    cout << "Zig-Zag traversal" << endl;
    vector<vector<int>> zz = t->zig_zag(root);
    for (auto i : zz)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    // Left view of Binary Tree
    cout << "Left View of Binary Tree: " << endl;
    vector<int> res;
    t->left_view(root, res, 0);
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Right View of Binary Tree: " << endl;
    vector<int> res2;
    t->right_view(root, res2, 0);
    for (auto i : res2)
    {
        cout << i << " ";
    }
    cout << endl;

    // Vertical order traversal
    cout << "Vertical order traversal:" << endl;
    map<int, multiset<pair<int,int>>> mp;
    int hdis = 0;
    int level = 0;
    t->vertical(root, hdis, level, mp);
    for (auto it : mp)
    {
        for (auto i : it.second)
        {
            cout << i.second << " ";
        }
        cout << endl;
    }

    cout << "Top view: " << endl;
    vector<int> ans = t->topView(root);
    for(auto i: ans){
        cout << i << " ";
    }
    cout << endl;

      cout << "Bottom view: " << endl;
    ans = t->bottomView(root);
    for(auto i: ans){
        cout << i << " ";
    }
    cout << endl;

}
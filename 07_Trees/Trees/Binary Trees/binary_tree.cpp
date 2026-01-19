#include <bits/stdc++.h>
using namespace std;

class Tree
{
public:
    int data;
    Tree *left, *right;
    Tree(int d) : data(d), left(NULL), right(NULL) {}

    // DFS (Inorder, Preorder, Postorder)
    void inorder(Tree *root)
    {
        if (!root)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    void preorder(Tree *root)
    {
        if (!root)
            return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(Tree *root)
    {
        if (!root)
            return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    // BFS (Level order traversal)
    void level_order(Tree *root)
    {
        if (!root)
            return;
        queue<Tree *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                Tree *node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                cout << node->data << " ";
            }
            cout << endl;
        }
    }

    // Iterative Pre-order Traversal - using stack
    void itr_preorder(Tree *root)
    {
        if (!root)
            return;
        stack<Tree *> st;
        st.push(root);
        while (!st.empty())
        {
            Tree *node = st.top();
            st.pop();
            cout << node->data << " ";
            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
        }
    }
    void itr_inorder(Tree *root)
    {
        if (!root)
            return;
        stack<Tree *> st;
        Tree *node = root;
        while (true)
        {
            if (node)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                if (st.empty())
                    break;
                node = st.top();
                st.pop();
                cout << node->data << " ";
                node = node->right;
            }
        }
    }

    void itr_postorder(Tree *root)
    { // using 2 stacks
        if (!root)
            return;
        stack<Tree *> st1, st2;
        st1.push(root);
        while (!st1.empty())
        {
            Tree *node = st1.top();
            st1.pop();
            st2.push(node);
            if (node->left)
                st1.push(node->left);
            if (node->right)
                st1.push(node->right);
        }
        while (!st2.empty())
        {
            auto node = st2.top();
            cout << node->data << " ";
            st2.pop();
        }
    }

    void itr_postorder2(Tree *root)
    {
        if (!root)
            return;
        Tree *curr = root;
        stack<Tree *> st;
        while (curr != NULL or !st.empty())
        {
            if (curr)
            {
                st.push(curr);
                curr = curr->left; // keep on going towards the left of the tree
            }
            else
            {                                // curr got null
                auto temp = st.top()->right; // go to the right side of last visited node
                if (!temp)
                {                              // if it doesn't exist
                    temp = st.top();           // store top in a temp var
                    st.pop();                  // pop the top
                    cout << temp->data << " "; // print it
                    while (!st.empty() and temp == st.top()->right)
                    { // keep doing it until you find a right branch
                        temp = st.top();
                        st.pop();
                        cout << temp->data << " ";
                    }
                }
                else
                {
                    curr = temp;
                }
            }
        }
    }

    // Max Depth
    int max_depth(Tree *root)
    {
        if (!root)
            return 0;
        int l_max = max_depth(root->left);
        int r_max = max_depth(root->right);
        return 1 + max(l_max, r_max);
    }

    int height(Tree *root, int &diameter)
    {
        if (!root)
            return 0;
        Tree *ptr = root;
        int l_max = height(ptr->left, diameter);
        int r_max = height(ptr->right, diameter);
        diameter = max(diameter, l_max + r_max);
        return 1 + max(l_max, r_max);
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

    cout << "Recursive DFS Traversals: " << endl;
    cout << "Inorder: ";
    t->inorder(root);
    cout << endl;
    cout << "Preorder: ";
    t->preorder(root);
    cout << endl;
    cout << "Postorder: ";
    t->postorder(root);
    cout << endl;
    cout << endl;
    cout << "Level-order(BFS): ";
    t->level_order(root);
    cout << endl;
    cout << "Iterative DFS Traversals: " << endl;
    cout << "Preorder: ";
    t->itr_preorder(root);
    cout << endl;
    cout << "Inorder: ";
    t->itr_inorder(root);
    cout << endl;
    cout << "Postorder: ";
    t->itr_postorder(root);
    cout << endl;
    cout << "Postorder(1 stack): ";
    t->itr_postorder2(root);
    cout << endl;
    cout << endl;

    // Max Depth of a binary tree
    cout << "Maximum Depth: ";
    cout << t->max_depth(root) << endl;
    cout << endl;
    cout << endl;

    // Diameter of a binary tree
    cout << "Diameter: ";
    int diameter = 0;
    t->height(root, diameter);
    cout << diameter << endl;
    cout << endl;
    cout << endl;
}
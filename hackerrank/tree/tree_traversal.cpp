/*
https://www.hackerrank.com/challenges/tree-preorder-traversal
*/
#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

void preorder_tree(node *root) {
    if (root == nullptr)
        return;    
    cout << root->data << " ";
    preorder_tree(root->left);
    preorder_tree(root->right);
}

void Postorder(node *root) {
    if (root == nullptr)
        return;    
    preorder_tree(root->left);
    preorder_tree(root->right);
    cout << root->data << " ";
}

void Inorder(node *root) {
    if (root == nullptr)
        return;
    preorder_tree(root->left);
    cout << root->data << " ";
    preorder_tree(root->right);    
}

/*
https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree
*/

void traveal(node *node, int depth, int &maxd) {
    if (node == nullptr)
        return;
    depth++;
    maxd = max(depth, maxd);
    traveal(node->left, depth, maxd);
    traveal(node->right, depth, maxd);
}

int height(node * root)
{
    int maxd = 0;
    traveal(root, 0, maxd);
    return maxd;
}

//https://www.hackerrank.com/challenges/binary-search-tree-insertion

node * insert(node * root, int value)
{
    node *x = root;
    node *y = nullptr;
    node *z = new node();
    z->data = value;
    while (x != nullptr) {
        y = x;
        if (z->data < x->data)
            x = x->left;
        else
            x = x->right;
    }
    if (y != nullptr) {
        if (z->data < y->data)
            y->left = z;
        else
            y->right = z;
        return root;
    }
    else {
        return z;
    }
}

//https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor

void travealLCA(node *node, bool &b1, bool &b2, int v1, int v2) {
   
}

node * lca(node * root, int v1, int v2)
{

    return nullptr;

}

#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Tree  {
    public:
    TreeNode* root;
    Tree() : root(nullptr) {};

    TreeNode*  insert(TreeNode* node) {
        int x; cin>>x;
        if(x==-1) return nullptr;

        TreeNode* newNode = new TreeNode(x);
        if(root==nullptr) {
            root=newNode; node=newNode;
        }

        node->left = insert(newNode);
        node->right = insert(newNode);
        return node;
    }

    void preorder() {
        TreeNode* node = root;
        if(node==nullptr) return;

        preorder(node->left);
        cout<<node->val<<" ";
        preorder(node->right);
    }
};

int main() {
    int x=10;
    while(x!=-2) {
        Tree obj;
        TreeNode* root = obj.insert(nullptr);
    }
    
    return 0;
}
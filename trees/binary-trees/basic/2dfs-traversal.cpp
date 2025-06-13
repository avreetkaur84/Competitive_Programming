// Question Link -

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// * Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void preOrder(TreeNode *node, vector<int> &arr)
    {
        if (node == nullptr)
            return;

        arr.push_back(node->val);
        preOrder(node->left, arr);
        preOrder(node->right, arr);
    }

    void inOrder(TreeNode* node, vector<int> &arr) {
        if(node==nullptr) return;

        inOrder(node->left, arr);
        arr.push_back(node->val);
        inOrder(node->right, arr);
    }

    void postOrder(TreeNode* node, vector<int> &arr) {
        if(node==nullptr) return;

        postOrder(node->left, arr);
        postOrder(node->right, arr);
        arr.push_back(node->val);
    }
};
// Question Link - https://leetcode.com/problems/merge-two-binary-trees/description/

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

class Solution {
public:
    // preorder traversal
    TreeNode* helper(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return nullptr;
        if(!root1) return root2;
        else if(!root2) return root1;
       
        TreeNode* node = new TreeNode(root1->val+root2->val);        
        node->left = helper((root1)?root1->left:nullptr, (root2)?root2->left:nullptr);
        node->right = helper((root1)?root1->right:nullptr, (root2)?root2->right:nullptr);

        return node;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return helper(root1, root2);
    }
};
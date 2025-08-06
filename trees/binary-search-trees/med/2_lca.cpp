// Question Link - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr || p==root || q==root) return root;

        if((root->val>p->val && root->val<q->val) ||(root->val<p->val && root->val>q->val)) return root;

        TreeNode* lf_Tree=nullptr; TreeNode* rf_Tree=nullptr;
        if(root->val>p->val && root->val>q->val) lf_Tree = lowestCommonAncestor(root->left, p, q);
        if(root->val<p->val && root->val<q->val) rf_Tree = lowestCommonAncestor(root->right, p, q);

        if(lf_Tree) return lf_Tree;
        else return rf_Tree;        
    }
};
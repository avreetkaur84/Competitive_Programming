// Question Link - https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

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
 
// max depth of binary tree
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1+max(lh, rh);
    }
};

// min depth of binary tree
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;

        int lf = minDepth(root->left);
        int rf = minDepth(root->right);

        if(lf==0 || rf==0) return 1+max(lf,rf);
        return 1+min(lf, rf);
    }
};
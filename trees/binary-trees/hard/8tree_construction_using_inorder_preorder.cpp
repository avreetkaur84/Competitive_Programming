// Question Link - https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// This question is really deep, like it will test or foundation of logic bulding!!! Good question

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
    TreeNode* helper(vector<int> &preorder, int p_st, int p_end, vector<int> &inorder, int i_st, int i_end, unordered_map<int, int> &mp) {
        if(p_st>p_end || i_st>i_end) return NULL;

        TreeNode* root = new TreeNode(preorder[p_st]);
        int rootIdx = mp[root->val];
        int lf_tree_ele = rootIdx-i_st;

        root->left = helper(preorder, p_st+1, p_st+lf_tree_ele, inorder, i_st, rootIdx-1, mp);
        root->right = helper(preorder, p_st+lf_tree_ele+1, p_end, inorder, rootIdx+1, i_end, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++)  mp[inorder[i]]=i;

        return helper(preorder, 0, n-1, inorder, 0, n-1, mp);
    }
};
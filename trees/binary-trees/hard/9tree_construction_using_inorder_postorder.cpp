// Question Link - https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// One needs to be extra careful while determining the starta dn end index of left and right subtree

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
    TreeNode* helper(vector<int>& inorder, int in_st, int in_end, vector<int>& postorder, int po_st, int po_end, unordered_map<int, int> &mp) {
        if(in_st>in_end || po_st>po_end) return NULL;

        TreeNode* root = new TreeNode(postorder[po_end]);
        int rootIdx = mp[root->val];
        int lf_size = rootIdx-in_st; 

        root->left = helper(inorder, in_st, rootIdx-1, postorder, po_st, po_st+lf_size-1, mp);
        root->right = helper(inorder, rootIdx+1, in_end, postorder, po_st+lf_size, po_end-1, mp);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp; int n=inorder.size();
        for(int i=0; i<n; i++) mp[inorder[i]] = i;

        return helper(inorder, 0, n-1, postorder, 0, n-1, mp);
    }
};
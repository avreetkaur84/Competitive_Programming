// Question Link - https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

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
    void helper(TreeNode* node, int &i, int mn, int mx, vector<int>& preorder) {
        if(i<0 || i>=preorder.size()) return;
        // cout<<"Main: "<<i<<" "<<node->val<<" "<<preorder[i]<<endl;

        // lf -> min=parent_min , max=parent
        if(preorder[i]<node->val) {
            // cout<<"Lf: "<<i<<" "<<node->val<<" "<<preorder[i]<<endl;
            if(preorder[i]<node->val && preorder[i]<mn) return;
            TreeNode* newNode = new TreeNode(preorder[i]);
            node->left = newNode; i++;
            helper(newNode, i, mn, node->val, preorder);
        }

        if(i<0 || i>=preorder.size()) return;
        
        if(preorder[i]>node->val) {
            // cout<<"Rf: "<<i<<" "<<node->val<<" "<<preorder[i]<<endl;
            if(preorder[i]>node->val && preorder[i]>mx) return;
            TreeNode* newNode = new TreeNode(preorder[i]);
            node->right = newNode; i++;
            helper(newNode, i, node->val, mx, preorder);
        }
        
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        int i=1;
        helper(root, i, INT_MIN, INT_MAX, preorder);
        return root;
    }
};
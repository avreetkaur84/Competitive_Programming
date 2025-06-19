// Question Link - https://leetcode.com/problems/binary-tree-maximum-path-sum/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

//  * Definition for a binary tree node.
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
    int helper(TreeNode* node, int &maxx) {
        if(node==nullptr) return 0;

        int lf = helper(node->left, maxx);
        int rf = helper(node->right, maxx);

        // int c1 = node->val;
        // int c2 = max(node->val+lf, c1);
        // int c3 = max(node->val+rf, c2);
        // int c4 = max(node->val+lf+rf, c3);
        maxx = max(maxx, node->val+max(lf,0)+max(rf, 0));
        // cout<<maxx<<endl;

        return node->val+ max(0, max(rf, lf));
    }

    int maxPathSum(TreeNode* root) {
        if(root==nullptr) return 0;
        int maxx=INT_MIN;
        maxx = max(helper(root, maxx), maxx);
        // maxx=max(root->val, maxx);

        return maxx;
    }
};
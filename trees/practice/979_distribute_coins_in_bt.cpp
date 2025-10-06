// Question Link - https://leetcode.com/problems/distribute-coins-in-binary-tree/description/

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
    // moves calculation -> get from l+r
    // val of node: l+r+root->val-1;
    int ans=0;  

    int helper(TreeNode* root)  {
        if(root==nullptr) return 0;

        int l = helper(root->left);
        int r = helper(root->right);
        ans += abs(l)+abs(r);
        return l+r+root->val-1;
    }

    int distributeCoins(TreeNode* root) {
        if(root==nullptr) return 0;

        helper(root);
        return ans;
    }
};
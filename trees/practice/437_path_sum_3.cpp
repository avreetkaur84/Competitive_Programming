// Question Link - https://leetcode.com/problems/path-sum-iii/description/

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
    // agar I create one for function and har node ke liye woh call kare
    int cnt = 0;

    void helper(TreeNode* node, long long sum, int target) {
        if(!node) return;
        if(node->val+sum==target) cnt++;

        helper(node->left, sum+node->val, target);
        helper(node->right, sum+node->val, target);  
    }

    void preorder(TreeNode* node, int target) {
        if(!node) return;

        helper(node, 0, target);
        preorder(node->left, target);
        preorder(node->right, target);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return 0;
        preorder(root, targetSum);
        return cnt;
    }
};
// Question Link - https://leetcode.com/problems/validate-binary-search-tree/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

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
    bool helper(TreeNode* node, long long minn, long long maxx) {
        if(node==nullptr) return true;
        // cout<<node->val<<" min: "<<minn<<" maxx: "<<maxx<<endl;
        if(node->val<=minn || node->val>=maxx) return false;

        bool flag1 = helper(node->left, minn, node->val);
        if(!flag1) return false;
        bool flag2 = helper(node->right, node->val, maxx);
        if(!flag2) return false;

        return true;
    }

    bool isValidBST(TreeNode* root) {
        if(root==nullptr) return true;
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};
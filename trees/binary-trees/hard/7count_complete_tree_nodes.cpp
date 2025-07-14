 // Question Link - https://leetcode.com/problems/count-complete-tree-nodes/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

/*
    1. Calculate the height of right and left subtree. 
    2. If height is equa then asnwer is simple 2^h-1
    3. If not -> move to tnext left adn right and then check again.
*/

class Solution {
public:
    int leftTreeHeight(TreeNode* node) {
        if(node==nullptr) return 0;
        return 1+leftTreeHeight(node->left);
    }

    int rightTreeHeight(TreeNode* node) {
        if(node==nullptr) return 0;
        return 1+rightTreeHeight(node->right);
    }

    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;

        int lf = leftTreeHeight(root->left);
        int rf = rightTreeHeight(root->right);

        if(lf==rf) return pow(2, lf+1)-1;
        return 1+countNodes(root->left) + countNodes(root->right);
    }
};
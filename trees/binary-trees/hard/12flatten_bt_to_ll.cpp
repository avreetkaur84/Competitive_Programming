// Question Link - https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Flattened using Morris Traversal Technique

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
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        TreeNode* cur = root;

        while(cur!=NULL) {
            if(cur->left!=NULL) {
                TreeNode* leftChild = cur->left;
                while(leftChild->right!=NULL) {
                    leftChild = leftChild->right;
                }

                leftChild->right = cur->right;
                TreeNode* temp = cur->left;
                cur->right=temp; cur->left=NULL;
                cur = temp;
            } else {
                cur = cur->right;
            }
        }
    }
};
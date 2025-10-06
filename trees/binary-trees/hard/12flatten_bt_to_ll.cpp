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

// on 2 oct, 2025
class Solution2 {
public:
    /*
        backtrack mein kaise return karu, means right node left se link ho then left root se, es liye maine ulta chalaya hai
    */

    TreeNode* helper(TreeNode* node) {
        if(!node) return nullptr;
        if(!node->left && !node->right) return node;

        TreeNode* leftTail = helper(node->left);
        TreeNode* rightTail = helper(node->right);

        if(leftTail) {
            TreeNode* store = node->right;
            node->right = node->left;
            node->left = nullptr;
            leftTail->right = store;
        }

        if(rightTail) return rightTail;
        if(leftTail) return leftTail;
        return nullptr;
    }

    void flatten(TreeNode* root) {
        helper(root);
    }
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
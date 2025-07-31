// Question Link - https://leetcode.com/problems/delete-node-in-a-bst/description/

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return nullptr;
        
        if(root->val<key) root->right = deleteNode(root->right, key);
        else if(root->val>key) root->left = deleteNode(root->left, key);
        else {
            if(!root->right) return root->left;
            if(!root->left) return root->right;

            TreeNode* temp = root->right;
            while(temp->left) temp=temp->left;
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }

        return root;
    }
};
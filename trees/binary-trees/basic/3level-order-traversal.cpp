// Question Link - https://leetcode.com/problems/binary-tree-level-order-traversal/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// * Definition for a binary tree node.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr) return res;

        queue<TreeNode*> q;
        q.push(root);        

        while(!q.empty()) {
            vector<int> arr;
            int n = q.size();

            for(int i=0; i<n; i++) {
                TreeNode* node = q.front();

                if(node->left!=nullptr) q.push(node->left); 
                if(node->right!=nullptr) q.push(node->right);                 
                
                arr.push_back(node->val);
                q.pop();
            }            

            res.push_back(arr);            
        }

        return res;
    }
};
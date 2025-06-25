// Question Link - https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr) return res;
        queue<TreeNode*> q; int cnt=1;
        q.push(root);

        while(!q.empty()) {
            int n=q.size(); vector<int> arr;
            for(int i=0; i<n; i++) {
                TreeNode* node = q.front();
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
                arr.push_back(node->val); q.pop();
            }

            if(cnt & 1) res.push_back(arr);
            else {
                reverse(arr.begin(), arr.end());
                res.push_back(arr);
            }
            
            cnt++;
        }

        return res;
    }
};

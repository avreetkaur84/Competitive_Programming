// Question Link - https://leetcode.com/problems/binary-tree-right-side-view/description/

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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr) return {};
        queue<pair<TreeNode*, int>> q;
        map<int, int> mp; vector<int> res;

        q.push({root, 0});
        while(!q.empty()) {
            TreeNode* node=q.front().first;

            if(node->left) q.push({node->left, q.front().second+1});
            if(node->right) q.push({node->right, q.front().second+1});

            mp[q.front().second]=node->val; q.pop();
        }

        for(const auto& i : mp) {
            res.push_back(i.second);
        }

        return res;
    }
};
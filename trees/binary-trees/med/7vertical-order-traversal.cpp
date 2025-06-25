// Question Link - https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

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
    /*
        what I can observe:
        1. Child idx depends on parents idx, so, first, use the parent idx everytime to assign the idx to child.
        2. Solve the question in 2 traverses. First traverse, assign the idx to all the nodes and store it. Here comes catch, we have to print vertical traversal, means column vise traversal. So, storage of final array size will be maxx colm we get. So, there is no need to sort, we can append directly.
        3. How to store idx and how to traverse the array to store idx: Level order tarevrsal with stack to assign the addresses, and store in vector array.
        
    */

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==nullptr) return {{}};

        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, vector<pair<int, int>>> mp;
        int mc=0;

        q.push({root, {0, 0}}); 

        while(!q.empty()) {
                TreeNode* node = q.front().first;
                pair<int, int> q_sec=q.front().second; q.pop(); 

                if(node->left!=nullptr) q.push({node->left, {q_sec.first+1, q_sec.second-1}});
                if(node->right!=nullptr) q.push({node->right, {q_sec.first+1, q_sec.second+1}});

                mp[q_sec.second].push_back({q_sec.first, node->val});
        }

        vector<vector<int>> res; 

        // worked perfectly fine on leetcode!! -> commented part is included in solution

        // for(auto& [key, vec] : mp) {
        //     sort(vec.begin(), vec.end());
        //     vector<int> temp;

        //     for(const auto& p : vec) temp.push_back(p.second);
            
        //     res.push_back(temp);
        // }

        return res;
    }
};
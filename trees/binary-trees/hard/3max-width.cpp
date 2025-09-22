// Question Link - https://leetcode.com/problems/maximum-width-of-binary-tree/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    I didn't know how to solve this question, so I watched striver tutorial, and got the intution. To be honest, I learnt a lot from this question. It was my first time, dealig with indexes of binary tree and then even converting them to avoid int overflow.
    I go tthe intution earlier that level order traversal will be implemented, but I didn't know how exactly.
    Algorithm:
    1. We have to put the node and its index in the queue.
    2. To insert left node, we will use formula (2*i)+1 -> 0 based indexing
    3. To insert right node, we will use formula (2*i)+2
    4. Now, we will convert the i for every level, because otherwise we will get integer overflow error.
*/


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
    int widthOfBinaryTree(TreeNode* root) {
        if(root->left==nullptr && root->right==nullptr) return 1;
        queue<pair<TreeNode*, long long>> q; int maxWd=0;
        
        if(root) q.push({root, 0});        // {node, idx}

        while(!q.empty()) {
            int n=q.size(); long long minn=q.front().second, maxx=-1;
            for(int i=0; i<n; i++) {
                TreeNode* node=q.front().first; long long idx=q.front().second; maxx=idx;
                if(node->left) q.push({node->left, 2*(idx-minn)+1});
                if(node->right) q.push({node->right, 2*(idx-minn)+2});
                q.pop();
            }
            maxWd = max(maxWd, int(maxx-minn+1));
        }

        return maxWd;
    }
};
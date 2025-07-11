// Question Link - https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    Got the intution idea from striver, but coded everything on my own from scratch.
    1. Store the parent pointers of every child in the hashmap
    2. Then start traversing from the target node, and keep track of distance also.
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
    // do level order traversal and mark pointers
    unordered_map<TreeNode*, TreeNode*> markParents(TreeNode* node) {
        queue<TreeNode*> q; unordered_map<TreeNode*, TreeNode*> mp;
        if(node) {
            q.push(node);
            mp[node] = NULL;
        }

        while(!q.empty()) {
            int n=q.size(); 
            for(int i=0; i<n; i++) {
                TreeNode* node=q.front();
                if(node->left) {
                    q.push(node->left);
                    mp[node->left] = node;
                }
                if(node->right) {
                    q.push(node->right);
                    mp[node->right] = node;
                }
                q.pop();
            }
        }

        return mp;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res; set<TreeNode*> visited;
        unordered_map<TreeNode*, TreeNode*> mp;
        mp = markParents(root);

        // start traversing from target node -> to distance k nodes
        queue<TreeNode*> q; q.push(target); visited.insert(target);
        while(!q.empty()) {
            if(k==0) break;
            int n=q.size(); 
            for(int i=0; i<n; i++) {
                TreeNode* node=q.front();
                if(node->left && visited.find(node->left)==visited.end()) {
                    q.push(node->left); visited.insert(node->left);
                }
                if(node->right && visited.find(node->right)==visited.end()) {
                    q.push(node->right); visited.insert(node->right);
                }
                TreeNode* parent = mp[node];
                if(parent && visited.find(parent)==visited.end()) {
                    q.push(parent); visited.insert(parent);
                }
                q.pop();
            }
            k--;
        }

        if(k==0) {
            while(!q.empty()) {
                int data = q.front()->val;
                res.push_back(data); q.pop();
            }
        }

        return res;
    }
};
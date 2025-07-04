// Question Link - https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        if(root==nullptr) return {};
        queue<pair<Node*, pair<int, int>>> q;  // {Node, {row, col}}
        map<int, int> mp; // {col, {row, val}}
        vector<int> res;
        
        q.push({root, {0,0}});
        
        while(!q.empty()) {
            Node* node=q.front().first; 
            pair<int, int> p = q.front().second;
            
            if(node->left) q.push({node->left, {p.first+1, p.second-1}});
            if(node->right) q.push({node->right, {p.first+1, p.second+1}});
            
            mp[p.second]=node->data;
            q.pop(); 
        }
        
        for(auto &i : mp) {
            res.push_back(i.second);
        }
        
        return res;
    }
};
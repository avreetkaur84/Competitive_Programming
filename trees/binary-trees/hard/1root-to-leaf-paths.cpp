// Question Link - https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    Just five days ago I was not able to solve this quuestion, so I started doing dp questions and today within 20 minutes, I did this question right, by writing full code from scratch and not seeing a single tutorial video.
    I mean I guess I am making some progress and this was fucking recursion question, which is my current weakness.
*/

// Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};


class Solution {
  public:
    void helper(Node* node, vector<int> arr, vector<vector<int>> &res) {
        if(node==nullptr) return;
        
        if(node->left==nullptr && node->right==nullptr) {
            res.push_back(arr); return;
        }
        
        vector<int> arr1 = arr;
        if(node->left!=nullptr) arr1.push_back(node->left->data);
        if(node->left) helper(node->left, arr1, res);
        
        vector<int> arr2 = arr;
        if(node->right!=nullptr) arr2.push_back(node->right->data);
        if(node->right) helper(node->right, arr2, res);
    }
  
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> res;
        if(root->left==nullptr && root->right==nullptr) return {{root->data}};
        
        helper(root, {root->data}, res);
        return res;
    }
};
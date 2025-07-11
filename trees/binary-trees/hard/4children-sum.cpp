// Question Link - https://www.geeksforgeeks.org/problems/children-sum-parent/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    Solved this question under 20 minutes on first try, like built everything from scracth without any help!!!! Still can't believe, this happened.
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
    void helper(Node* node, int &res) {
        if(res==0) return;
        
        if(node->left==nullptr && node->right==nullptr) return;
        int lf=0, rf=0; 
        if(node->left) lf = node->left->data;
        if(node->right) rf = node->right->data;
        if(lf+rf != node->data) {
            res=0; return;
        }
        
        if(node->left) helper(node->left, res);
        if(node->right) helper(node->right, res);
    }
    
    int isSumProperty(Node *root) {
        int res=1;
        helper(root, res);
        return res;
    }
};
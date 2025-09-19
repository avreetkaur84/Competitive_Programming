// Question Link - https://leetcode.com/problems/same-tree/description/

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


// simple inorder traversal
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr) return true;
        if((p==nullptr && q!=nullptr) || (q==nullptr && p!=nullptr)) return false;

        if(p->val!=q->val) return false;
        bool res1 = isSameTree(p->left, q->left);
        bool res2 = isSameTree(p->right, q->right);
        if(res1==false || res2==false) return false;
        else return true;
    }
};

class Solution {
public:
    // !!! LOSER !!!

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val!=q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
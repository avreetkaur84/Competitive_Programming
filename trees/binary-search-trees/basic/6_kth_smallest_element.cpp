// Question Link - https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

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
    void inorder(TreeNode* node, int k, int &cnt, int &val) {
        if(node==nullptr) return;

        if(node->left) inorder(node->left, k, cnt, val);
        cnt++;
        // cout<<cnt<<" "<<node->val<<endl;
        if(cnt==k) {
            val=node->val; return;
        }
        if(node->right) inorder(node->right, k, cnt, val);
    }

    int kthSmallest(TreeNode* root, int k) {
        int val=-1, cnt=0;
        inorder(root, k, cnt, val);
        return val;
    }
};
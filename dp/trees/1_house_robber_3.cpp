// Question Link: https://leetcode.com/problems/house-robber-iii/description/

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
        Postorder trvaersal: node, ke left and right ka data chaheye
        har node ke liye pick and non_pick store hogga
        I am not skipping more than 1 elements contnuously, below i more of a greedy approach

    */
    using pi = pair<int, int>;    // {pick, non_pick}

    pi memo(TreeNode* node) {
        if(node==nullptr) return {0, 0};

        // left & right mein se bhi max hi choose karna hai
        pi left = memo(node->left);
        pi right = memo(node->right);

        
        //  another problem, code dono left right ko lae hi raha hai, hardcoded jadda hai yeh
        // wait, left tree ka sab alag caculate gohha & right ka alag, maine mix kar deeya

        // non pick ko shorne ka koi faeda nii hogga
        int pick = left.second+right.second+node->val;
        // non pick change hogga -> non_pick mein 2 choices - 
        int non_pick = max(left.first, left.second)+max(right.first, right.second);

        return {pick, non_pick};
    }

    int rob(TreeNode* root) {
        pi res = memo(root);
        return max(res.first, res.second);
    }
};
// Question Link - https://leetcode.com/problems/symmetric-tree/description/

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

    /*
        1. I knew my recusion is weak but this question made me feel this again as I was able to draw and iterate this question recursive solution on my notebood but I as unable to write it in code. So, for code I had to refer to tutorial.
        2. My first first intutionwas to try and solve this question using level order traversal but it was using too much memory and I got memory limit exceed error.
    */

class Solution {
public:
    bool helper(TreeNode* left, TreeNode* right) {
        if(left==nullptr || right==nullptr) return left==right;

        if(left->val != right->val) return false;

        return helper(left->left, right->right) && helper(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        return helper(root->left, root->right);
    }
};


// GOT MEMORY LIMIT EXCEED ERROR
 class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr || (root->left==nullptr && root->right==nullptr)) return true;
        queue<TreeNode*> q; 
        q.push(root); bool flag;

        while(!q.empty()) {
            flag=true;
            int n=q.size(); vector<int> arr;
            for(int i=0; i<n; i++) {
                TreeNode* node = q.front();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

                arr.push_back(node->val);
                if(node==root) flag=false;
            }

            if(flag) {
                if(arr.size()&1) return false;
                vector<int> a(n/2); vector<int> b(n/2);
                for(int i=0; i<n/2; i++) a[i]=arr[i];
                for(int i=n/2; i<n; i++) b[i]=arr[i];
                reverse(b.begin(), b.end());
                if(a!=b) return false;
            }
        }

        return true;
    }
};
// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left; TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int Val) : val(Val), left(nullptr), right(nullptr) {};
    TreeNode(int Val, TreeNode* Left, TreeNode* Right) : val(Val), left(Left), right(Right) {};
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = root;
        if(root==NULL) {
            root = new TreeNode(val);
            return root;
        }
        
        while(node!=NULL) {
            if(node->val<val) {
                if(node->right==NULL) {
                    node->right = new TreeNode(val); break;
                }
                node=node->right;
            }
            else if(node->val>val) {
                if(node->left==NULL) {
                    node->left = new TreeNode(val); break;
                }
                node=node->left;
            }
        }

        return root;
    }
};
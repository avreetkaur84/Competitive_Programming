// Question Link - http://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Revised again on 20 Sep, 2025
/*
    Pure Backtracking.
    - We have root, lf, rf
    - If node is found in lf -> it return found node
    - If node is found in rf -> it retuns found node
    - If node is not found -> in returns NULL, means when root becomes NULL
    - So, we will have 3 cases:
        1. Lf = NULL -> means both nodes will be in rf, return rf
        2. rf = NULL -> means both nodes will be in lf, return lf
        3. LF!=null and rf!=NULL -> means boh nodes are under root, so will return root.
*/


/*
    Here, I have to return that node, who has both the nodes present in its subtree.
    Now, tree only traverses downward, 
    I have to first make a check of visited, like if p node was found in this subtree, and then q. If both nodes are found in that subtree then we can return the node under which these both comes. But, then we have to preserve the state, or basically, we will be using using recursion and backtracking, now, this thing, ancestor node will be found with backtracking as we have to return the lowest commo node.
    Now, I have idea, but I have confusion in code implementation and idea clarity, its unconnected dots so far.

    - Taken the starting intution hint from tutorial
*/

// Striver's Solution - Mind bowgling -> Insane dude!!!!!!!
// This solution gives the answer with just backtracking, without using any space-> I have to learn a lot.....
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q) return root;

        TreeNode* lf = lowestCommonAncestor(root->left, p, q);
        TreeNode* rf = lowestCommonAncestor(root->right, p, q);

        if(lf==NULL) return rf;
        else if(rf==NULL) return lf;
        else return root;
    }
};


// First solution - Got MLE

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


//  This is wrong -> I have to correct it still!!
class Solution {
public:
    void helper(TreeNode* node, TreeNode* req, vector<TreeNode*> &arr) {
        if(node==nullptr) return;
        if(node == req) {
            return;
        }

        if(node->left!=nullptr) arr.push_back(node->left);
        if(node->left) helper(node->left, req, arr);

        vector<TreeNode*> arr2 = arr;
        if(node->right!=nullptr) arr2.push_back(node->right);
        if(node->right) helper(node->right, req, arr2);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_path; vector<TreeNode*> q_path;
        helper(root, p, p_path);
        helper(root, q, q_path);

        int i=0;
        while(i<p_path.size() && i<q_path.size()) {
            // cout<<p_path[i]->val<<"  "<<q_path[i]->val<<endl;
            if(p_path[i]!=q_path[i]) return p_path[i-1];
            i++;
        }

        return p_path[i-1];
    }
};




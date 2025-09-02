#include <iostream>
using namespace std;

/*
    Try to vidualize the cases and write the code according to cases
*/

class TreeNode {
    public:
     int val;
     TreeNode* left;
     TreeNode* right;

     TreeNode(int v) {
        val=v; left=nullptr; right=nullptr;
     }

     TreeNode(int v, TreeNode* Left, TreeNode* Right) {
        val=v;
        left=Left;
        right=Right;
     }
};

TreeNode* Delete(TreeNode* root, int key) {
    if(root==nullptr) return;
    
    if(root->val>key) root->left = Delete(root->left, key);
    else if(root->val<key) root->right = Delete(root->right, key);
    else {
        // root->val == key
        TreeNode* temp = root->left;
        while(temp->right!=nullptr) temp=temp->right;
        // Delete(root->left, )
    }
}
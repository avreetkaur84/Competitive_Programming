// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    - Dry run a big example on notebook first after understanding the intution, It was really fun to solve this question as it consumed a lot of brain cells to dry run a big example :) - turning psycho day by day I guess!!
    1. Root ke left ke right most child to sabse phele root se connect karna hai.
    2. Then root ke left ke left child ke pass jatte raho and then left child ko uske root ke sath connect karte jao
*/

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> arr;
        TreeNode* cur = root;

        while(cur!=NULL) {
            if(cur->left==NULL) {
                arr.push_back(cur->val);
                cur=cur->right;
            } else {
                TreeNode* leftChild = cur->left;
                while(leftChild->right!=NULL) leftChild=leftChild->right;
                leftChild->right=cur;

                TreeNode* temp = cur;
                cur = cur->left;
                temp->left = NULL;
            }
        }

        return arr;
    }
};


// MORRIS PREORDER TRAVERSAL
vector<int> preorder(Node* root) {
        if(root==NULL) return {};
        vector<int> arr;
        Node* cur = root;
        
        while(cur!=NULL) {
            arr.push_back(cur->data);
            if(cur->left==NULL) {
                cur=cur->right;
            } else {
                // arr.push_back(cur->data);
                Node* leftChild = cur->left;
                while(leftChild->right != NULL) leftChild = leftChild->right;
                leftChild->right = cur->right;
                
                Node* temp = cur;
                cur=cur->left;
                temp->left=NULL;
            }
        }
        
        return arr;
        
    }
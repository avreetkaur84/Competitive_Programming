// Question Link -

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// * Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};

        vector<int> arr;
        stack<TreeNode* > st;
        st.push(root);

        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop(); arr.push_back(node->val);

            if(node->right != nullptr) st.push(node->right);
            if(node->left != nullptr) st.push(node->left);
        }

        return arr;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};

        vector<int> arr;
        stack<TreeNode* > st;

        TreeNode* mover = root;
        while(mover!=nullptr) {
            st.push(mover); mover=mover->left;
        }

        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop(); arr.push_back(node->val);
            // cout<<node->val<<endl;

            if(node->right!=nullptr) {
                node = node->right; 

                while(node!=nullptr) {
                    st.push(node); node=node->left; 
                }
            }
        }


        return arr;
    }

    // using 2 stacks
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> arr;
        if(root==nullptr) return arr;

        stack<TreeNode*> st1, st2;  
        st1.push(root);

        while(!st1.empty()) {
            TreeNode* node = st1.top();
            st1.pop(); st2.push(node);

            if(node->left!=nullptr) st1.push(node->left);
            if(node->right!=nullptr) st1.push(node->right);
        }

        while(!st2.empty()) {
            arr.push_back(st2.top()->val);
            st2.pop(); 
        }

        return arr;
    }


    // using 1 stack;
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> arr;
        if(root==nullptr) return arr;

        stack<TreeNode*> st;  
        TreeNode* node = root;

        while(!st.empty() || node!=nullptr) {
            if(node!=nullptr) {
                st.push(node); node = node->left;
            } else {
                TreeNode* temp = st.top()->right;
                if(temp==nullptr) {
                    temp = st.top(); st.pop(); arr.push_back(temp->val);

                    while(!st.empty() && temp==st.top()->right) {
                        temp=st.top(); st.pop(); arr.push_back(temp->val);
                    }
                } else node = temp;
            }
        }

        return arr;
    }
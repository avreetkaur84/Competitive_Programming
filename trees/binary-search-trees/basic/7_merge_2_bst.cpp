// Question Link - https://www.geeksforgeeks.org/problems/merge-two-bst-s/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;


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
    void inorder(Node* root, vector<int> &arr) {
        if(root==nullptr) return;
        
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
    
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int> t1;
        inorder(root1, t1);
        inorder(root2, t1);
        sort(t1.begin(), t1.end());
        
        return t1;
    }
};
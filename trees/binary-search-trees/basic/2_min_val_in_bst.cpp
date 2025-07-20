// Question Link - 

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
  
    int minValue(Node* root) {
        if(root==NULL) return -1;
        
        while(root->left!=NULL) root=root->left;
        return root->data;
    }
};

/*
    First try - But I got TLE as I was too focused on the technique than problem and concepts. I just jumped into code even before analyzing everything in detail, which is worst mistake that a coer can make. 
*/
class TLE {
  public:
    Node* bst(Node* root) {
        if(root->left==NULL && root->right==NULL) return root;
        
        if(root->left) root=root->left;
        return bst(root);
    }
  
    int minValue(Node* root) {
        // if(root==NULL) return 0;
        Node* res = bst(root);
        return res->data;
    }
};
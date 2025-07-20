// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    In my pattern of writing code, I haev observed that I write nested if's and this is something that needs to be improved. I nned to think of flat logics.
*/

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

// Finally did this!!!!!!!
int findCeil(Node* root, int input) {
    if(root==NULL) return -1;
    int ans=-1;
    while(root) {
        // cout<<root->data<<endl;
        if(root->data==input) return input;
        if(root->data>input) {
            ans=root->data;
            root=root->left;
        } else {
            root = root->right;
        }
    }
    
    return ans;
    
}

// MY FIRST TRY:
int findCeil(Node* root, int input) {
    if(root==NULL) return -1;
    int ans=root->data;
    while(root) {
        // cout<<root->data<<endl;
        if(root->data==input) return input;
        
        if(root->data>input) {
            if(root->left==NULL) return ans;
            else {
                root=root->left; 
                if(root->left==NULL && root->right==NULL) return ans;
                ans=root->data;
            }
        } else {
            if(root->right==NULL) {
                if(ans<input) return -1;
                else return ans;
            }
            else {
                root=root->right; ans=root->data;
            }
        }
    }
    
    return -1;
}
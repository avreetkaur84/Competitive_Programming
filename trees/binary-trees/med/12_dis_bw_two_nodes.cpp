// Question Link - https://www.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1
#include <bits/stdc++.h>
using namespace std;

/*
    1. Find the root under which both nodes fall.
    2. Count the distace from root to left node and then to the right node, where left and right node are p and q nodes.
    3. Our reccursion will return once we have found p or q, won't go till null.
*/

//  A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; 

class Solution {
  public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    
    /*
        2 functions : 
            1. common root : LCA
            2. Distance between two nodes
        
    */
    
    Node* LCA(Node* root, int a, int b) {
        if(root==nullptr || root->data==a || root->data==b) return root;
        
        Node* lf = LCA(root->left, a, b);
        Node* rf = LCA(root->right, a, b);
        
        if(lf==nullptr) return rf;
        else if(rf==nullptr) return lf;
        else return root;
    }
    
    int dis(Node* root, int a) {
        if(root==nullptr) return -1;
        if(root->data==a) return 0;
        
        int lf = dis(root->left, a);
        int rf = dis(root->right, a);
        
        if(lf==-1 && rf==-1) return -1;
        else if(lf==-1) return 1+rf;
        else if(rf==-1) return 1+lf;
    }
    
    int findDist(Node* root, int a, int b) {
        Node* com = LCA(root, a, b);
        int pd = dis(com, a);
        int qd = dis(com, b);
        // cout<<com->data<<" "<<pd<<" "<<qd<<"\n";
        
        return pd+qd;
    }
};
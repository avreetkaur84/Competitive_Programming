// Question Link - https://www.geeksforgeeks.org/problems/burning-tree/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Definition for Binary Tree Node
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
    // Level Order Traversal -> Parent pointer
    unordered_map<Node*, Node*> parent_pointer(Node* root, int target, Node* &tar) {
        unordered_map<Node*, Node*> mp;
        queue<Node*> q;
        if(root) {
            q.push(root); mp[root]=NULL;
        }
        
        while(!q.empty()) {
            int n=q.size();
            for(int i=0; i<n; i++) {
                Node* node=q.front();
                if(node->data == target) tar=node;
                if(node->left) {
                    q.push(node->left); mp[node->left]=node;
                }
                if(node->right) {
                    q.push(node->right); mp[node->right]=node;
                }
                q.pop();
            }
        }
        
        return mp;
    }
  
    int minTime(Node* root, int target) {
        int time=-1; Node* tar;
        unordered_map<Node*, Node*> mp = parent_pointer(root, target, tar);
        set<Node*> st; queue<Node*> q;
        q.push(tar); st.insert(tar);
        
        while(!q.empty()) {
            int n=q.size(); 
            for(int i=0; i<n; i++) {
                Node* node=q.front(); 
                if(st.find(node->left)==st.end() && node->left) {
                    q.push(node->left); st.insert(node->left);
                }
                if(st.find(node->right)==st.end() && node->right) {
                    q.push(node->right); st.insert(node->right);
                }
                if(st.find(mp[node])==st.end() && mp[node]!=NULL) {
                    q.push(mp[node]); st.insert(mp[node]);
                }
                q.pop();
            }
            
            time++;
            
        }
        
        return time;
        
    }
};

// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    This question just fucked my mind, or more precisely, I fucked my mind because of my own mistakes. 
    1. I spent around 2 hours on solving the question in wrong way, means I misunderstood meaning of top view question, and just after reading the question and seeing the examples I created my own version of top view, which is the bggest mistake I did. In previous question also this was my mistake.
    Lesson - spending extra 5 minutes to understand the question is better than spending 2 hours to solve the questrion in wrong was and then question your existence and your brain!!! So, engrain this in your mind.
    2. After understanding the question correctly, solved it in 20 minutes!!!! -> so, need to learn from my mistakes.
*/


struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        if(root==nullptr) return {};
        vector<pair<int, int>> arr; set<int> st;
        queue<pair<Node*, pair<int, int>>> q;
        
        q.push({root, {0, 0}}); 
        
        while(!q.empty()) {
            Node* node=q.front().first;
            pair<int, int> p = q.front().second;
            
            if(st.find(p.second)==st.end()) {
                st.insert(p.second); arr.push_back({p.second, node->data});
            }
            
            if(node->left) {
                q.push({node->left, {p.first+1, p.second-1}});
            } 
            if(node->right) {
                q.push({node->right, {p.first+1, p.second+1}});
            }
            
            q.pop();
        }
        
        sort(arr.begin(), arr.end());
        vector<int> res;
        for(int i=0; i<arr.size(); i++) res.push_back(arr[i].second);
        
        return res;
    }
};
// Question Link - https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    This question is really amazing, I leant a lot.
    Things I learnt:
    1. I was asked to traverse the boundary elements of teh tree, first left side then leaft and at last right. Therefore, like I started by thinking of one single technique that can do all these, but eventually I hit the road block, then I look at hint. From there I got the idea of breaking the problem and solving it into three parts. And, coding three parts separately was pretty easy then having one technique.
    So, LESSON LEARNT: Try to think of problem in small blocks, don't always think of a technque first, try to reate the intution of what the problem is askinga nd how you can solve it in most basic way.
    2. I didn't read the quesion in deatil, like I just grasped the main point, I haev to traverse the left nodes all, but question was about choosing the left most leaf node, not always left, therefore, first solution that I created failed some test cases. Therefore, first study the question in detail, ask teh doubts and then proceed with solving it.
    3. I think I can optimise this problem further by removing set, as I had to add set because I was getting duplicates in leaf node adn last node of lefta nd right side, so I can do better next time.
*/


// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
    void addLeftNode(Node* node, vector<int> &ln, set<Node*> &st) {
        if(node==nullptr) return;
        
        ln.push_back(node->data); st.insert(node);
        if(node->left==nullptr) addLeftNode(node->right, ln, st);
        addLeftNode(node->left, ln, st);
    }
    
    void addLeafNode(Node* node, vector<int> &ln, set<Node*> &st) {
        if(node==nullptr) return;
        
        if(node->left==nullptr && node->right==nullptr) {
            if(st.find(node)==st.end()) {
                ln.push_back(node->data);   st.insert(node);
            }
        }
        addLeafNode(node->left, ln, st);
        addLeafNode(node->right, ln, st);
    }
    
    void addRightNode(Node* node, vector<int> &rn, set<Node*> &st) {
        if(node==nullptr) return;
        
        if(st.find(node)==st.end()) {
            rn.push_back(node->data); st.insert(node);
        }
        
        if(node->right==nullptr) addRightNode(node->left, rn, st);
        addRightNode(node->right, rn, st);
        // better way to avoid any problems:
        // if (node->right)    addRightNode(node->right, rn, st);
        // else    addRightNode(node->left, rn, st);

    }
  
    vector<int> boundaryTraversal(Node *root) {
        vector<int> res; set<Node* > st; 
        if(root==nullptr) return res;
        res.push_back(root->data); st.insert(root);
        
        if(root->left!=nullptr) addLeftNode(root->left, res, st);
        
        addLeafNode(root, res, st);
        
        vector<int> rt;
        if(root->right!=nullptr) {
            addRightNode(root->right, rt, st);
            reverse(rt.begin(), rt.end());
            res.insert(res.end(), rt.begin(), rt.end());
        }
        
        return res;
    }
};


// Question Link - https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    I got introduced with string stream, which is I guess super weapon. This question made me question my own existence!!!
*/

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Codec {
public:
    // int numToString(string data, int &i) {
    //     if (i >= data.size()) return 10001;
    //     if(i<data.size() && data[i]==',') i++;

    //     if(i<data.size() && data[i]=='N') {
    //         i++; 
    //         if(i<data.size() && data[i]==',') i++;
    //         return 10001;
    //     }

    //     string num="";
    //     while(i<data.size() && data[i]!=',') {
    //         num+=data[i]; i++;
    //     }
    //     if(i<data.size() && data[i]==',') i++;

    //     if (num == "") return 10001;
    //     return stoi(num);
    // }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr) return "";
        string res=""; queue<TreeNode*> q; 
        if(root) q.push(root);

        while(!q.empty()) {
            int n=q.size(); 
            for(int i=0; i<n; i++) {
                TreeNode* node = q.front(); 

                if(node==NULL) {
                    res+='N,'; 
                } else {
                    res+=to_string(node->val)+','; 
                    q.push(node->left); 
                    q.push(node->right);
                }

                q.pop();
            }
        }
        // cout<<"len: "<<res.size()<<"  "<<res<<endl;

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return nullptr;
        stringstream s(data);
        queue<TreeNode*> q;

        string val;
        getline(s, val, ',');
        
        TreeNode* root = new TreeNode(stoi(val)); q.push(root);
        
        while(!q.empty()) {
            TreeNode* node = q.front();
            
            getline(s, val, ',');
            if(!val.empty() && val!="N") {
                TreeNode* leftNode = new TreeNode(stoi(val)); 
                node->left=leftNode;
                q.push(leftNode);
            }

            getline(s, val, ',');
            if(!val.empty() && val!="N") {
                TreeNode* rightNode = new TreeNode(stoi(val)); 
                node->right=rightNode;
                q.push(rightNode);
            }
            q.pop();
        }

        return root;
        
    }
};
// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class TreeNode
{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void output(vector<int> arr) {
    for(int i : arr) cout<<i<<" ";
    cout<<endl;
}

void preInPostTraversal(TreeNode* root) {
    vector<int> pre; vector<int> in; vector<int> post;
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});

    while(!st.empty()) {
        pair<TreeNode*, int> helper = st.top();
        if(helper.second==1) {
            st.pop();
            pre.push_back(helper.first->val);
            helper.second++;
            st.push(helper);
            if(helper.first->left!=nullptr) st.push({helper.first->left, 1});
        } else if(helper.second==2) {
            st.pop();
            in.push_back(helper.first->val);
            helper.second++;
            st.push(helper);
            if(helper.first->right!=nullptr) st.push({helper.first->right, 1});
        } else {
            st.pop();
            post.push_back(helper.first->val);
        }
    }

    output(pre);
    output(in);
    output(post);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    preInPostTraversal(root);
}
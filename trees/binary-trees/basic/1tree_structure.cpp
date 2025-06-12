// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node() {
            data=0;
            left=nullptr;
            right=nullptr;
        }

        Node(int Data) {
            data=Data;
            left=nullptr;
            right=nullptr;
        }
};

class BinaryTree {
    public:
        Node* root;

        Node* treeFormation(Node* root, vector<int> &arr) {

        }
};


int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(2);

    root->left->left = new Node(4);
    root->left->right = new Node(1);

    return 0;
}
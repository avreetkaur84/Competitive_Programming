// Question Link: https://leetcode.com/problems/implement-trie-prefix-tree/description/?envType=problem-list-v2&envId=trie

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    bool isLeaf=false;
    TrieNode* ch[26] = {nullptr};
};

class Trie : public TrieNode {
TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for(auto it : word) {
            if(!temp->ch[it-'a']) temp->ch[it-'a'] = new TrieNode();
            temp = temp->ch[it-'a'];
        }
        temp->isLeaf=true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for(auto it : word) {
            if(!temp->ch[it-'a']) return false;
            temp = temp->ch[it-'a'];
        }
        return temp->isLeaf;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(auto it : prefix) {
            if(!temp->ch[it-'a']) return false;
            temp = temp->ch[it-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
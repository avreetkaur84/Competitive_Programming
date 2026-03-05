// Question Link: https://leetcode.com/problems/longest-common-prefix/description/?envType=problem-list-v2&envId=trie

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    bool isLeaf = false;
    int childCnt = 0;
    TrieNode* ch[26] = {nullptr};
};

class Trie : public TrieNode {
    TrieNode* root;
public: 
    Trie(vector<string>& strs) {
        root = new TrieNode();
        buildTree(strs);
    }

    void buildTree(vector<string>& strs) {
        for(auto it : strs) {
            insert(it);
        }
    }

    void insert(string word) {
        TrieNode* temp = root;
        for(auto it : word) {
            if(!temp->ch[it-'a'])  {
                temp->ch[it-'a'] = new TrieNode();
                temp->childCnt+=1;
            }
            temp = temp->ch[it-'a'];
        }
        temp->isLeaf = true;
    }

    string prefix(string word) {
        string res="";
        TrieNode* temp = root;
        for(auto it : word) {
            if(temp->childCnt>1) return res;
            temp=temp->ch[it-'a'];
            res+=it;
        }
        return res;
    }
};

class Solution : public TrieNode {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string w=strs[0];
        for(auto it : strs) {
            if(w.size()>it.size()) w=it;
        }

        Trie* t = new Trie(strs);
        return t->prefix(w);
    }
};
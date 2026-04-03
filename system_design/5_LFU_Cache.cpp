// Question Link - https://leetcode.com/problems/lfu-cache/description/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key, val;
    Node* prev=nullptr;
    Node* next=nullptr;

    Node(int key, int val)  {
        this->key = key;
        this->val = val;
    }
};

class LinkedList {
    Node* head=nullptr;
    Node* tail=nullptr;
    int sz=0;
public:
    LinkedList() {
        head=new Node(-1, -1);
        tail=new Node(-1, -1);
        head->next=tail;
        tail->prev=head;
    }

    Node* insert(Node* newNode) {
        Node* temp = head->next;
        head->next=newNode;
        temp->prev=newNode;
        newNode->prev=head;
        newNode->next=temp;
        sz++;
        return newNode;
    }

    int delete_tail() {
        Node* node = tail->prev;
        node->prev->next=tail;
        tail->prev=node->prev;
        node->prev=nullptr; 
        node->next=nullptr;
        int key = node->key;
        sz--;
        delete node;
        return key;
    }

    void delete_node(Node* node) {
        Node* before = node->prev;
        Node* after = node->next;
        before->next=after;
        after->prev=before;
        node->prev=nullptr;
        node->next=nullptr;
        sz--;
    }

    bool is_empty() {
        if(sz>0) return false;
        return true;
    }

};

class LFUCache {
public:
    int cap;
    unordered_map<int, Node*> key_node; 
    unordered_map<int, int> key_freq;
    map<int, LinkedList*> freq_list;

    LFUCache(int capacity) {
        cap=capacity;
    }

    void update_freq(int key) {
        // freq change: remove node from cur freq, insert in +1 freq
        int cur_freq = key_freq[key];
        if(!freq_list.count(cur_freq+1)) {
            LinkedList* ll = new LinkedList();
            freq_list[cur_freq+1]=ll;
        }
        freq_list[cur_freq]->delete_node(key_node[key]);
        freq_list[cur_freq+1]->insert(key_node[key]);
        key_freq[key]=cur_freq+1;
    }
    
    int get(int key) {
        if(!key_node.count(key)) return -1;
        update_freq(key);
        return key_node[key]->val;
    }
    
    void put(int key, int value) {
        if(key_node.count(key)) {
            key_node[key]->val=value;
            update_freq(key);
            return;
        } 

        if(key_node.size()>=cap) {
            int x=0;
            cout<<key_node.size()<<" "<<key<<"\n";
            for(auto it : freq_list) {
                int u = it.first;
                LinkedList* v = it.second;
                if(v->is_empty()) continue;
                int key = v->delete_tail();
                key_node.erase(key);
                key_freq.erase(key);
                x=u; break;
            }
        }

        Node* newNode = new Node(key, value);
        if(!freq_list.count(1)) {
            LinkedList* ll = new LinkedList();
            freq_list[1]=ll;
        }

        freq_list[1]->insert(newNode);
        key_node[key]=newNode;
        key_freq[key]=1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
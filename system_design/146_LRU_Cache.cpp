// Question Link - https://leetcode.com/problems/lru-cache/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Optimised and accpeted version: Doubly linked list and hashmap
class Node {
public:
    int key, val;
    Node* prev=nullptr; 
    Node* next=nullptr;
    Node() {
        key=-1;
        val=-1;
    }

    Node(int key, int val) {
        this->key = key;
        this->val = val;
    }
};

class LinkedList : public Node {
    Node* head;
    Node* tail;
public:
    LinkedList() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    // always at head
    void insert(Node* newNode) {
        newNode->prev=head;
        newNode->next=head->next;
        head->next=newNode;
        newNode->next->prev=newNode;
    }

    // delete at tail when size full
    int deleteAtTail() {
        Node* temp = tail->prev;
        int key=temp->key;
        tail->prev=temp->prev;
        temp->prev->next=tail;
        delete temp;
        return key;
    }

    Node* deleteInBetween(Node* temp) {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        temp->next=nullptr;
        temp->prev=nullptr;
        return temp;
    }

    void getNode(Node* cur) {
        deleteInBetween(cur);
        insert(cur);
    }

};

class LRUCache : public LinkedList {
public:
    unordered_map<int, Node*> mp;
    int cap;
    LinkedList l;

    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        l.getNode(mp[key]);
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        Node* temp;
        if(mp.count(key)) {
            temp = l.deleteInBetween(mp[key]);
            temp->key=key;
            temp->val=value;
        } else {
            temp = new Node(key, value);
        }
        l.insert(temp);
        mp[key]=temp;

        if(mp.size()>cap) {
            int delKey = l.deleteAtTail();
            mp.erase(delKey);
        }
    }
};


// Brute
class LRUCache {
public:
    unordered_map<int, int> key_val;
    unordered_map<int, int> key_cnt;
    set<pair<int, int>> st;  // {cnt, key}
    int cap, cnt;

    LRUCache(int capacity) {
        cap=capacity;
        cnt=0;
    }
    
    int get(int key) {
        cnt++;
        if(key_val.count(key)) {
            st.erase({key_cnt[key], key});
            key_cnt[key]=cnt;
            st.insert({key_cnt[key], key});
            return key_val[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        cnt++;
        if(key_val.count(key)) {
            st.erase({key_cnt[key], key});
        }
        key_cnt[key]=cnt;
        st.insert({key_cnt[key], key});
        key_val[key]=value;

        if(st.size()>cap) {
            // key val
            pair<int, int> p = *st.begin();
            int x = p.first, y = p.second;
            key_val.erase(y);
            key_cnt.erase(y);
            st.erase({x, y});
        }
    }
};

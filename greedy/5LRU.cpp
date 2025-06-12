// Question Link - https://www.geeksforgeeks.org/problems/page-faults-in-lru5603/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// User function Template for C++

class Node {
    public:
        // int key;
        int val;
        Node* prev;
        Node* next;
        
        Node() {
            // key = -1; 
            val = -1;
            prev = nullptr; 
            next=nullptr;
        }
        
        Node(int Val) {
            val=Val;
            next=nullptr; prev=nullptr;
        }
};

class LinkedList {
  public:
    Node* head;
    Node* tail;
    
    LinkedList() {
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
    }
    
    void insertAtHead(Node* NewNode) {
        Node* curNode = head->next;
        head->next = NewNode;
        NewNode->prev = head;
        NewNode->next = curNode;
        curNode->prev = NewNode;
    }
    
    int deleteNode(Node* delNode) {
        Node* forNode = delNode->next;
        Node* backNode = delNode->prev;
        forNode->prev = backNode;
        backNode->next = forNode;
        delete delNode;
    }
    
    int deleteAtTail() {
        Node* delNode = tail->prev;
        Node* curNode = delNode->prev;
        tail->prev = curNode;
        curNode->next=tail;
        int x = delNode->val;
        delete delNode;
        
        return x;
    }
};

class Solution {
  public:
    int pageFaults(int N, int C, int pages[]) {
        int i=0, cnt=0;
        unordered_map<int, Node*> mp;
        LinkedList l;
        
        while(i<N) {
            if(mp.find(pages[i])==mp.end()) {
                // not found!!
                cnt++;
                if(mp.size()>=C) {
                    int x = l.deleteAtTail();
                    mp.erase(x);
                }
                
                Node* newNode = new Node(pages[i]);
                l.insertAtHead(newNode);
                mp.insert({pages[i], newNode});
            } else {
                l.deleteNode(mp[pages[i]]);
                Node* newNode = new Node(pages[i]);
                l.insertAtHead(newNode);
                mp[pages[i]]=newNode;
            }
            
            i++;
        }
        
        return cnt;
    }
};
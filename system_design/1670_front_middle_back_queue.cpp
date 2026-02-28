// Question Link: https://leetcode.com/problems/design-front-middle-back-queue/description/

#include <bits/stdc++.h>
using namespace std;

// AC: WITH TWO DEQUES
class FrontMiddleBackQueue {
public:
    /*
       we will use 2 deque for this,   
       Right can never have size greater than left
       middle will be left.back()
       while adding at middle, we have to add in front of middle, so we will put left.back() in right front and then add the middle in left back
       After adding -> left.size-right.size
       case 1: 0 or 1 -> do nothing
       case 2: -1     -> right front will be pushed to left back
    */
    
    deque<int> left, right;
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        left.push_front(val);
        updateQueue();
    }
    
    void pushMiddle(int val) {
        if(left.empty() && right.empty()) {
            left.push_back(val); return;
        } 
        if(left.size()>right.size()) {
            int mid = left.back();
            left.pop_back();
            left.push_back(val);
            left.push_back(mid);
        } else {
            left.push_back(val);
        }
        updateQueue();
    }
    
    void pushBack(int val) {
        right.push_back(val);
        updateQueue();
    }
    
    int popFront() {
        if(right.empty() && left.empty()) return -1;
        int val = left.front();
        left.pop_front();
        updateQueue();
        return val;
    }
    
    int popMiddle() {
        if(right.empty() && left.empty()) return -1;
        int val = left.back();
        left.pop_back();
        updateQueue();
        return val;
    }
    
    int popBack() {
        if(right.empty() && left.empty()) return -1;
        int val;
        if(right.empty()) {
            val = left.back();
            left.pop_back();
        } else {
            val = right.back();
            right.pop_back();
        }
        updateQueue();
        return val;
    }

    void updateQueue() {
        int x = left.size()-right.size();
        if(x==0 || x==1) return;
        if(x==-1) {
            left.push_back(right.front());
            right.pop_front();
        } else if(x==2) {
            right.push_front(left.back());
            left.pop_back();
        }
    }
};



// WA: NEED TO CORRECT THIS
class Node {
public:
    int val;
    Node* next=nullptr;
    Node* prev=nullptr;
    Node() {

    }

    Node(int data) {
        val=data;
    }
};

class FrontMiddleBackQueue : public Node {
private:
    Node* front;
    Node* middle;
    Node* back;
    int size;

public:
    /*
        - using doubly linked list
        - middle operation will be performed easily
        - three pointers: font, back, middle
        - during middle insertion: we will insert and pop from front always
    */

    FrontMiddleBackQueue() {
        front=nullptr;
        middle=nullptr;
        back=nullptr;
        size=0;
    }
    
    void pushFront(int val) {
        Node* newNode = new Node(val);
        size++;

        if(!front && !middle && !back) {
            front=newNode;
            middle=newNode;
            back=newNode;
        } else {
            newNode->next=front;
            front->prev=newNode;
            front=newNode;
            if(size&1) middle=middle->prev;
        }
    }
    
    void pushMiddle(int val) {
        Node* newNode = new Node(val);
        size++;

        if(!front && !middle && !back) {      // no node
            front=newNode;
            middle=newNode;
            back=newNode;
        } else if(!middle->prev) {            // one node
            newNode->next=middle;
            middle->prev=newNode;
            middle=newNode;
            front=newNode;
        } else {                             
            // more than one node -> middle back will never be nullptr, as in even cases middle is always the frontmost element according to instractions
            Node* prev_node = middle->prev;
            prev_node->next=newNode;
            newNode->prev=prev_node;
            newNode->next=middle;
            middle->prev=newNode;
            middle=newNode;
        }
    }
    
    void pushBack(int val) {
        Node* newNode = new Node(val);        
        size++;

        if(!front && !middle && !back) {
            front=newNode;
            middle=newNode;
            back=newNode;
        } else {
            back->next=newNode;
            newNode->prev=back;
            back=newNode;
            if(size%2==0) middle=middle->next;
        }
    }
    
    int popFront() {
        if(!front) return -1;
        size--; 
        int val = front->val;

        if(!front->next) {
            front=nullptr;
            middle=nullptr;
            back=nullptr;
        } else {
            Node* next_node = front->next;
            front=next_node;
            front->prev=nullptr;
            if(size&1 && middle->next!=nullptr) middle=middle->next;
        }

        return val;
    }
    
    int popMiddle() {
        if(!middle) return -1;
        size--;
        int val=middle->val;

        if(!middle->prev && !middle->next) {
            front=nullptr;
            middle=nullptr;
            back=nullptr;
        } else if(!middle->prev) {
            Node* next_node = middle->next;
            next_node->prev=nullptr;
            middle=next_node;
            front=next_node;
        } else {
            Node* prev_node = middle->prev;
            Node* next_node = middle->next;
            prev_node->next=next_node;
            next_node->prev=prev_node;
            middle=prev_node;
        }

        return val;
    }
    
    int popBack() {
        if(!back) return -1;
        size--;
        int val=back->val;

        if(!back->prev) {
            front=nullptr;
            middle=nullptr;
            back=nullptr;
        } else {
            Node* prev_node=back->prev;
            prev_node->next=nullptr;
            back=prev_node;
            if(size&1 && back->prev!=nullptr) middle=middle->prev;
        }

        return val;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
// Question Link - https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

/*
    My first intution -
    1. traberse teh while linked list, store it in string, then convert that string to number and then add 1 to the number, then again convert it into string. Then, again traverse th ell and compare each node with the number, and if it does not match then chnage the node number.
    Problem: contraint was 10^5 -> so, it gave out of range error.

    Now, second ntution - got hint from gpt -
    1. Reverse the linked list. Traverse the linked list and add 1. Then again reverse the linked list and return head.
*/

class Solution {
  public:
    Node* reverseLL(Node* head) {
        if(head==nullptr) return nullptr;
        
        Node* cur = head;
        Node* prev=nullptr;
        Node* temp;
        
        while(cur!=nullptr) {
            temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
        
        return prev;
    }
  
    Node* addOne(Node* head) {
        Node* revHead = reverseLL(head);
        
        // traverse and add +!
        Node* mover = revHead;
        bool flag=true;
        
        while(mover!=nullptr) {
            if(flag) {
                if(mover->data==9) {
                    mover->data=0;
                    if(mover->next==nullptr) {
                        mover->next = new Node(1);
                        flag=false;
                    }
                }
                else {
                    mover->data+=1; flag=false;
                }
            }
            
            mover=mover->next;
        }
        
        head = reverseLL(revHead);
        return head;
    }
};


// GOT OUT OF RANGE ERROR
class Solution {
  public:
    Node* addOne(Node* head) {
        string n="";
        Node* mover = head;
        
        while(mover!=nullptr) {
            n+=char(mover->data+'0');
            mover=mover->next;
        }
        
        long long num=stoll(n);
        num+=1;
        n = to_string(num);
        
        int i=0; mover=head;
        
        while(mover!=nullptr) {
            if(mover->data!=n[i]-'0') mover->data=n[i]-'0';
            
            if(n[n.size()-1]=='0' && i==n.size()-2) {
                mover->next = new Node(0);
            }
            
            mover=mover->next; i++;
        }
        
        
        
        return head;
    }
};
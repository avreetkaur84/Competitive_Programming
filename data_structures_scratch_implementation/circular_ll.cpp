#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        data = 0;
        next = nullptr;
    }

    Node(int Data) {
        data = Data;
        next = nullptr;
    }

    Node(int Data, Node* Next) {
        data = Data;
        next = Next;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() {
        head=nullptr;
        tail=nullptr;
    }

    void arr2LinkedList(vector<int> arr) {
        if(arr.size()==0) return;
        Node* firstNode = new Node(arr[0]);
        head = firstNode;

        Node* mover = head;
        for(int i=1; i<arr.size(); i++) {
            Node* newNode = new Node(arr[i]);
            mover->next = newNode;            
            mover = newNode;
            tail=mover;
        }
        tail->next = head;
    }

    void display() {
        Node* mover=head;
        while(mover->next!=head) {
            cout<<mover->data<<" ";
            mover=mover->next;
        }
        cout<<endl;
    }

    void insertAtStart(int val) {
        Node* newNode = new Node(val);
        if(head==nullptr) {
            head = newNode;
            tail = newNode;
        }

        newNode->next = head;
        head = newNode;
        tail->next = head;
    }

    int totalOccurence(int val) {
        Node* mover=head; int cnt;
        while(mover->next!=head) {
            if(mover->data==val) cnt++;
            mover = mover->next;
        }

        return cnt;
    }

    void deleteAtStart() {
        head = head->next;
        tail->next = head;
    }

    void deleteAtAny(int val, int x, int cnt) {
        if(x>cnt) {
            cout<<"Given occurence releteion count should be in range"<<endl; return;
        }

        Node* mover = head;
        while(mover->data==val && x>0) {
            deleteAtStart(); x--;
        }

        mover = head;
        while(mover->next!=head && x>0) {
            if(mover->next->data==val) {
                Node* temp = mover->next;
                mover->next=temp->next;
                x--;
            }
        }        

    }
};

int main() {
    vector<int> arr = {2, 5, 6, 4, 4, 7, 2, 2, 8};
    LinkedList obj;
    obj.arr2LinkedList(arr);
    obj.insertAtStart(2);
    obj.display();

    obj.insertAtStart(9);
    obj.display();

    int cnt = obj.totalOccurence(2);
    obj.deleteAtAny(2, 3, cnt);
    obj.display();

    cout<<obj.tail->data<<endl;

    cnt = obj.totalOccurence(4);
    obj.deleteAtAny(4, 3, cnt);
    obj.display();
}
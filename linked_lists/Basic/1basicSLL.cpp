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

        LinkedList() {
            head = nullptr;
        }

        Node* arr2LL(vector<int> &arr) {
            if(arr.empty()) return nullptr;

            head = new Node(arr[0]);
            Node* mover = head;

            for(int i=1; i<arr.size(); i++) {
                Node* newNode = new Node(arr[i]);
                mover->next = newNode;
                mover = newNode;
            }

            return head;
        }

        void printLL(Node* head) {
            Node* mover = head;
            cout<<"Linked List: ";
            while(mover!=nullptr) {
                cout<<mover->data<<"    ";
                mover=mover->next;
            }
            cout<<endl;
        }

        Node* insertAtStart(Node* head, int data) {
            Node* newNode = new Node(data);

            newNode->next = head;
            return newNode;
        }

        Node* insertAtLast(Node* head, int data) {
            Node* newNode = new Node(data);
            if(head==nullptr) return newNode;

            Node* mover = head;

            while(mover->next!=nullptr) {
                mover = mover->next;
            }

            mover->next = newNode;
            return head;
        }

        Node* insertAtIndex(Node* head, int data, int idx) {
            if(idx==0) return insertAtStart(head, data);

            Node* newNode = new Node(data);
            Node* mover  = head;
            int cnt=1;

            while(mover!=nullptr && cnt<idx) {
                mover = mover->next; cnt++;
            }

            if(mover==nullptr) {
                cout<<"Index out of bound"<<endl;
                delete newNode;
                return head;
            }

            Node* temp = mover->next;
            mover->next = newNode;
            newNode->next = temp;

            return head;
        }

        Node* deleteAtStart(Node* head) {
            if(head==nullptr) return nullptr;
            Node* mover = head->next;
            delete head;
            return mover;
        }

        Node* deleteAtLast(Node* head) {
            if(head==nullptr) return nullptr;
            if(head->next==nullptr) {
                delete head; 
                return nullptr;
            }

            Node* mover = head;
            while(mover->next->next!=nullptr) {
                mover=mover->next;
            }
            
            delete(mover->next);
            mover->next=nullptr;

            return head;
        }

        Node* deleteAtIndex(Node* head, int idx) {
            if(head==nullptr) return nullptr;
            if(idx==0) return deleteAtStart(head);

            Node* mover = head;
            int i=1;

            while(mover->next!=nullptr && i<idx) {
                mover=mover->next;
                i++;
            }

            if(mover->next==nullptr) {
                cout<<"Index out of bounds"<<endl;
                return head;
            }

            Node* temp = mover->next;
            mover->next = temp->next;
            delete(temp);
            return head;
        }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    LinkedList l;
    Node* head = l.arr2LL(arr);
    l.printLL(head);

    head = l.insertAtStart(head, 0);
    l.printLL(head);
    head = l.insertAtLast(head, 9);
    l.printLL(head);
    head = l.insertAtIndex(head, -1, 3);
    l.printLL(head);

    head = l.deleteAtStart(head);
    l.printLL(head);
    head = l.deleteAtLast(head);
    l.printLL(head);
    head = l.deleteAtIndex(head, 3);
    l.printLL(head);

    return 0;
}
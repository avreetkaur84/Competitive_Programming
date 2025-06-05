// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* prev;

    Node() {
        data = 0;
        next = nullptr;
        prev = nullptr;
    }

    Node(int Data) {
        data = Data;
        next = nullptr;
        prev = nullptr;
    }

    Node(int Data, Node* Next, Node* Prev) {
        data = Data;
        next = Next;
        prev = Prev;
    }
};

class LinkedList {
    public:
        Node* head;
        Node* tail;

        LinkedList() {
            head = nullptr;
            tail = nullptr;
        }

        Node* arr2LL(vector<int> arr) {
            if(arr.empty()) return nullptr;

            head = new Node(arr[0]);
            Node* mover = head;

            for(int i=1; i<arr.size(); i++) {
                Node* newNode = new Node(arr[i], nullptr, mover);
                mover->next = newNode;
                mover = newNode;
            }
            
            tail=mover;
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

        void printReverseLL(Node* head) {
            Node* mover = tail;
            cout<<"Linked List: ";

            while(mover!=nullptr) {
                cout<<mover->data<<"    ";
                mover = mover->prev;
            }

            cout<<endl;
        }

        ~LinkedList() {
            Node* temp = head;
            while (temp != nullptr) {
                Node* next = temp->next;
                delete temp;
                temp = next;
            }
            head = nullptr;
            tail = nullptr; 
            cout<<"Cleaned up Memory"<<endl;
        }

};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    LinkedList l;
    Node* head = l.arr2LL(arr);
    l.printLL(head);    
    l.printReverseLL(head);

    return 0;
}
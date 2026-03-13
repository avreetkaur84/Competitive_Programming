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
            
            tail = mover;
            return head;        
        }

        void printLL(Node* head) {
            Node* mover = head;
            cout << "Linked List: ";
            while(mover != nullptr) {
                cout << mover->data << "    ";
                mover = mover->next;
            }
            cout << endl;
        }

        Node* insertAtStart(Node* head, int data) {
            Node* newNode = new Node(data);
            newNode->next = head;
            if (head != nullptr) head->prev = newNode;
            head = newNode;
            if (tail == nullptr) tail = head; 
            return head;
        }

        Node* insertAtEnd(Node* head, int data) {
            Node* newNode = new Node(data);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
                return head;
            }

            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            return head;
        }

        Node* insertAtIndex(Node* head, int data, int idx) {
            if (idx == 0) return insertAtStart(head, data);

            Node* mover = head;
            int cnt = 1;

            while (mover != nullptr && cnt < idx) {
                mover = mover->next;
                cnt++;
            }

            if (mover == nullptr) {
                cout << "Index out of bounds" << endl;
                return head;
            }

            Node* newNode = new Node(data);
            Node* temp = mover->next;

            newNode->next = temp;
            newNode->prev = mover;
            mover->next = newNode;
            if (temp != nullptr) temp->prev = newNode;
            if (newNode->next == nullptr) tail = newNode; // Update tail
            return head;
        }

        Node* deleteAtStart(Node* head) {
            if (head == nullptr) return nullptr;

            Node* temp = head->next;
            delete head;
            if (temp != nullptr) temp->prev = nullptr;
            else tail = nullptr;
            return temp;
        }

        Node* deleteAtEnd(Node* head) {
            if (tail == nullptr) return nullptr;

            if (tail == head) {
                delete tail;
                head = nullptr;
                tail = nullptr;
                return head;
            }

            Node* newTail = tail->prev;
            delete tail;
            newTail->next = nullptr;
            tail = newTail;
            return head;
        }

        Node* deleteAtIndex(Node* head, int idx) {
            if (head == nullptr) return nullptr;
            if (idx == 0) return deleteAtStart(head);

            Node* mover = head;
            int cnt = 1;

            while (mover->next != nullptr && cnt < idx) {
                mover = mover->next;
                cnt++;
            }

            if (mover->next == nullptr) {
                cout << "Index out of bounds" << endl;
                return head;
            }

            Node* temp = mover->next;
            mover->next = temp->next;
            if (temp->next != nullptr) temp->next->prev = mover;
            else tail = mover; 
            delete temp;
            return head;
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
            cout << "Cleaned up Memory" << endl;
        }

};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    LinkedList l;
    Node* head = l.arr2LL(arr);

    cout << "Original: ";
    l.printLL(head);

    head = l.insertAtStart(head, 0);
    l.printLL(head);

    head = l.insertAtEnd(head, 6);
    l.printLL(head);

    head = l.insertAtIndex(head, -1, 3);
    l.printLL(head);

    head = l.deleteAtStart(head);
    l.printLL(head);

    head = l.deleteAtEnd(head);
    l.printLL(head);

    head = l.deleteAtIndex(head, 2);
    l.printLL(head);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class MyQueue {
private:
    Node* front;
    Node* rear;

public:
    MyQueue() {
        front = NULL;
        rear = NULL;
    }

    ~MyQueue() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow. Cannot dequeue." << endl;
            return;
        }
        cout << "Dequeued: " << front->data << endl;
        Node* temp = front;
        front = front->next;
        if (front == NULL) rear = NULL; 
        delete temp;
    }

    void peek() {
        if (front == NULL) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Front element: " << front->data << endl;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue: ";
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    MyQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.peek();

    q.dequeue();
    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.display();

    return 0;
}
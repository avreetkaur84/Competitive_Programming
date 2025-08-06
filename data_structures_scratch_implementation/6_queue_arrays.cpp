#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int size;

public:
    MyQueue(int cap) {
        capacity = cap;
        front = 0;
        rear = -1;
        size = 0;
        arr = new int[capacity];
    }

    ~MyQueue() {
        delete[] arr;
    }

    void enqueue(int value) {
        if (size == capacity) {
            cout << "Queue Overflow. Cannot enqueue " << value << "." << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    void dequeue() {
        if (size == 0) {
            cout << "Queue Underflow. Cannot dequeue." << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front = (front + 1) % capacity;
        size--;
    }

    void peek() {
        if (size == 0) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void display() {
        if (size == 0) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    MyQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.peek();

    q.dequeue();
    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // should show overflow
    q.display();

    return 0;
}
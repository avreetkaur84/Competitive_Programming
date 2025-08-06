#include <bits/stdc++.h>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int cap) {
        capacity = cap;
        front = 0;
        rear = -1;
        size = 0;
        arr = new int[capacity];
    }

    ~CircularQueue() {
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
    CircularQueue cq(5);

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.display();

    cq.peek();

    cq.dequeue();
    cq.display();

    cq.enqueue(40);
    cq.enqueue(50);
    cq.enqueue(60);
    cq.display();

    cq.enqueue(70); // Overflow

    return 0;
}
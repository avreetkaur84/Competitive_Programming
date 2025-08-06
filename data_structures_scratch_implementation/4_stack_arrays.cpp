#include <bits/stdc++.h>
using namespace std;

class MyStack {
private:
    int* arr;
    int capacity;
    int top;

public:
    MyStack(int cap) {
        capacity = cap;
        top = -1;
        arr = new int[capacity];
    }

    ~MyStack() {
        delete[] arr;
    }

    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack Overflow. Cannot push " << value << "." << endl;
            return;
        }
        arr[++top] = value;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow. Cannot pop." << endl;
            return;
        }
        cout << "Popped: " << arr[top--] << endl;
    }

    void peek() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MyStack st(5);

    st.push(10);
    st.push(20);
    st.push(30);
    st.display();

    st.peek();

    st.pop();
    st.display();

    st.push(40);
    st.push(50);
    st.push(60); 
    st.display();

    return 0;
}
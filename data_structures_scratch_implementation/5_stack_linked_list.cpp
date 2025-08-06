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

class MyStack {
private:
    Node* top;

public:
    MyStack() {
        top = NULL;
    }

    ~MyStack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow. Cannot pop." << endl;
            return;
        }
        cout << "Popped: " << top->data << endl;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void peek() {
        if (top == NULL) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Top element: " << top->data << endl;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void display() {
        if (top == NULL) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack: ";
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.display();

    st.peek();

    st.pop();
    st.display();

    st.push(40);
    st.push(50);
    st.display();

    return 0;
}

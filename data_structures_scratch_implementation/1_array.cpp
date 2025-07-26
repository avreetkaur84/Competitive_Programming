#include <bits/stdc++.h>
using namespace std;

class MyArray {
private:
    int* arr;
    int capacity;
    int size;

public:
    MyArray(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    ~MyArray() {
        delete[] arr;
    }

    void insertEnd(int value) {
        if (size == capacity) {
            cout << "Array is full. Cannot insert." << endl;
            return;
        }
        arr[size++] = value;
    }

    void insertAtIndex(int index, int value) {
        if (size == capacity) {
            cout << "Array is full. Cannot insert." << endl;
            return;
        }
        if (index < 0 || index > size) {
            cout << "Invalid index." << endl;
            return;
        }
        for (int i = size - 1; i >= index; i--) {
            arr[i + 1] = arr[i];
        }
        arr[index] = value;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index." << endl;
            return;
        }
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void deleteByValue(int value) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            cout << "Value not found in array." << endl;
            return;
        }
        deleteAtIndex(index);
    }

    void display() {
        cout << "Array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MyArray myArr(10);

    myArr.insertEnd(5);
    myArr.insertEnd(10);
    myArr.insertEnd(15);
    myArr.display();

    myArr.insertAtIndex(1, 7);
    myArr.display();

    myArr.deleteAtIndex(2);
    myArr.display();

    myArr.deleteByValue(7);
    myArr.display();

    return 0;
}

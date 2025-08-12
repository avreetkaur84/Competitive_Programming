#include <bits/stdc++.h>
using namespace std;
#define PRIORITIES 3
#define SIZE 5

class CircularPriorityQueue2D {
    int arr[PRIORITIES][SIZE];
    int front[PRIORITIES];
    int rear[PRIORITIES];

public:
    CircularPriorityQueue2D() {
        for (int i = 0; i < PRIORITIES; i++) {
            front[i] = -1;
            rear[i] = -1;
        }
    }

    bool isFull(int p) {
        return ( (rear[p] + 1) % SIZE == front[p] );
    }

    bool isEmpty(int p) {
        return (front[p] == -1);
    }

    void enqueue(int p, int value) {
        if (p < 0 || p >= PRIORITIES) {
            cout << "Invalid priority!\n";
            return;
        }

        if (isFull(p)) {
            cout << "Priority " << p << " queue is FULL!\n";
            return;
        }
        
        if (isEmpty(p)) {
            front[p] = rear[p] = 0;
        } else {
            rear[p] = (rear[p] + 1) % SIZE;
        }
        arr[p][rear[p]] = value;
        cout << "Inserted " << value << " at priority " << p << endl;
    }

    void dequeue() {
        for (int p = 0; p < PRIORITIES; p++) {
            if (!isEmpty(p)) {
                cout << "Removed " << arr[p][front[p]] << " from priority " << p << endl;
                if (front[p] == rear[p]) {
                    front[p] = rear[p] = -1;
                } else {
                    front[p] = (front[p] + 1) % SIZE;
                }
                return;
            }
        }
        cout << "All queues are EMPTY!\n";
    }

    void display() {
        for (int p = 0; p < PRIORITIES; p++) {
            cout << "Priority " << p << ": ";
            if (isEmpty(p)) {
                cout << "EMPTY";
            } else {
                int i = front[p];
                while (true) {
                    cout << arr[p][i] << " ";
                    if (i == rear[p]) break;
                    i = (i + 1) % SIZE;
                }
            }
            cout << endl;
        }
        cout<<endl;
    }
};

int main() {
    CircularPriorityQueue2D pq;

    pq.enqueue(0, 10);
    pq.enqueue(1, 50);
    pq.enqueue(0, 20);
    pq.enqueue(2, 100);
    pq.enqueue(1, 60);
    pq.display();

    pq.dequeue();
    pq.dequeue();
    pq.display();

    pq.enqueue(0, 30); // will reuse freed space
    pq.enqueue(0, 40);
    pq.display();

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int *p = new int[5];
    int *m = p;   // keep base address safe

    // assign values
    for (int i = 0; i < 5; i++) {
        *p = i;
        p++;
    }

    // reset pointer
    p = m;

    // print values
    for (int i = 0; i < 5; i++) {
        cout << *p << " ";
        p++;
    }

    delete[] m; // free memory
    return 0;
}
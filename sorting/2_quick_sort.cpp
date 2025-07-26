#include <bits/stdc++.h>
using namespace std;

class QuickSort {
public:
    int partition(vector<int>& arr, int left, int right) {
        int pivot = arr[right];
        int i = left - 1;

        for (int j = left; j < right; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[right]);
        return i + 1;
    }

    void quickSort(vector<int>& arr, int left, int right) {
        if (left < right) {
            int pivotIndex = partition(arr, left, right);
            quickSort(arr, left, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, right);
        }
    }

    void printArray(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> arr = {78, 14, 47, 8, 3, 19, 81, 13, 1};
    QuickSort qs;

    cout << "Original array: ";
    qs.printArray(arr);

    qs.quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    qs.printArray(arr);

    return 0;
}

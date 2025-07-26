#include <bits/stdc++.h>
using namespace std;

class Matrix {
public:
    void multiply(vector<vector<int>>& A, vector<vector<int>>& B, int r1, int c1, int c2) {
        vector<vector<int>> result(r1, vector<int>(c2, 0));

        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                for (int k = 0; k < c1; k++) {
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        cout << "Resultant Matrix:" << endl;
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    vector<vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };

    vector<vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };

    int r1 = A.size();
    int c1 = A[0].size();
    int c2 = B[0].size();

    Matrix mat;
    mat.multiply(A, B, r1, c1, c2);

    return 0;
}

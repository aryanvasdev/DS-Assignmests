#include <iostream>

using namespace std;

int main() {
    int matrix[10][10], transpose[10][10];
    int r, c;

    cout << "Enter rows and columns of matrix: ";
    cin >> r >> c;

    cout << "Enter elements of the matrix:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "Transpose of the matrix:" << endl;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            cout << transpose[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
#include <iostream>

using namespace std;

int main() {
    int first[10][10], second[10][10], result[10][10];
    int r1, c1, r2, c2;

    cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;

    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Error: Column of first matrix is not equal to row of second." << endl;
        return 1;
    }

    cout << "Enter elements of matrix 1:" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cin >> first[i][j];
        }
    }

    cout << "Enter elements of matrix 2:" << endl;
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cin >> second[i][j];
        }
    }
    
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }

    cout << "Product of the two matrices is:" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << result[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
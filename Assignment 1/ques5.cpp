#include <iostream>

using namespace std;

int main() {
    int matrix[10][10];
    int r, c;

    cout << "Enter the number of rows: ";
    cin >> r;
    cout << "Enter the number of columns: ";
    cin >> c;

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "\nSum of rows:" << endl;
    for (int i = 0; i < r; i++) {
        int rowSum = 0;
        for (int j = 0; j < c; j++) {
            rowSum += matrix[i][j];
        }
        cout << "Sum of row " << i + 1 << ": " << rowSum << endl;
    }

    cout << "\nSum of columns:" << endl;
    for (int j = 0; j < c; j++) {
        int colSum = 0;
        for (int i = 0; i < r; i++) {
            colSum += matrix[i][j];
        }
        cout << "Sum of column " << j + 1 << ": " << colSum << endl;
    }

    return 0;
}
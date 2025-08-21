#include <iostream>
using namespace std;
#define MAX 100
void transposeSparse(int mat[][3], int transposed[][3])
{
int rows = mat[0][0]; 
int cols = mat[0][1]; 
int nonZero = mat[0][2];
transposed[0][0] = cols; 
transposed[0][1] = rows; 
transposed[0][2] = nonZero;
int k = 1;
    for (int i = 0; i < cols; i++) {
        for (int j = 1; j <= nonZero; j++) {
            if (mat[j][1] == i) {
                transposed[k][0] = mat[j][1];
                transposed[k][1] = mat[j][0];
                transposed[k][2] = mat[j][2];
                k++;
            } 
        } 
    } 
}

int main() {
int mat[MAX][3], transposed[MAX][3];
int rows, cols, nonZero;
cout << "Enter number of rows, columns, and non-zero elements: ";
cin >> rows >> cols >> nonZero;
mat[0][0] = rows;
mat[0][1] = cols;
mat[0][2] = nonZero;
cout << "Enter non-zero elements (row col value):\n";
for (int i = 1; i <= nonZero; i++)
cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
transposeSparse(mat, transposed);
cout << "Transposed Sparse Matrix:\n";
cout << "Row\tCol\tValue\n";
    for (int i = 1; i <= transposed[0][2]; i++) {
        cout << transposed[i][0] << "\t" << transposed[i][1] << "\t" << transposed[i][2] << "\n";
    }

    return 0;
}
#include <iostream>

using namespace std;

int main() {
    int arr[100];
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size;) {
            if (arr[j] == arr[i]) {
                for (int k = j; k < size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                size--;
            } else {
                j++;
            }
        }
    }

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
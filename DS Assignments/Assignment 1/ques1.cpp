#include <iostream>

using namespace std;

const int MAX_SIZE = 100;
int arr[MAX_SIZE];
int currentSize = 0;

void createArray() {
    cout << "Enter the number of elements: ";
    cin >> currentSize;
    if (currentSize > MAX_SIZE) {
        cout << "Error: Size cannot exceed " << MAX_SIZE << endl;
        currentSize = 0;
        return;
    }
    cout << "Enter " << currentSize << " elements:" << endl;
    for (int i = 0; i < currentSize; i++) {
        cin >> arr[i];
    }
    cout << "Array created successfully." << endl;
}

void displayArray() {
    if (currentSize == 0) {
        cout << "Array is empty." << endl;
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < currentSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement() {
    if (currentSize >= MAX_SIZE) {
        cout << "Array is full. Cannot insert." << endl;
        return;
    }
    int pos, value;
    cout << "Enter position to insert: ";
    cin >> pos;
    cout << "Enter value to insert: ";
    cin >> value;

    if (pos < 1 || pos > currentSize + 1) {
        cout << "Invalid position." << endl;
        return;
    }

    for (int i = currentSize; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;
    currentSize++;
    cout << "Element inserted." << endl;
}

void removeElement() {
    if (currentSize == 0) {
        cout << "Array is empty. Cannot delete." << endl;
        return;
    }
    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;

    if (pos < 1 || pos > currentSize) {
        cout << "Invalid position." << endl;
        return;
    }

    for (int i = pos - 1; i < currentSize - 1; i++) {
        arr[i] = arr[i + 1];
    }
    currentSize--;
    cout << "Element deleted." << endl;
}

void linearSearch() {
    if (currentSize == 0) {
        cout << "Array is empty." << endl;
        return;
    }
    int value;
    cout << "Enter element to search for: ";
    cin >> value;

    for (int i = 0; i < currentSize; i++) {
        if (arr[i] == value) {
            cout << "Element found at position " << i + 1 << endl;
            return;
        }
    }
    cout << "Element not found." << endl;
}

int main() {
    int choice;
    while (true) {
        cout << "\n--MENU--\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createArray(); break;
            case 2: displayArray(); break;
            case 3: insertElement(); break;
            case 4: removeElement(); break;
            case 5: linearSearch(); break;
            case 6: return 0;
            default: cout << "Invalid choice. Please try again." << endl;
        }
    }
}
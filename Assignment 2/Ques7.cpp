#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements in array: " << endl;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    int count=0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i<j && arr[i]>arr[j]) {
                count++;
            }
        }
    }
    cout << "Number of inversions: " << count << endl;
    return 0;
}

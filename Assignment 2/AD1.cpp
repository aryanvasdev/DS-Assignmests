#include<iostream>
#include<cmath>
using namespace std;
int main() {
    int k;
    cout << "Enter the value of k: ";
    cin >> k;
    int n;
    cout << "Enter number of elements in array: " << endl;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i < j && abs(arr[i] - arr[j])==k) {
                count++;
            }
        }
    }
    cout << "Number of pair : " << count << endl;
    return 0;
}
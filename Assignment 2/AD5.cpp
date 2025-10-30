#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter number of elements in array: " << endl;
    cin >> n;       
    int arr[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];  
    }
    for(int i=0;i<n;i++) {
        if(arr[i]==2){
            for(int j=i+1;j<n;j++) {
                int temp = arr[i];
                arr[j] = arr[i];
                arr[i] = temp;
                i++;
            }
        }
    }
    for(int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
}
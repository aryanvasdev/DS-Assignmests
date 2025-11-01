#include<iostream>
using namespace std;

int left(int i){
    return 2*i;;
}
int right(int i){
    return 2*i + 1;
}
void maxHeapify(int arr[], int n, int i){
    int l = left(i);
    int r = right(i);
    int largest = i;
    if(l<=n && arr[l]>arr[i]){
        largest = l;
    }
    if(r<=n && arr[r]>arr[largest]){
        largest = r;
    }
    if(largest != i){
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeaap(int arr[],int n){
    for(int i=n/2; i>=1; i--){
        maxHeapify(arr, n, i);
    }
}

void heapSort(int arr[], int n){
    buildMaxHeaap(arr, n);
    for(int i=n; i>=2; i--){
        swap(arr[1], arr[i]);
        maxHeapify(arr, i-1, 1);
    }
}
    
int main() {
    int n = 6;
    int arr[7] = {0, 4, 10, 3, 5, 1, 8};

    heapSort(arr, n);

    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
}
int find_missing_linear(const int arr[], int size) {
    long n = size + 1;
    for (int i = 0; i < size; ++i) {
        if (arr[i] != i + 1) return i + 1;
    }
    return n;
}
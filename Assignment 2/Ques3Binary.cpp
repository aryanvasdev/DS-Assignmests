int find_missing_binary(const int arr[], int size) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == mid + 1) left = mid + 1;
        else right = mid - 1;
    }
    return left + 1;
}
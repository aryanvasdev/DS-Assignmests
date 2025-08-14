int binary_search(const int arr[], int size, int val) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int mid_val = arr[mid];
        if (mid_val == val) return mid;
        else if (mid_val < val) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
int binary_search_recursive(int *arr, int left, int right, int x) {
    int mid;
    if (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == x) return x;
        if (arr[mid] > x) return binary_search_recursive(arr, left, mid - 1, x);
        else binary_search_recursive(arr, mid + 1, right, x);
    }
    return -1;
}

int binary_search(int *arr, int N, int x) {
    int left = 0, right = N - 1;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == x) return mid;
        else if (arr[mid] > x) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

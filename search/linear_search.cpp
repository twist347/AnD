int linear_search(int *arr, int N, int key) {
    for (int i = 0; i < N; ++i) {
        if (arr[i] == key) return i;
    }
    return -1;
}

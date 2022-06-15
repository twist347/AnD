void quick_sort_recursive(int *arr, int left, int right) {
    int i = left;
    int j = right;
    int pivot = arr[(left + right) / 2];
    int t;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            i++;
            j--;
        }
    }
    if (j > left) quick_sort_recursive(arr, left, j);
    if (i < right) quick_sort_recursive(arr, i, right);
}

void count_sort(int *arr, int N) {
    int max = -1;
    for (int i = 0; i < N; ++i) {
        if (arr[i] > max) max = arr[i];
    }
    int t[max + 1] = {0};
    
    for (int i = 0; i < N; ++i) {
        t[arr[i]]++;
    }
    int k = 0;
    for (int i = 0; i < max + 1; ++i) {
        for (int j = 0; j < t[i]; ++j) {
            arr[k] = i;
            ++k;
        }
    }
}

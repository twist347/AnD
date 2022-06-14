void selection_sort(int *arr, int N)
{
    for (int i = 0; i < N; ++i)
    {
        int idx = i;
        int current = arr[i];
        for (int j = i + 1; j < N; j++)
        {
            if (arr[j] < current)
            {
                idx = j;
                current = arr[j];
            }
        }
        arr[idx] = arr[i];
        arr[i] = current;
    }
}

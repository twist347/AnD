void bubble_sort(int *arr, int N)
{
    int n = N;
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (int i = 0; i < n - 1; ++i)
        {
            if (arr[i] > arr[i + 1])
            {
                int t = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = t;
                flag = true;
            }
        }
        n--;
    }
}

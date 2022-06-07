// arr1[p,q] (n1), arr2[p + 1, r] (n2)
// arr[p,q]
void merge(int *arr, int p, int q, int r)
{
    int n1 = q - p + 2;
    int n2 = r - q + 1;
    int left[n1];
    int right[n2];
    for (int i = 0; i < n1 - 1; ++i)
    {
        left[i] = arr[p + i];
    }

    for (int i = 0; i < n2 - 1; ++i)
    {
        right[i] = arr[q + i + 1];
    }

    left[n1 - 1] = INT32_MAX;
    right[n2 - 1] = INT32_MAX;

    int i = 0, j = 0;
    for (int k = p; k < r + 1; ++k)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
    }
}

void merge_sort(int *arr, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        merge_sort(arr, p, q);
        merge_sort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

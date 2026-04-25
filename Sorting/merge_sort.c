#include <stdio.h>

void merge_sort(int a[], int length);
void merge_sort_recursion(int a[], int l, int r);
void merge_sorted_arrays(int a[], int l, int m, int r);

int main()

{
    int arr[] = {0,1,2};
    int len = sizeof(arr) / sizeof(int);
    merge_sort(arr, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
    return 0;
}
void merge_sort(int a[], int length)
{
    merge_sort_recursion(a, 0, length - 1);
}
void merge_sort_recursion(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        merge_sort_recursion(a, l, m);
        merge_sort_recursion(a, m + 1, r);
        merge_sorted_arrays(a, l, m, r);
    }
}
void merge_sorted_arrays(int a[], int l, int m, int r)
{
    int left_len =( m - l) + 1;
    int right_len = r - m;
    int temp_left[left_len];
    int temp_right[right_len];

    int i, j, k;
    for (int i = 0; i < left_len; i++)
    {
        temp_left[i] = a[l + i];
    }
    for (int i = 0; i < right_len; i++)
    {
        temp_right[i] = a[m + 1 + i];
    }

    i = 0, j = 0, k = l;
    while (i < left_len && j < right_len)
    {

        if (temp_left[i] < temp_right[j])
        {
            a[k] = temp_left[i];
            i++;
        }
        else
        {
            a[k] = temp_right[j];
            j++;
        }
        k++;
    }

    for (; i < left_len; i++)
    {
        a[k] = temp_left[i];

        k++;
    }
    for (; j < right_len; j++)
    {
        a[k] = temp_right[j];
        k++;
    }
}

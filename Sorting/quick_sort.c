#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int a[], int l, int h)
{
    int pivot = a[l];
    int i = l;
    int j = h;
    while (i < j)
    {
        while (a[i] <= pivot && i <= h - 1)
        {
            i++;
        }
        while (a[j] > pivot && j >= l + 1)
        {
            j--;
        }
        if (i < j)
        {
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[l], &a[j]);
    return j;
}
void quick_sort(int a[], int l, int h)
{
    if (l < h)
    {
        int pivot = partition(a, l, h);
        quick_sort(a, l, pivot - 1);
        quick_sort(a, pivot + 1, h);
    }
}
int main()
{
    int arr[] = {2, 1, 6, 8, 2, 3, 4, 9};
    int len = sizeof(arr) / sizeof(int);
    quick_sort(arr, 0, len - 1);
    for (int i = 0; i < len; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
    return 0;
}
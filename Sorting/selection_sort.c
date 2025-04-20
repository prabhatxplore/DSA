#include <stdio.h>

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int smallestIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallestIdx])
            {
                smallestIdx = j;
            }
            // swapping
        }
        int temp = arr[i];
        arr[i] = arr[smallestIdx];
        arr[smallestIdx] = temp;
    }
}
int main()
{
    int arr[] = {9, 8, 5, 2, 6, 1};
    int n = sizeof(arr) / sizeof(int);

    selection_sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    return 0;
}
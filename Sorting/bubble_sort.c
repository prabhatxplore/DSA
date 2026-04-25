#include <stdio.h>

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d iteration \n", i);
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
            for (int i = 0; i < n; i++)
            {
                printf("%d  ", arr[i]);
            }
            printf("\n");
        }
    }
}
int main()
{
    int arr[] = {2, 3, 1};
    int n = (sizeof(arr) / sizeof(int));

    bubble_sort(arr, n);
    printf("Sorted array\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
}
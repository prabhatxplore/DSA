#include <stdio.h>
int binarySearch(int Arr[], int key, int n);
int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 13, 45, 46, 78, 80, 85, 89, 95, 120, 126, 150}, n;
    // Enter your key
    int key = 150;
    // Index to the last array
    n = sizeof(A) / sizeof(A[0]) - 1;
    // Calling Function
    int result = binarySearch(A, key, n);
    // Printing result
    if (result != -1)
    {
        printf("Element %d is found at index [%d]", key, result);
    }
    else
        printf("Element not found");
    return 0;
}
// Binary Search Algorithm
int binarySearch(int Arr[], int key, int n)
{
    // Initializing low and high
    int l = 0, h = n;
    // loop all the way while low less or equal to high
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (Arr[mid] == key)
        {
            return mid;
        }
        else if (key < Arr[mid])
        {
            h = mid - 1;
        }
        else
            l = mid + 1;
    }
    // return (-1) element not found
    return -1;
}

#include <stdio.h>

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int PI = low - 1;

    for (int i = low; i < high; i++)
    {
        if (arr[i] < pivot)
        {
            PI++;
            // swpap arr[PI] and arr[i]
            int temp = arr[PI];
            arr[PI] = arr[i];
            arr[i] = temp;
        }
    }
    PI++;
    // swap arr[PI] and arr[high]
    int temp = arr[PI];
    arr[PI] = arr[high];
    arr[high] = temp;

    return PI;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int PI = partition(arr, low, high);

        quickSort(arr, low, PI - 1);
        quickSort(arr, PI + 1, high);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];

    // Input the array elements
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Perform quick sort
    quickSort(arr, 0, n - 1);

    // Print the sorted array
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}
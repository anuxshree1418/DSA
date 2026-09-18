#include <stdio.h>
int binarySearch(int arr[], int n, int k)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (k == arr[mid])
            return mid;
        else if (k > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int k;
    scanf("%d", &k);
    int res = binarySearch(arr, n, k);
    if (res != -1)
        printf("found at %d th idx", res);
    else
        printf("key is not found");
    return 0;
}


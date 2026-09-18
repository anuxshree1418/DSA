// MERGE SORTING
#include <stdio.h>
void mergesort(int *, int);// this function actually divide the array in subarrays
void merge(int *, int, int *, int, int *, int);//compare and merge the subarrays in thrird array
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    mergesort(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d", arr[i]);
}
void mergesort(int *arr, int n)
{
    if (n < 2)
        return;
    int mid = n / 2;
    int left[mid];
    int right[n - mid];

    for (int i = 0; i < mid; i++)
        left[i] = arr[i];
    for (int i = mid; i < n; i++)
        right[i - mid] = arr[i];
    mergesort(left, mid);
    mergesort(right, n - mid);
    merge(left, mid, right, n - mid, arr, n);
}
void merge(int *left, int nL, int *right, int nR, int *arr, int n)
{
    int i = 0, j = 0, k = 0;
    while (i < nL && j < nR)
    {
        if (left[i] <= right[j])
            arr[k] = left[i++];
        else
            arr[k] = right[j++];
            
        k++;
    }
    while (i < nL)// collect the left over elements of left subarray
        arr[k++] = left[i++];

    while (j < nR)// collect the left over elements of right subarray
        arr[k++] = right[j++];
}
#include <stdio.h>
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) // for(int i=0;i<=n-2;i++)
    {
        for (int j = i + 1; j < n; j++) // for(int j = i+1;j<=n-1;j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
selectionSort(arr,n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
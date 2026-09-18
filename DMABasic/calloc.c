#include <stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d", &n);
    int *arr = calloc(n, sizeof(int));
    if (!arr)
    {
        printf("memory allocation failed");
        exit(1);
    }
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    free(arr);
    arr=NULL;
    return 0;
}
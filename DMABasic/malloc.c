#include <stdio.h>
#include <stdlib.h>
// CREATING ARRAY USING DYNAMIC MEMORY ALLOCATON MALLOC
int *getArray(int n)
{
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;
    return arr;
}
int main()
{
    int n;
    scanf("%d", &n);
    int *arr = getArray(n);
    for (int i = 0; i < n; i++)
        printf("%d", arr[i]);
    free(arr);
    arr = NULL;

    return 0;
}
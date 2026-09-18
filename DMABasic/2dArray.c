#include<stdio.h>
#include<stdlib.h>
int main()
{
    int row,col;
    scanf("%d%d",&row,&col);
    int **arr=malloc(row*sizeof(int *));
    for(int i=0;i<row;i++)
    {
        arr[i]=malloc(col*sizeof(int));
        if(!arr[i])
        {
            printf("memory allocation failed");
            exit(1);
        }
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
            scanf("%d",&arr[i][j]);
    }

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
            printf("%d",arr[i][j]);
    }

return 0;
}
// ZERO INDEX BASED ARRAY BASED TREE..
#include<stdio.h>
int main()
{
    int size;
    printf("Give the number of nodes of the tree you want :");
    scanf("%d",&size);
    int arr[size];
    int k=0; //AS THIS IS 0TH IDX BASED 
    int rdata;
    printf("enter the root node data:");
    scanf("%d",&rdata);
    arr[k]=rdata;

    
return 0;
}
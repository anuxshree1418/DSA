#include<iostream>
using namespace std;
void mergeSort(int * ,int );
void merge(int *,int,int *,int,int *,int);
int main()
{    
    return 0;
}
void mergeSort(int *arr,int n )
{
    int mid =n/2;
    int left[mid];
    int right[n-mid];
    for(int i=0;i<mid;i++)
        left[i]=arr[i];
    for(int i=mid;i<n;i++)
        right[i-mid]=arr[i];
    mergeSort(left,mid);
    mergeSort(right,n-mid);
    merge(left,mid,right,n-mid,arr,n);
}

void merge(int *left,int nL,int *right,int rL,int *arr,int n)
{
    
}

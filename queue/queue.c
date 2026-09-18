#include<stdio.h>

int arr[5];
int front =-1;
int rear=-1;
void enQ(int data)
{
    if(rear>=4)
    {
        printf("the queue is full ..");
        return;
    }
    else
    {
        if(front==-1&&rear==-1)
    {
        front++;
        arr[++rear]=data;
    }
    else 
        arr[++rear]=data;
    }
}
void deQ()
{
    if(front==-1 || front==5)
    {
        printf("the queue is already empty ..");
        return;
    }
    else
    {
        ++front;
    }

}
void peek()
{
    if(front ==-1 || front == 5)
    {
         printf("empty ..");
    }
    else
    {
        printf("%d",&arr[front]);
    }
}

int main()
{
    enQ(2);
    enQ(3);
    enQ(6);
    deQ();
    peek();
    enQ(8);
    

return 0;
}
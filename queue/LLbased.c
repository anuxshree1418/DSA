#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *nxt;
} node;

node *head = NULL;
node *top = NULL;
int nodecount = 0;

void enQ(int);
void peek();
void deQ();

int main()
{
    enQ(1);
    enQ(2);
    enQ(3);
    enQ(4);
    peek();//should print 1
    deQ();
    peek();//should print 2
    enQ(5);
    peek();//should print 2
    return 0;
}
void enQ(int data)
{
    node *newnode = malloc(sizeof(node));
    if (!newnode)
    {
        printf("failed to allocate memory .");
        exit(1);
    }
    nodecount++;
    newnode->data = data;
    newnode->nxt = NULL;

    // NOW INSERTING AT LAST :)
    if (head == NULL)
    {
        head = newnode;
    }
    else
        top->nxt = newnode;

    top = newnode;
}

void peek()
{
    if(!head)
    {
        printf("empty stack...");
        return;
    }
    printf("%d\n",head->data);
}


void deQ()//delete first node
{
    if (!head)
        return;
    node *curr = head;
    node *nxtnode = curr->nxt;
    free(curr);
    nodecount--;
    head = nxtnode;
}

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

void push(int);
void peek();
void pop();

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    peek();//should print 4
    pop();
    peek();//should print 3
    push(5);
    peek();//should print 5
    return 0;
}
void push(int data)
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
    if(!top)
    {
        printf("empty stack...");
        return;
    }
    printf("%d\n",top->data);
}
// DELETE FROM LAST NODE

void pop() // THIS DELETE ONLY THE LAST NODE
{
    if (head == NULL)
        printf("Not possible to delete..");
    else if (!head->nxt)
    {
        free(head);
        head = NULL;
        return;
    }
    else
    {
        node *temp = head;
        while (temp->nxt->nxt != NULL)
        {
            temp = temp->nxt;
        }
        free(temp->nxt);
        nodecount--;
        temp->nxt = NULL;
        top = temp;
    }
}
// THIS GIVES SEGMENTATION FAULT IN ONLINE COMPILER BUT IN GCC IT WORK PROPERLY
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *nxt;
} node;

node *head = NULL;
node *tail = NULL;
int nodecount = 0;

node *makenode(int);
void inrt_at_begin(int);
void inrt_at_last(int);
void inrt_at_anyposition(int, int);
void display();
void deleteLast();            // THIS DELETE ONLY THE LAST NODE
void deletefirst();           // THIS DELETE ONLY THE 1ST NODE
void deletefromfirst(node *); // THIS DELETE WHOLE LIST AND THE DELETETION START FROM 1ST NODE
void deletefromlast();        // THIS DELETE THE WHOLE LIST AND THE DELETION START FROM THE LAST NODE
void deleteanyposition(int);  // THIS DELETE THE NODE OF ANY SPECIFIC POSITION
int main()
{
    for (int i = 1; i <= 10; i++)
        inrt_at_begin(i);
    inrt_at_anyposition(17, 3); // THIS INSERT THE 17 IN 3RD INDEX NOT IN 3RD POSITION

    display();
    deletefromlast();
    printf("\n");
    display();

    return 0;
}

node *makenode(int data)
{
    node *newnode = malloc(sizeof(node));
    if (!newnode)
    {
        printf("memory allocation failed .");
        exit(1);
    }

    newnode->data = data;
    newnode->nxt = NULL;

    return newnode;
}

void inrt_at_begin(int data)
{
    node *newnode = makenode(data);
    nodecount++;

    // NOW I HAVE TO INSERT THIS NODE AT THE BEGGINING

    (*newnode).nxt = head;
    head = newnode;

    if (!tail)
        tail = newnode; // THIS  WORKS WHEN THE LIST IS EMPTY AND I  CREATE AND LINKED THE 1ST NODE
}

void inrt_at_last(int data)
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
        tail->nxt = newnode;

    tail = newnode;
}

void inrt_at_anyposition(int data, int position)
{

    // If you have 5 nodes (nodecount = 5), their indices are 0, 1, 2, 3, and 4. So if I want to add at postion 6 there is no position 5(node which idx is 5)

    if (position < 0 || position > nodecount)
        printf("insert node is not possible .");
    else if (position == 0)
    {
        inrt_at_begin(data);
    }
    else if (position == nodecount)
    {
        inrt_at_last(data);
    }
    else
    {
        node *newnode = makenode(data);
        node *temp = head;
        for (int i = 0; i < position - 1; i++) // THIS LOOP IS FOR INSERT THE NODE INDEXWISE (IF I GIVE POSITION 3 THEN IT INSERT AT 3 IDX)
                                               // for(int i=0;i<position-2;i++) (THIS IS LITTLE BIT USER FRIENDLY THIS ACTULLY INSERT THE NODE AT 3RD POSITION NOT AT 3RD INDEX)
            temp = temp->nxt;

        newnode->nxt = temp->nxt;
        temp->nxt = newnode;
        nodecount++;
    }
}

void display()
{
    if (!head)
        printf("the list is empty ..");
    else
    {
        node *temp = head;
        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->nxt;
        }
    }
}

void deleteLast() // THIS DELETE ONLY THE LAST NODE
{
    if (head == NULL)
        printf("Not possible to delete..");
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
        tail = temp;
    }
}
void deletefirst()
{
    if (!head)
        return;
    node *curr = head;
    node *nxtnode = curr->nxt;
    free(curr);
    nodecount--;
    head = nxtnode;
}

void deletefromfirst(node *ptr)
{
    if (!head)
        return;
    node *curr = head;
    node *nxtnode = curr->nxt;
    free(curr);
    head = nxtnode;
    deletefromfirst(nxtnode);
    tail = NULL;
    nodecount = 0;
}

void deletefromlast()
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
        temp->nxt = NULL;
    }
    while (head)
        deletefromlast();
    tail = NULL;
    nodecount = 0;
}

void deleteanyposition(int position)
{
    if (position < 0 || position >= nodecount)
        printf("deletion can't be possible..");
    else if (position == 0)
        deletefirst();
    else if (position == nodecount - 1)
        deleteLast();
    else
    {
        node *temp = head;
        for (int i = 0; i < position - 1; i++)
            temp = temp->nxt;
        node *temp2 = temp->nxt->nxt;
        free(temp->nxt);
        nodecount--;
        temp->nxt = temp2;
    }
}
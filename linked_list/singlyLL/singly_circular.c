#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *nxt;

} node;

node *head = NULL, *tail = NULL;
int nodecount = 0;

void inrt_at_begin(int);
node *makenode(int);
void display();
void deletefromfirst(node *); // recursively delete from 1st node
void inrt_at_last(int);
void inrt_anyposition(int, int);
void deletefromlast(); // recursively delete from last
void deleteLast();     // delete only the last node
void deleteFirst();    // delete only the first node
void deleteanyposition(int);

int main()
{
    for (int i = 1; i <= 2; i++)
        inrt_at_last(i);
    // inrt_anyposition(17, 2); // this function insert the newnode at 3rd node not at 3rd index this is little bit user friendly;
    display();
    deleteLast();
    deleteLast();
    printf("\n");
    display();

    return 0;
}

void inrt_at_begin(int data)
{
    node *newnode = makenode(data);
    nodecount++;
    // NOW I HAVE TO INSERT THIS NODE AT THE BEGGINING BUT THIS IS CIRCULAR
    if (!head)
    {
        head = tail = newnode;
    }
    else
    {
        newnode->nxt = head;
        head = newnode;
    }
    tail->nxt = newnode;
}
void inrt_at_last(int data)
{
    node *newnode = makenode(data);
    if (!newnode)
    {
        printf("memory allocation failed.");
        exit(1);
    }
    nodecount++;
    if (!head)
        tail->nxt = head = tail = newnode;
    else
    {
        newnode->nxt = head;
        tail->nxt = newnode;
        tail = newnode;
    }
}
void inrt_anyposition(int data, int position)
{
    if (position < 0 || position > nodecount)
        printf("node insertion is not possible ...");
    else if (position == 0)
        inrt_at_begin(data);
    else if (position == nodecount)
        inrt_at_last(data);
    else
    {
        node *temp = head;
        for (int i = 0; i < position - 2; i++)
            temp = temp->nxt;

        node *newnode = makenode(data);
        if (!newnode)
        {
            printf("memory allocation failed");
            exit(1);
        }
        nodecount++;
        newnode->nxt = temp->nxt;
        temp->nxt = newnode;
    }
}

void display()
{
    if (head == NULL)
        printf("empty list");
    else
    {
        node *temp = head;
        while (temp->nxt != head)
        {
            printf("%d ", (*temp).data);
            temp = temp->nxt;
        }
        printf("%d", temp->data);
    }
}
void deletefromfirst(node *curr) // delete(head)
{
    if (curr == NULL) // BASE CONDITION..:)
        return;
    if (head == tail)
    {
        free(head);
        head = tail = NULL;
    }
    if (head != tail)
    {
        node *current = curr; // current = head = address od 1st node

        node *address_of_next_node = (*current).nxt; // address_of_next_node = address of 2nd node

        free(current); // free the 1st node
        head = address_of_next_node;
        tail->nxt = address_of_next_node;
        deletefromfirst(address_of_next_node);
    }
    nodecount = 0;
}

void deleteFirst()
{
    if (!head)
    {
        printf("deletion can't be possible..");
        return;
    }
    if (head == tail)
    {
        free(head);
        nodecount--;
        head = tail = NULL;
    }
    if (head != tail)
    {
        node *nxtnode = head->nxt;
        free(head);
        nodecount--;
        head = tail->nxt = nxtnode;
    }
}
void deleteLast()
{
    if (!head)
        return;
    node *temp = head;

    while (temp->nxt->nxt != head)
        temp = temp->nxt;
    if (head == tail)
    {
        free(temp);
        nodecount--;
        head = tail = NULL;
    }
    else
    {
        free(temp->nxt);
        nodecount--;
        temp->nxt = head;
        tail = temp;
    }
}
void deletefromlast()
{
    if (!head)
        return;
    node *temp = head;

    while (temp->nxt->nxt != head)
        temp = temp->nxt;
    if (head == tail)
    {
        free(temp->nxt);
        head = tail = NULL;
    }
    else
    {
        free(temp->nxt);
        nodecount--;
        temp->nxt = head;
        tail = temp;
    }
    while (head)
        deletefromlast();

    nodecount = 0;
}
void deleteanyposition(int position)
{
    // if(position<0||position>nodecount)
}
// MAKING NEW NODE

node *makenode(int data)
{
    node *newnode = malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("memory allocation failed");
        exit(1);
    }
    newnode->data = data;
    newnode->nxt = NULL;
    return newnode;
}
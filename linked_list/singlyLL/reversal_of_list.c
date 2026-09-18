#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *nxt;
}node;

node *head = NULL;
node *tail = NULL;
int nodecount =0;

void inrt_at_begin(int);
void display();
void delete(node *);
void reverse(node *);
node *makenode(int);

int main()
{
    for(int i=1;i<=7;i++)
        inrt_at_begin(i);
    display();
    printf("\n");
    reverse(head);
    display();
    delete(head);
    display();
    return 0;
}

node *makenode(int data)
{
    node *newnode = malloc(sizeof (node));
    if(!newnode)
    {
        printf("memory allocation failed ..");
        exit(1);
    }
    newnode->data=data;
    newnode->nxt= NULL;
    return newnode;
    
}

void inrt_at_begin(int data)
{
    node *newnode = makenode(data);

    // NOW I HAVE TO INSERT THIS NODE AT THE BEGGINING
    (*newnode).nxt = head;
    head = newnode;
}
void display()
{
    if (head == NULL)
        printf("empty list");
    else
    {
        node *temp = head;
        while (temp != NULL)
        {
            printf("%d ", (*temp).data);
            temp = temp->nxt;
        }
    }
}

void delete(node *curr) // delete(head)
{
    if (curr == NULL)// BASE CONDITION..:)
        return;

    node *current = curr; // current = head = address od 1st node

    node *address_of_next_node = (*current).nxt; // address_of_next_node = address of 2nd node
    head=address_of_next_node;

    free(current); // free the 1st node

    delete(address_of_next_node);
   
}

void reverse(node *newnode)
{
    node *currentnode = newnode;
    node *previousnode = NULL;
    node *nextnode = NULL;

    while(currentnode != NULL)
    {
        nextnode= currentnode->nxt;
        currentnode->nxt = previousnode;
        previousnode = currentnode;
        currentnode = nextnode;
    }

    head = previousnode;
}
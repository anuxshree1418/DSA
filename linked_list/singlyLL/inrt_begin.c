#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *nxt;

} node;

node *head = NULL;
void take_data(int);
node *makenode(int);
void display();
void delete(node *);

int main()
{
    for (int i = 1; i <= 10; i++)
        take_data(i);

    display();
    delete(head);
    display();

    return 0;
}

void take_data(int data)
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
    if (curr == NULL) // BASE CONDITION..:)
        return;

    node *current = curr; // current = head = address od 1st node

    node *address_of_next_node = (*current).nxt; // address_of_next_node = address of 2nd node

    free(current); // free the 1st node

    delete(address_of_next_node);
    head = NULL;
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
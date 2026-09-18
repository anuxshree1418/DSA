#include <stdio.h>
int n = 5;
int stack[5];
int top = -1;
void push(int value)
{
    if (top == n - 1)
    {
        printf("stack overflow...\n");
        return;
    }
    stack[++top] = value;
}
void peek()
{
    if(top==-1)
    {
        printf("stack empty...\n");
        return;
    }
    printf("%d\n",stack[top]);
}
void pop()
{
    if(top==-1)
    {
        printf("stack underflow...\n");
        return;
    }
    top--;
}

int main()
{
    push(10);
    push(20);
    push(30);
    peek(); // Should print 30
    pop();
    peek(); // Should print 20
    pop();
    peek(); // Should print 10
    pop();
    peek(); // Should print "Stack is empty"
    pop(); // Should print "Stack underflow"
    push(40);
    push(50);
    push(60);
    push(70);
    push(80);
    push(90); // Should print "Stack overflow"

    return 0;
}
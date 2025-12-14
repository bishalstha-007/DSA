#include <stdio.h>
#define size 5

int top = -1;
int stack[size];

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (top == size - 1)
        return 1;
    else
        return 0;
}

void push(int value)
{
    if (isFull())
        printf("stack is full.");
    else
    {
        top++;
        stack[top] = value;
    }
}

int pop()
{
    if (isEmpty())
        // printf("stack is empty");
        return 1;
    else
    {
        int temp = stack[top];
        top--;
        return temp;
    }
}

void peek()
{
    if (isEmpty())
        printf("stack is empty");
    else
        printf("top element:%d\n", stack[top]);
}

void display()
{
    if (isEmpty())
        printf("stack is empty");
    else
    {
        printf("stack elements:\n");
        for (int i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

int main()
{
    // display();
    push(3);
    push(6);
    push(69);
    push(91);
    display();
    peek();
    display();
    printf("poped value is %d\n", pop());
    peek();
    return 0;
}
#include <stdio.h>
#define SIZE 7

int top = -1;
int stack[SIZE];

int isEmpty()
{
    return (top == -1);
}

int isFull()
{
    return (top == SIZE - 1);
}

void push(int data)
{
    if (isFull())
    {
        printf("Stack is full.\n");
    }
    else
    {
        top++;
        stack[top] = data;
    }
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack is empty.\n");
        return 1; 
    }
    else
    {
        int data = stack[top];
        top--;
        return data;
    }
}

void peek()
{
    if (isEmpty())
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Top element is: %d\n", stack[top]);
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    push(9);
    push(18);
    push(1);
    display();
    peek();
    printf("Popped: %d\n", pop());
    display();
    return 0;
}
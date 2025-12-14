#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

void isFull();
void isEmpty();
void push();
void pop();
void peek();
void display();

int main()
{
    int choice = 0;

    while (choice != 7)
    {
        printf("1. Check Full\n");
        printf("2. Check Empty\n");
        printf("3. Push\n");
        printf("4. Pop\n");
        printf("5. Peek\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            isFull(); 
            break;

        case 2:
            isEmpty(); 
            break;

        case 3:
            push();
            break;

        case 4:
            pop();
            break;

        case 5:
            peek();
            break;

        case 6:
            display();
            break;

        case 7:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

void isFull()
{
    if (top == SIZE - 1)
        printf("Stack is FULL\n");
    else
        printf("Stack is NOT full\n");
}

void isEmpty()
{
    if (top == -1)
        printf("Stack is EMPTY\n");
    else
        printf("Stack is NOT empty\n");
}

void push()
{
    int value;
    if (top == SIZE - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        printf("Enter value: ");
        scanf("%d", &value);
        stack[++top] = value;
        printf("Value pushed successfully\n");
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        printf("Popped element: %d\n", stack[top--]);
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top element: %d\n", stack[top]);
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
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



#include <stdio.h>
#define SIZE 5

int top = -1;
int stack[SIZE];

// Function prototypes
int isFull(), pop(), isEmpty();

void push(int value), peek(),  display();

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- Stack Menu ---\n");
        printf("1. Check if Full\n");
        printf("2. Check if Empty\n");
        printf("3. Push\n");
        printf("4. Pop\n");
        printf("5. Peek\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: if (isFull())
                printf("Stack is full.\n");
            else
                printf("Stack is not full.\n");
            break;

        case 2:
            if (isEmpty())
                printf("Stack is empty.\n");
            else
                printf("Stack is not empty.\n");
            break;

        case 3:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;

        case 4:
            value = pop();
            if (value != 1)
                printf("Popped: %d\n", value);
            break;

        case 5:
            peek();
            break;

        case 6:
            display();
            break;

        case 7:
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
}

// Check if stack is full
int isFull()
{
    return top == SIZE - 1;
}

// Check if stack is empty
int isEmpty()
{
    return top == -1;
}

// Push operation
void push(int value)
{
    if (isFull())
    {
        printf("Stack overflow!\n");
    }
    else
    {
        stack[++top] = value;
        printf("Pushed: %d\n", stack[top]);
    }
}

// Pop operation
int pop()
{
    if (isEmpty())
    {
        printf("Stack underflow!\n");
        return 1;
    }
    else
    {
        return stack[top--];
    }
}

// Peek operation
void peek()
{
    if (isEmpty())
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Top element: %d\n", stack[top]);
    }
}

// Display stack elements
void display()
{
    if (isEmpty())
    {
        printf("Stack is empty!\n");
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
#include <stdio.h>
#define MAX 5

int top = -1;
char stack[MAX];

int isempty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull()
{
    if (top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(char data)
{
    if (!isfull())
    {
        stack[++top] = data;
        printf("Pushed: %c\n", data);
    }
    else
    {
        printf("Stack is OverFlow.\n");
    }
}

void pop()
{
    if (!isempty())
    {
        char data = stack[top];
        top--;
        printf("Popped: %c\n", data);
    }
    else
    {
        printf("Stack is UnderFlow.\n");
    }
}

int main()
{

    char ex[] = "d-{a+(b*c)]}";

    int n = sizeof(ex) / sizeof(ex[0]) - 1; // -1 to exclude null terminator
    int is_well_bracketed = 1;              // Flag to track validity

    for (int i = 0; i < n; i++)
    {

        if (ex[i] == '[' || ex[i] == '{' || ex[i] == '(')
        {
            push(ex[i]);
        }
        else if (ex[i] == ']' || ex[i] == '}' || ex[i] == ')')
        {
            if (isempty())
            {
                printf("Ill Brackeeted.\n");
                is_well_bracketed = 0;
                break;
            }
            else if ((stack[top] == '[' && ex[i] == ']') ||
                     (stack[top] == '{' && ex[i] == '}') ||
                     (stack[top] == '(' && ex[i] == ')'))
            {

                pop();
            }
            else
            {
                printf("Ill Brackeeted.\n");
                is_well_bracketed = 0;
                break;
            }
        }
    }
    if (is_well_bracketed)
    {
        if (!isempty())
        {
            printf("Ill Bracketed.\n");
        }
        else
        {
            printf("Well Bracketed.\n");
        }
    }

    return 0;
}
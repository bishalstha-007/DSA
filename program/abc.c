#include <stdio.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

/* Stack operations */
void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    if (top == -1)
        return '\0';
    return stack[top--];
}

/* Matching logic */
int isMatching(char open, char close)
{
    if (open == '(' && close == ')')
        return 1;
    if (open == '{' && close == '}')
        return 1;
    if (open == '[' && close == ']')
        return 1;
    return 0;
}

/* Main checking function */
int areBracketsBalanced(char expr[])
{
    for (int i = 0; i < strlen(expr); i++)
    {
        char ch = expr[i];

        // If opening bracket, push
        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }
        // If closing bracket
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            char popped = pop();

            // No matching opening bracket
            if (!isMatching(popped, ch))
                return 0;
        }
    }
    // If stack is empty at end
    return (top == -1);
}

int main()
{
    char expr[100];

    printf("Enter an expression: ");
    scanf("%s", expr);

    if (areBracketsBalanced(expr))
        printf("Brackets are BALANCED\n");
    else
        printf("Brackets are NOT BALANCED\n");

    return 0;
}

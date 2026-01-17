#include <stdio.h>
#include <string.h>

char stack[20];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

int priority(char x)
{
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char infix[20], prefix[20];
    int i, j = 0;
    char x;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    /* Reverse infix */
    strrev(infix);

    /* Swap brackets */
    for (i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    /* Convert to postfix */
    for (i = 0; infix[i] != '\0'; i++)
    {
        x = infix[i];

        if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
        {
            prefix[j++] = x;
        }
        else if (x == '(')
        {
            push(x);
        }
        else if (x == ')')
        {
            while (stack[top] != '(')
                prefix[j++] = pop();
            pop();
        }
        else
        {
            while (top != -1 && priority(stack[top]) > priority(x))
                prefix[j++] = pop();
            push(x);
        }
    }

    while (top != -1)
        prefix[j++] = pop();

    prefix[j] = '\0';

    /* Reverse postfix to get prefix */
    strrev(prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}

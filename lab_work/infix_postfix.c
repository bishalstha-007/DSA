
#include <stdio.h>

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
    else if (x == '*' || x == '/')
        return 2;
    else
        return 0;
}

int main()
{
    char infix[20], postfix[20];
    int i = 0, j = 0;
    char x;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while (infix[i] != '\0')
    {
        x = infix[i];

        /* Operand */
        if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
        {
            postfix[j++] = x;
        }
        /* Left parenthesis */
        else if (x == '(')
        {
            push(x);
        }
        /* Right parenthesis */
        else if (x == ')')
        {
            while (stack[top] != '(')
                postfix[j++] = pop();
            pop();
        }
        /* Operator */
        else
        {
            while (top != -1 && priority(stack[top]) >= priority(x))
                postfix[j++] = pop();
            push(x);
        }
        i++;
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);
    return 0;
}

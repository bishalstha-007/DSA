#include <stdio.h>
#include <string.h>

int stack[20];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char prefix[20], ch;
    int i;
    int a, b, result;

    printf("Enter prefix expression: ");
    scanf("%s", prefix);

    /* Scan from right to left */
    for (i = strlen(prefix) - 1; i >= 0; i--)
    {
        ch = prefix[i];

        /* Operand (single digit) */
        if (ch >= '0' && ch <= '9')
        {
            push(ch - '0');
        }
        else /* Operator */
        {
            a = pop();
            b = pop();

            if (ch == '+')
                result = a + b;
            else if (ch == '-')
                result = a - b;
            else if (ch == '*')
                result = a * b;
            else if (ch == '/')
                result = a / b;

            push(result);
        }
    }

    printf("Result = %d\n", pop());
    return 0;
}
 
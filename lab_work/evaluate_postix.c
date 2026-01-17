#include <stdio.h>

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
    char postfix[20], ch;
    int i = 0;
    int a, b, result;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    while (postfix[i] != '\0')
    {
        ch = postfix[i];

        /* If operand (single digit) */
        if (ch >= '0' && ch <= '9')
        {
            push(ch - '0'); // convert char to int
        }
        else /* Operator */
        {
            b = pop();
            a = pop();

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
        i++;
    }

    printf("Result = %d\n", pop());
    return 0;
}

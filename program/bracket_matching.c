#include<stdio.h>
#define size 5

int top = -1;
char stack[size];

int isEmpty();
int isFull();
void push(char val);
void pop();

int main()
{
    char ch[] = "d-{a+(b*c)]}";

    // for (int i = 0; i < n; i++) {
    //     printf("Enter the expression:");
    //     scanf("%s",ch[i]);

    int n = sizeof(ch) / sizeof(ch[0]) - 1;

    for (int i = 0; i < n; i++)
    {
        if (ch[i] == '[' || ch[i] == '{' || ch[i] == '(')
            push(ch[i]);

        // else if(ch[i] == ch[top])
        else if ((stack[top] == '[' && ch[i] == ']') ||
                 (stack[top] == '{' && ch[i] == '}') ||
                 (stack[top] == '(' && ch[i] == ')'))
            pop();

        else if (ch[i] == ']' || ch[i] == '}' || ch[i] == ')') {
            printf("Ill bracket\n");
            return 0; 
        }
    }

    if (isEmpty())
        printf("Well bracket\n");
    else
        printf("Ill bracket\n");
    return 0;
}

int isFull()
{
    return (top == size - 1) ;
}

int isEmpty()
{
        return (top == -1);
}

void push(char val) {
    if (isFull()) 
    printf("stack is Full. \n");
    else{
        top++;
        stack[top] = val;
        printf("%c is pushed in the stack\n", val);
    }
}

void pop() {
    if (isEmpty()) 
    printf("stack is empty\n");
    else {
        char val = stack[top];
        top--;
        printf("%c is poped\n", val);
    }
} 

#include<stdio.h>
#define SIZE 7 
int top= -1;
int stack[SIZE] ;

isEmpty() {
    if (top == -1){
        return 1;
    }
    else {
    return 0;
    }
}
isFull() {
    if(top == SIZE - 1) {
        return 1;
    }
    else
    return 0;
}

int push(int data) {
    if(isFull())
    printf("stack is full.\n") ;
    else {
        top++;
        stack[top]= data;
    }
}

void pop() {
    if(isEmpty())
    printf("stack is empty. \n");
    else 
    {
        int data = stack[top];
        top--;
    }
}

void peek(){
    if(isEmpty()) 
    printf("empty.\n");
    else
    printf("Top element is:%d", stack[top]);
}

int display() {
    if(isEmpty()) {
        printf("stack is empty.\n");
    }
    else {
        for ( int i=top; i >=0; i--) {
            printf("%d\n", stack[top]);
        }
    }
}

int main() {
    push (9);
    push(18);
    push(1);
    display() ;
    return 0;
}
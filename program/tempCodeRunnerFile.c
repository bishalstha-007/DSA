#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

/* Function declarations */
int isFull();
int isEmpty();
void push();
void pop();
void peek();
void display();

int main() {
    int choice;

    do {
        printf("\n--- STACK MENU ---\n");
        printf("1. Check Full\n");
        printf("2. Check Empty\n");
        printf("3. Push\n");
        printf("4. Pop\n");
        printf("5. Peek\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFull())
                    printf("Stack is FULL\n");
                else
                    printf("Stack is NOT full\n");
                break;

            case 2:
                if (isEmpty())
                    printf("Stack is EMPTY\n");
                else
                    printf("Stack is NOT empty\n");
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
    } while (choice != 7);

    return 0;
}

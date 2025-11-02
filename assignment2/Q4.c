#include <stdio.h>

#define MAX 5

int push(int arr[], int top);
int pop(int arr[], int top);
void peek(int arr[], int top);
void show(int arr[], int top);

int main() {
    int stack[MAX];
    int top = -1, choice;

    do {
        printf("\n========== STACK MENU ==========\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: top = push(stack, top); break;
            case 2: top = pop(stack, top); break;
            case 3: peek(stack, top); break;
            case 4: show(stack, top); break;
            case 5: printf("\nExiting program. Goodbye!\n"); break;
            default: printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}

int push(int arr[], int top) {
    int val;

    if (top == MAX - 1) {
        printf("\nStack Overflow! Cannot add more.\n");
        return top;
    }

    printf("Enter value to push: ");
    scanf("%d", &val);

    arr[++top] = val;
    printf("%d pushed onto stack.\n", val);

    return top;
}

int pop(int arr[], int top) {
    if (top == -1) {
        printf("\nStack Underflow! Stack is empty.\n");
        return top;
    }

    printf("%d popped from stack.\n", arr[top]);
    return --top;
}

void peek(int arr[], int top) {
    if (top == -1) {
        printf("\nStack is empty.\n");
        return;
    }

    printf("Top element: %d\n", arr[top]);
}

void show(int arr[], int top) {
    if (top == -1) {
        printf("\nStack is empty.\n");
        return;
    }

    printf("\n------ STACK CONTENTS ------\n");
    for (int i = top; i >= 0; i--)
        printf("| %d |\n", arr[i]);
    printf("-----------------------------\n");
}


#include <stdio.h>
#include <stdlib.h>

int top = -1;
int num[100], size, var, choice = 0;

void push() {
    if (top == size - 1) {
        printf("stack overflow\n");
        return;
    }
    top++;
    printf("enter the element: ");
    scanf("%d", &var);
    num[top] = var;
}

void pop() {
    if (top == -1) {
        printf("stack underflow\n");
        return;
    }
    printf("the popped element is %d\n", num[top]);
    top--;
}

void display() {
    if (top == -1) {
        printf("the stack is empty\n");
        return;
    }
    printf("the elements are:\n");
    for (int i = 0; i <= top; i++) {
        printf("%d\n", num[i]);
    }
}

int main() {
    printf("stack operations\n");
    printf("enter the size: ");
    scanf("%d", &size);

    while (choice != 4) {
        printf("\npress 1 for push\n2 for pop\n3 for display\n4 to quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

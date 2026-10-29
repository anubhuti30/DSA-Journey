
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *next;
} nodeptr;

nodeptr *top = NULL;

/* PUSH: Insert an element */
void push(int item)
{
    nodeptr *newnode;

    newnode = (nodeptr *)malloc(sizeof(nodeptr));

    if (newnode == NULL) {
        printf("Stack Overflow: Memory not available!\n");
        return;
    }

    newnode->info = item;
    newnode->next = top;
    top = newnode;

    printf("%d pushed into stack.\n", item);
}

/* POP: Delete the top element */
void pop()
{
    nodeptr *temp;

    if (top == NULL) {
        printf("Stack Underflow: Stack is empty!\n");
        return;
    }

    temp = top;
    printf("Deleted element: %d\n", temp->info);

    top = top->next;
    free(temp);
}

/* PEEK: Display the top element */
void peek()
{
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Top element: %d\n", top->info);
}

/* DISPLAY: Print all elements */
void display()
{
    nodeptr *temp;

    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    temp = top;

    printf("Stack elements (TOP to BOTTOM):\n");

    while (temp != NULL) {
        printf("%d\n", temp->info);
        temp = temp->next;
    }
}

/* MENU-DRIVEN MAIN */
int main()
{
    int choice, item;

    while (1) {
        printf("\n--- STACK USING LINKED LIST ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &item);
                push(item);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

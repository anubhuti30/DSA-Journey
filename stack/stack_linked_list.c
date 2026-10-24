
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *next;
} nodeptr;

nodeptr *push(nodeptr *list, int x)
{
    nodeptr *p = malloc(sizeof(nodeptr));

    if (p == NULL) {
        printf("Memory allocation failed\n");
        return list;
    }

    p->info = x;
    p->next = list;
    list = p;

    printf("%d pushed into stack\n", x);
    return list;
}

nodeptr *pop(nodeptr *list)
{
    nodeptr *p;

    if (list == NULL) {
        printf("Stack Underflow\n");
        return list;
    }

    p = list;
    printf("Popped element: %d\n", p->info);
    list = list->next;
    free(p);

    return list;
}

void peek(nodeptr *list)
{
    if (list == NULL)
        printf("Stack is empty\n");
    else
        printf("Top element: %d\n", list->info);
}

void display(nodeptr *list)
{
    if (list == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack (top to bottom): ");
    while (list != NULL) {
        printf("%d ", list->info);
        list = list->next;
    }
    printf("\n");
}

int main(void)
{
    nodeptr *list = NULL;
    int choice, x;

    do {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n0. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
            case 1:
                printf("Enter element: ");
                if (scanf("%d", &x) != 1)
                    goto cleanup;
                list = push(list, x);
                break;

            case 2:
                list = pop(list);
                break;

            case 3:
                peek(list);
                break;

            case 4:
                display(list);
                break;

            case 0:
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);

cleanup:
    while (list != NULL)
        list = pop(list);

    return 0;
}

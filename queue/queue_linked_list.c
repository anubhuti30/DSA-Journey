
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *next;
} nodeptr;

typedef struct {
    nodeptr *front;
    nodeptr *rear;
} queue;

queue enqueue(queue q, int x)
{
    nodeptr *p = malloc(sizeof(nodeptr));

    if (p == NULL) {
        printf("Memory allocation failed\n");
        return q;
    }

    p->info = x;
    p->next = NULL;

    if (q.rear == NULL) {
        q.front = q.rear = p;
    } else {
        q.rear->next = p;
        q.rear = p;
    }

    printf("%d inserted into queue\n", x);
    return q;
}

queue dequeue(queue q)
{
    nodeptr *p;

    if (q.front == NULL) {
        printf("Queue Underflow\n");
        return q;
    }

    p = q.front;
    printf("Deleted element: %d\n", p->info);

    q.front = q.front->next;

    if (q.front == NULL)
        q.rear = NULL;

    free(p);
    return q;
}

void peek(queue q)
{
    if (q.front == NULL)
        printf("Queue is empty\n");
    else
        printf("Front element: %d\n", q.front->info);
}

void display(queue q)
{
    nodeptr *p = q.front;

    if (p == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue (front to rear): ");
    while (p != NULL) {
        printf("%d ", p->info);
        p = p->next;
    }
    printf("\n");
}

int main(void)
{
    queue q = {NULL, NULL};
    int choice, x;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n0. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
            case 1:
                printf("Enter element: ");
                if (scanf("%d", &x) != 1)
                    goto cleanup;
                q = enqueue(q, x);
                break;

            case 2:
                q = dequeue(q);
                break;

            case 3:
                peek(q);
                break;

            case 4:
                display(q);
                break;

            case 0:
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);

cleanup:
    while (q.front != NULL)
        q = dequeue(q);

    return 0;
}




#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *next;
} nodeptr;

nodeptr *front = NULL;
nodeptr *rear = NULL;

/* ENQUEUE: Insert an element */
void enqueue(int item)
{
    nodeptr *newnode;

    newnode = (nodeptr *)malloc(sizeof(nodeptr));

    if (newnode == NULL) {
        printf("Queue Overflow: Memory not available!\n");
        return;
    }

    newnode->info = item;
    newnode->next = NULL;

    if (front == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }

    printf("%d inserted into queue.\n", item);
}

/* DEQUEUE: Delete an element */
void dequeue()
{
    nodeptr *temp;

    if (front == NULL) {
        printf("Queue Underflow: Queue is empty!\n");
        return;
    }

    temp = front;
    printf("Deleted element: %d\n", temp->info);

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

/* PEEK: Display the front element */
void peek()
{
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Front element: %d\n", front->info);
}

/* DISPLAY: Print all elements */
void display()
{
    nodeptr *temp;

    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    temp = front;

    printf("Queue elements (FRONT to REAR):\n");

    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }

    printf("\n");
}

/* MENU-DRIVEN MAIN */
int main()
{
    int choice, item;

    while (1) {
        printf("\n--- QUEUE USING LINKED LIST ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &item);
                enqueue(item);
                break;

            case 2:
                dequeue();
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

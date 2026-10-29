
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *next;
} node;

/* CREATE A NEW NODE */
node *getnode()
{
    node *p;

    p = (node *)malloc(sizeof(node));

    if (p == NULL) {
        printf("Memory not available!\n");
        exit(1);
    }

    return p;
}

/* INSERT AT BEGINNING */
void insertbeg(node *head, int x)
{
    node *mnode;

    mnode = getnode();
    mnode->info = x;

    mnode->next = head->next;
    head->next = mnode;
}

/* INSERT AT END */
void insertend(node *head, int x)
{
    node *mnode, *q;

    mnode = getnode();
    mnode->info = x;

    q = head->next;

    while (q->next != head) {
        q = q->next;
    }

    mnode->next = head;
    q->next = mnode;
}

/* DELETE FIRST NODE */
void deletefirstnode(node *head)
{
    node *p;

    if (head->next == head) {
        printf("Circular linked list is empty!\n");
    } else {
        p = head->next;
        head->next = p->next;
        free(p);

        printf("First node deleted.\n");
    }
}

/* DELETE LAST NODE */
void deletelast(node *head)
{
    node *p, *q;

    if (head->next == head) {
        printf("Circular linked list is empty!\n");
    } else {
        q = head;
        p = head->next;

        while (p->next != head) {
            q = p;
            p = p->next;
        }

        q->next = head;
        free(p);

        printf("Last node deleted.\n");
    }
}

/* SEARCH AN ELEMENT */
void searchnode(node *head, int x)
{
    node *p;
    int count = 1;

    p = head->next;

    while (p != head) {
        if (p->info == x) {
            printf("Element found at position %d.\n", count);
            return;
        }

        p = p->next;
        count++;
    }

    printf("Element not present.\n");
}

/* DISPLAY THE LIST */
void display(node *head)
{
    node *p;

    if (head->next == head) {
        printf("Circular linked list is empty!\n");
        return;
    }

    p = head->next;

    printf("HEAD -> ");

    while (p != head) {
        printf("%d -> ", p->info);
        p = p->next;
    }

    printf("HEAD\n");
}

/* MAIN FUNCTION */
int main()
{
    node *head;
    int choice, x;

    /* Create dummy/header node */
    head = getnode();
    head->next = head;

    while (1) {
        printf("\n--- CIRCULAR LINKED LIST ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete First Node\n");
        printf("4. Delete Last Node\n");
        printf("5. Search Element\n");
        printf("6. Display List\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter element: ");
                if (scanf("%d", &x) != 1)
                    goto finish;
                insertbeg(head, x);
                break;

            case 2:
                printf("Enter element: ");
                if (scanf("%d", &x) != 1)
                    goto finish;
                insertend(head, x);
                break;

            case 3:
                deletefirstnode(head);
                break;

            case 4:
                deletelast(head);
                break;

            case 5:
                printf("Enter element to search: ");
                if (scanf("%d", &x) != 1)
                    goto finish;
                searchnode(head, x);
                break;

            case 6:
                display(head);
                break;

            case 7:
                goto finish;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

finish:
    /* Free all data nodes and the header node */
    while (head->next != head) {
        node *p = head->next;
        head->next = p->next;
        free(p);
    }

    free(head);

    printf("Program terminated.\n");
    return 0;
}

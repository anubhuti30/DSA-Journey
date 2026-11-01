
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *next;
    struct node *prev;
} nodeptr;

nodeptr *list = NULL;

// Create a new node
nodeptr *getnode(int data) {
    nodeptr *p = (nodeptr *)malloc(sizeof(nodeptr));

    if (p == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    p->info = data;
    p->next = p->prev = NULL;

    return p;
}

// Insert at beginning
nodeptr *insert_beg(nodeptr *list, int data) {
    nodeptr *p = getnode(data);

    if (list == NULL) {
        p->next = p->prev = p;
        return p;
    }

    nodeptr *last = list->prev;

    p->next = list;
    p->prev = last;
    last->next = p;
    list->prev = p;

    return p;
}

// Insert at end
nodeptr *insert_end(nodeptr *list, int data) {
    nodeptr *p = getnode(data);

    if (list == NULL) {
        p->next = p->prev = p;
        return p;
    }

    nodeptr *last = list->prev;

    p->next = list;
    p->prev = last;
    last->next = p;
    list->prev = p;

    return list;
}

// Insert after a given value
nodeptr *insert_after(nodeptr *list, int key, int data) {
    if (list == NULL) {
        printf("List is empty!\n");
        return list;
    }

    nodeptr *q = list;

    do {
        if (q->info == key) {
            nodeptr *p = getnode(data);

            p->next = q->next;
            p->prev = q;
            q->next->prev = p;
            q->next = p;

            return list;
        }
        q = q->next;
    } while (q != list);

    printf("Element not found!\n");
    return list;
}

// Delete from beginning
nodeptr *delete_beg(nodeptr *list) {
    if (list == NULL) {
        printf("List is empty!\n");
        return list;
    }

    nodeptr *p = list;

    if (list->next == list) {
        free(p);
        return NULL;
    }

    nodeptr *last = list->prev;

    list = list->next;
    list->prev = last;
    last->next = list;

    free(p);
    return list;
}

// Delete from end
nodeptr *delete_end(nodeptr *list) {
    if (list == NULL) {
        printf("List is empty!\n");
        return list;
    }

    nodeptr *last = list->prev;

    if (list->next == list) {
        free(list);
        return NULL;
    }

    nodeptr *second_last = last->prev;

    second_last->next = list;
    list->prev = second_last;

    free(last);
    return list;
}

// Delete a specific value
nodeptr *delete_value(nodeptr *list, int key) {
    if (list == NULL) {
        printf("List is empty!\n");
        return list;
    }

    nodeptr *p = list;

    do {
        if (p->info == key) {

            if (p->next == p) {
                free(p);
                return NULL;
            }

            p->prev->next = p->next;
            p->next->prev = p->prev;

            if (p == list)
                list = p->next;

            free(p);
            printf("Element deleted!\n");
            return list;
        }

        p = p->next;
    } while (p != list);

    printf("Element not found!\n");
    return list;
}

// Display forward
void display_forward(nodeptr *list) {
    if (list == NULL) {
        printf("List is empty!\n");
        return;
    }

    nodeptr *p = list;

    printf("NULL <- ");

    do {
        printf("%d <-> ", p->info);
        p = p->next;
    } while (p != list);

    printf("(Back to Head)\n");
}

// Display backward
void display_backward(nodeptr *list) {
    if (list == NULL) {
        printf("List is empty!\n");
        return;
    }

    nodeptr *p = list->prev;

    printf("NULL <- ");

    do {
        printf("%d <-> ", p->info);
        p = p->prev;
    } while (p != list->prev);

    printf("(Back to Last)\n");
}

// Search an element
void search(nodeptr *list, int key) {
    if (list == NULL) {
        printf("List is empty!\n");
        return;
    }

    nodeptr *p = list;
    int pos = 1;

    do {
        if (p->info == key) {
            printf("Element found at position %d\n", pos);
            return;
        }

        p = p->next;
        pos++;

    } while (p != list);

    printf("Element not found!\n");
}

// Main function
int main() {
    int choice, data, key;

    while (1) {
        printf("\n\n--- DOUBLY CIRCULAR LINKED LIST ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Value\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete a Specific Value\n");
        printf("7. Display Forward\n");
        printf("8. Display Backward\n");
        printf("9. Search\n");
        printf("10. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                list = insert_beg(list, data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                list = insert_end(list, data);
                break;

            case 3:
                printf("Enter value after which to insert: ");
                scanf("%d", &key);
                printf("Enter data: ");
                scanf("%d", &data);
                list = insert_after(list, key, data);
                break;

            case 4:
                list = delete_beg(list);
                break;

            case 5:
                list = delete_end(list);
                break;

            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                list = delete_value(list, key);
                break;

            case 7:
                display_forward(list);
                break;

            case 8:
                display_backward(list);
                break;

            case 9:
                printf("Enter value to search: ");
                scanf("%d", &key);
                search(list, key);
                break;

            case 10:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}

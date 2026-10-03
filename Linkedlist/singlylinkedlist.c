
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} nodeptr;

/* Display linked list */
void display(nodeptr *list)
{
    nodeptr *p = list;

    if (list == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (p != NULL)
    {
        printf("%d -> ", p->info);
        p = p->next;
    }
    printf("NULL\n");
}

/* Create linked list */
nodeptr *create(void)
{
    nodeptr *list = NULL, *p, *q;
    int n, i, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0)
        return NULL;

    for (i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &x);

        p = (nodeptr *)malloc(sizeof(nodeptr));

        if (p == NULL)
        {
            printf("Memory allocation failed\n");
            return list;
        }

        p->info = x;
        p->next = NULL;

        if (list == NULL)
            list = p;
        else
            q->next = p;

        q = p;
    }

    return list;
}

/* Insert at beginning */
nodeptr *insertbeg(nodeptr *list, int x)
{
    nodeptr *p = (nodeptr *)malloc(sizeof(nodeptr));

    if (p == NULL)
        return list;

    p->info = x;
    p->next = list;

    return p;
}

/* Insert at end */
nodeptr *insertend(nodeptr *list, int x)
{
    nodeptr *p, *q;

    p = (nodeptr *)malloc(sizeof(nodeptr));

    if (p == NULL)
        return list;

    p->info = x;
    p->next = NULL;

    if (list == NULL)
        return p;

    q = list;

    while (q->next != NULL)
        q = q->next;

    q->next = p;

    return list;
}

/* Search a value */
nodeptr *search(nodeptr *list, int x)
{
    nodeptr *p = list;

    while (p != NULL)
    {
        if (p->info == x)
            return p;

        p = p->next;
    }

    return NULL;
}

/* Insert after a given value */
nodeptr *insertafter(nodeptr *list, int x, int data)
{
    nodeptr *p, *q;

    p = search(list, x);

    if (p == NULL)
    {
        printf("Given node not found\n");
        return list;
    }

    q = (nodeptr *)malloc(sizeof(nodeptr));

    if (q == NULL)
        return list;

    q->info = data;
    q->next = p->next;
    p->next = q;

    return list;
}

/* Delete from beginning */
nodeptr *deletebeg(nodeptr *list)
{
    nodeptr *p;

    if (list == NULL)
    {
        printf("List is empty\n");
        return list;
    }

    p = list;
    list = list->next;
    free(p);

    return list;
}

/* Delete from end */
nodeptr *deleteend(nodeptr *list)
{
    nodeptr *p, *q;

    if (list == NULL)
    {
        printf("List is empty\n");
        return list;
    }

    if (list->next == NULL)
    {
        free(list);
        return NULL;
    }

    p = list;

    while (p->next->next != NULL)
        p = p->next;

    q = p->next;
    p->next = NULL;
    free(q);

    return list;
}

/* Delete a given value */
nodeptr *deletevalue(nodeptr *list, int x)
{
    nodeptr *p, *q;

    if (list == NULL)
    {
        printf("List is empty\n");
        return list;
    }

    if (list->info == x)
    {
        p = list;
        list = list->next;
        free(p);
        return list;
    }

    p = list;

    while (p->next != NULL && p->next->info != x)
        p = p->next;

    if (p->next == NULL)
    {
        printf("Node not found\n");
        return list;
    }

    q = p->next;
    p->next = q->next;
    free(q);

    return list;
}

/* Delete after a given value */
nodeptr *deleteafter(nodeptr *list, int x)
{
    nodeptr *p, *q;

    p = search(list, x);

    if (p == NULL)
        printf("Given node not found\n");
    else if (p->next == NULL)
        printf("No node exists after the given node\n");
    else
    {
        q = p->next;
        p->next = q->next;
        free(q);
    }

    return list;
}

/* Reverse linked list */
nodeptr *reverse(nodeptr *list)
{
    nodeptr *p, *q, *r;

    p = list;
    q = NULL;

    while (p != NULL)
    {
        r = p;
        p = p->next;
        r->next = q;
        q = r;
    }

    list = q;
    return list;
}

/* Free the entire list */
void freeList(nodeptr *list)
{
    nodeptr *p;

    while (list != NULL)
    {
        p = list;
        list = list->next;
        free(p);
    }
}

int main(void)
{
    nodeptr *list = NULL;
    int choice, x, data;
    nodeptr *p;

    do
    {
        printf("\n--- SINGLY LINKED LIST MENU ---\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert After a Given Value\n");
        printf("6. Delete from Beginning\n");
        printf("7. Delete from End\n");
        printf("8. Delete a Given Value\n");
        printf("9. Delete After a Given Value\n");
        printf("10. Search a Value\n");
        printf("11. Reverse List\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                freeList(list);
                list = create();
                break;

            case 2:
                display(list);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &x);
                list = insertbeg(list, x);
                break;

            case 4:
                printf("Enter value: ");
                scanf("%d", &x);
                list = insertend(list, x);
                break;

            case 5:
                printf("Insert after which value? ");
                scanf("%d", &x);
                printf("Enter new value: ");
                scanf("%d", &data);
                list = insertafter(list, x, data);
                break;

            case 6:
                list = deletebeg(list);
                break;

            case 7:
                list = deleteend(list);
                break;

            case 8:
                printf("Enter value to delete: ");
                scanf("%d", &x);
                list = deletevalue(list, x);
                break;

            case 9:
                printf("Delete after which value? ");
                scanf("%d", &x);
                list = deleteafter(list, x);
                break;

            case 10:
                printf("Enter value to search: ");
                scanf("%d", &x);
                p = search(list, x);

                if (p == NULL)
                    printf("Value not found\n");
                else
                    printf("Value found: %d\n", p->info);
                break;

            case 11:
                list = reverse(list);
                printf("List reversed successfully\n");
                break;

            case 12:
                freeList(list);
                printf("Program ended\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 12);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *prev;
    struct node *next;
} nodeptr;

// Insert at beginning
nodeptr* insertBeg(nodeptr *list, int x)
{
    nodeptr *newnode;
    newnode = (nodeptr*)malloc(sizeof(nodeptr));

    newnode->info = x;
    newnode->prev = NULL;
    newnode->next = list;

    if (list != NULL)
        list->prev = newnode;

    list = newnode;
    return list;
}

// Insert at end
nodeptr* insertEnd(nodeptr *list, int x)
{
    nodeptr *newnode, *q;

    newnode = (nodeptr*)malloc(sizeof(nodeptr));
    newnode->info = x;
    newnode->next = NULL;

    if (list == NULL)
    {
        newnode->prev = NULL;
        return newnode;
    }

    q = list;

    while (q->next != NULL)
        q = q->next;

    q->next = newnode;
    newnode->prev = q;

    return list;
}

// Delete from beginning
nodeptr* deleteBeg(nodeptr *list)
{
    nodeptr *q;

    if (list == NULL)
    {
        printf("List is empty");
        return list;
    }

    q = list;
    list = list->next;

    if (list != NULL)
        list->prev = NULL;

    free(q);
    return list;
}

// Delete from end
nodeptr* deleteEnd(nodeptr *list)
{
    nodeptr *q;

    if (list == NULL)
    {
        printf("List is empty");
        return list;
    }

    q = list;

    while (q->next != NULL)
        q = q->next;

    if (q->prev == NULL)
        list = NULL;
    else
        q->prev->next = NULL;

    free(q);
    return list;
}

// Display in forward direction
void displayForward(nodeptr *list)
{
    nodeptr *q = list;

    while (q != NULL)
    {
        printf("%d <-> ", q->info);
        q = q->next;
    }

    printf("NULL\n");
}

// Display in backward direction
void displayBackward(nodeptr *list)
{
    nodeptr *q = list;

    if (q == NULL)
        return;

    while (q->next != NULL)
        q = q->next;

    while (q != NULL)
    {
        printf("%d <-> ", q->info);
        q = q->prev;
    }

    printf("NULL\n");
}

int main()
{
    nodeptr *list = NULL;

    list = insertBeg(list, 30);
    list = insertBeg(list, 20);
    list = insertBeg(list, 10);

    list = insertEnd(list, 40);
    list = insertEnd(list, 50);

    printf("Forward List:\n");
    displayForward(list);

    printf("Backward List:\n");
    displayBackward(list);

    list = deleteBeg(list);
    list = deleteEnd(list);

    printf("After Deletion:\n");
    displayForward(list);

    return 0;
}

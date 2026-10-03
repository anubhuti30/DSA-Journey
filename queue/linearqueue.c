#include <stdio.h>
#define max 5

struct queue
{
    int item[max];
    int front;
    int rear;
};

void insert(struct queue *q, int x)
{
    if(q->rear == max - 1)
        printf("Queue is overflow\n");
    else
    {
        q->rear++;
        q->item[q->rear] = x;
    }
}

int empty(struct queue *q)
{
    if(q->rear < q->front)
        return 1;
    else
        return 0;
}

int delete(struct queue *q)
{
    int x;

    if(empty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }

    x = q->item[q->front];
    q->front++;
    return x;
}

void display(struct queue *q)
{
    int i;

    if(empty(q))
        printf("Queue is empty\n");
    else
    {
        for(i = q->front; i <= q->rear; i++)
            printf("%d ", q->item[i]);
        printf("\n");
    }
}

int main()
{
    struct queue q;
    int ch, x;

    q.front = 0;
    q.rear = -1;

    do
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                insert(&q, x);
                break;

            case 2:
                x = delete(&q);
                if(x != -1)
                    printf("Deleted: %d\n", x);
                break;

            case 3:
                display(&q);
                break;

            case 4:
                break;

            default:
                printf("Invalid choice\n");
        }
    } while(ch != 4);

    return 0;
}
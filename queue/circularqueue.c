
#include <stdio.h>
#define max 5

struct queue
{
    int item[max];
    int front;
    int rear;
};

int empty(struct queue *q)
{
    if(q->front == -1)
        return 1;
    else
        return 0;
}

void insert(struct queue *q, int x)
{
    if((q->rear + 1) % max == q->front)
        printf("Queue is overflow\n");
    else
    {
        if(q->front == -1)
            q->front = 0;

        q->rear = (q->rear + 1) % max;
        q->item[q->rear] = x;
    }
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

    if(q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
        q->front = (q->front + 1) % max;

    return x;
}

void display(struct queue *q)
{
    int i;

    if(empty(q))
    {
        printf("Queue is empty\n");
        return;
    }

    i = q->front;

    while(1)
    {
        printf("%d ", q->item[i]);

        if(i == q->rear)
            break;

        i = (i + 1) % max;
    }

    printf("\n");
}

int main()
{
    struct queue q;
    int ch, x;

    q.front = -1;
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

#include <stdio.h>
#define max 10

int top = -1;
int a[max];

void push(int x)
{
    if (top == max - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        top = top + 1;
        a[top] = x;
        printf("Element pushed successfully!\n");
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        printf("Deleted element = %d\n", a[top]);
        top--;
    }
}

void peep()
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("The top element is %d\n", a[top]);
    }
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack elements are:\n");

        for (i = top; i >= 0; i--)
        {
            printf("%d\t", a[i]);
        }

        printf("\n");
    }
}

int main()
{
    int ch, x;

    do
    {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peep\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &x);
                push(x);
                break;

            case 2:
                pop();
                break;

            case 3:
                peep();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program!\n");
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }

    } while (ch != 5);

    return 0;
}
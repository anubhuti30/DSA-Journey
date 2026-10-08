#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    top++;
    stack[top] = ch;
}

char pop()
{
    char ch;

    ch = stack[top];
    top--;

    return ch;
}

int isMatchingPair(char open, char close)
{
    if(open == '(' && close == ')')
        return 1;

    if(open == '{' && close == '}')
        return 1;

    if(open == '[' && close == ']')
        return 1;

    return 0;
}

int isBalanced(char exp[])
{
    int i;
    char ch, open;

    for(i = 0; exp[i] != '\0'; i++)
    {
        ch = exp[i];

        if(ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }
        else if(ch == ')' || ch == '}' || ch == ']')
        {
            if(top == -1)
                return 0;

            open = pop();

            if(!isMatchingPair(open, ch))
                return 0;
        }
    }

    if(top == -1)
        return 1;
    else
        return 0;
}

int main()
{
    char exp[MAX];

    printf("Enter expression: ");
    scanf("%s", exp);

    if(isBalanced(exp))
        printf("Balanced Parentheses");
    else
        printf("Not Balanced Parentheses");

    return 0;
}
#include <stdio.h>

void push(int *stack, int *stackTop, int data)
{

    if (*stackTop >= 100)
        return;
    else
    {
        stack[++(*stackTop)] = data;
    }
}

void peek(int *stack, int *stackTop)
{

    if (stackTop == -1)
        return;
    printf("%d", stack[*stackTop]);
}

void pop(int *stack, int *stackTop)
{

    if (stackTop == -1)
        return;
    printf("%d", stack[*stackTop]);
    (*stackTop)--;
}

int isEmpty(int stackTop)
{
    if (stackTop == -1)
        return 1;
    return 0;
}

int main()
{

    int stack[100];
    int stackTop = -1;

    push(stack, &stackTop, 20);
    push(stack, &stackTop, 12);
    push(stack, &stackTop, 4);

    pop(stack, &stackTop);
    int status = isEmpty(stackTop);

    return 0;
}
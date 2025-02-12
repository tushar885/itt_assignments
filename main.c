#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{

    int data;
    struct Node *next;

} Node;

typedef struct Stack
{

    Node *top;
    int size;

} Stack;

typedef struct Queue
{

    Stack *stack;

} Queue;

void initializeStack(Stack **stack)
{
    *stack = malloc(sizeof(Stack));
    (*stack)->size = 0;
    (*stack)->top = NULL;
}

void initializeQueue(Queue **que)
{
    *que = (Queue *)malloc(sizeof(Queue));
    initializeStack(&((*que)->stack));
}

void pushStack(Stack **stack, int data)
{

    if ((*stack)->top == NULL)
    {

        Node *newNode = malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;
        (*stack)->top = newNode;
    }
    else
    {

        Node *newNode = malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = (*stack)->top;
        (*stack)->top = newNode;
    }
    (*stack)->size++;
}

int isEmptyStack(Stack *stack)
{
    return stack->size <= 0;
}

int popStack(Stack **stack)
{

    if (isEmptyStack(*stack) == 1)
    {
        printf("Stack is Empty");
        return -1;
    }

    Node *poped = (*stack)->top;
    int data = poped->data;
    (*stack)->top = (*stack)->top->next;
    free(poped);
    (*stack)->size--;
    printf("%d", data);
    return data;
}

void pushToBottomOfStack(Stack **stack, int data)
{

    if (isEmptyStack(*stack) == 1)
    {
        pushStack(stack, data);
        return;
    }

    int poped = popStack(stack);
    pushToBottomOfStack(stack, data);
    pushStack(stack, poped);
}

void enqueue(Queue **que, int data)
{

    pushToBottomOfStack(&((*que)->stack), data);
}

int dequeue(Queue **que)
{

    return popStack(&((*que)->stack));
}

int main()
{

    Queue *que;
    initializeQueue(&que);

    enqueue(que, 12);
    enqueue(que, 19);
    enqueue(que, 1);

    dequeue(que);

    return 0;
}
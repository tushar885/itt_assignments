#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
    int size;
} Queue;

typedef struct Stack
{
    Queue *q1;
    Queue *q2;
} Stack;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(Queue *q, int data)
{
    Node *newNode = createNode(data);
    if (q->rear == NULL)
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

int dequeue(Queue *q)
{
    if (q->front == NULL)
    {
        printf("Stack is Empty\n");
        return -1;
    }
    int data = q->front->data;
    Node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    q->size--;
    return data;
}

int isQueueEmpty(Queue *q)
{
    return q->size == 0;
}

int queueSize(Queue *q)
{
    return q->size;
}

Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->q1 = createQueue();
    stack->q2 = createQueue();
    return stack;
}

void push(Stack *stack, int data)
{
    enqueue(stack->q1, data);
}

int pop(Stack *stack)
{
    if (isQueueEmpty(stack->q1))
    {
        printf("Stack is Empty\n");
        return -1;
    }
    while (queueSize(stack->q1) > 1)
    {
        enqueue(stack->q2, dequeue(stack->q1));
    }
    int poppedValue = dequeue(stack->q1);
    Queue *temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;
    return poppedValue;
}

int peek(Stack *stack)
{
    if (isQueueEmpty(stack->q1))
    {
        printf("Stack is Empty\n");
        return -1;
    }
    while (queueSize(stack->q1) > 1)
    {
        enqueue(stack->q2, dequeue(stack->q1));
    }
    int topValue = dequeue(stack->q1);
    enqueue(stack->q2, topValue);
    Queue *temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;
    return topValue;
}

int isStackEmpty(Stack *stack)
{
    return isQueueEmpty(stack->q1);
}

int stackSize(Stack *stack)
{
    return queueSize(stack->q1);
}

int main()
{
    Stack *stack = createStack();

    return 0;
}

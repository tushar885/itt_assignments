#include <stdio.h>

void enqueue(int *queue, int *front, int *rear, int data)
{

    if (*rear == 99)
    {
        printf("Queue is Full");
        return;
    }

    if (*front == -1)
    {
        queue[++(*rear)] = data;
        (*front)++;
    }
    else
    {
        queue[++(*rear)] = data;
    }
}

void dequeue(int *queue, int *front, int *rear)
{
    if (*front == -1 || *front > *rear)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Dequeued: %d\n", queue[*front]);
    (*front)++;

    if (*front > *rear)
    {
        *front = -1;
        *rear = -1;
    }
}

void peek(int *queue, int front)
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("Front Element: %d\n", queue[front]);
}

int isEmpty(int front, int rear)
{

    if (front == -1 || front > rear)
        return 1;
    return 0;
}

int size(int front, int rear)
{
    if (front == -1)
        return 0;
    return (rear - front + 1);
}

int main()
{

    int queue[100];
    int front = -1;
    int rear = -1;

    enqueue(queue, &front, &rear, 12);
    enqueue(queue, &front, &rear, 10);
    dequeue(queue, &front, &rear);

    return 0;
}
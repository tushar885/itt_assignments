#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory Allocation Failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node **head, int data, int pos)
{
    Node *newNode = createNode(data);
    if (newNode == NULL)
        return;

    if (pos == 1 || *head == NULL)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *curr = *head;

    if (pos == -1)
    {
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = newNode;
        return;
    }

    while (curr != NULL && --pos > 1)
    {
        curr = curr->next;
    }

    if (curr == NULL)
    {
        printf("Invalid Position\n");
        free(newNode);
        return;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}

void updateAtGivenPosition(Node **head, int pos, int data)
{
    if (pos <= 0)
    {
        printf("Invalid Position\n");
        return;
    }
    Node *curr = *head;
    int i = 0;
    while (curr != NULL && i < pos - 1)
    {
        curr = curr->next;
        i++;
    }
    if (curr == NULL)
    {
        printf("Invalid Position");
        return;
    }
    curr->data = data;
}

void deleteNode(Node **head, int pos)
{
    if (*head == NULL || pos < 1)
    {
        return;
    }

    Node *temp = *head;

    if (pos == 1)
    {
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node *prev = NULL;

    if (pos == -1)
    {
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        if (prev == NULL)
        {
            free(*head);
            *head = NULL;
        }
        else
        {
            prev->next = NULL;
            free(temp);
        }
        return;
    }

    while (temp != NULL && --pos > 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void printList(Node **head)
{
    Node *curr = *head;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void freeList(Node **head)
{
    Node *current = *head;
    Node *nextNode;

    while (current != NULL)
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    *head = NULL;
}

int main()
{
    Node *head = NULL;
    int noOfOperations;
    scanf("%d", &noOfOperations);

    if (noOfOperations <= 0)
    {
        printf("Invalid Input");
        return 0;
    }

    while (noOfOperations > 0)
    {
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int data;
            scanf("%d", &data);
            addNode(&head, data, -1);
            printList(&head);
            break;
        }
        case 2:
        {
            int data;
            scanf("%d", &data);
            addNode(&head, data, 1);
            printList(&head);
            break;
        }
        case 3:
        {
            int data;
            int pos;
            scanf("%d", &pos);
            scanf("%d", &data);
            addNode(&head, data, pos);
            printList(&head);
            break;
        }
        case 4:
        {
            printList(&head);
            break;
        }
        case 5:
        {
            int data;
            int pos;
            scanf("%d", &pos);
            scanf("%d", &data);
            updateAtGivenPosition(&head, pos, data);
            printList(&head);
            break;
        }
        case 6:
        {
            deleteNode(&head, 1);
            printList(&head);
            break;
        }
        case 7:
        {
            deleteNode(&head, -1);
            printList(&head);
            break;
        }
        case 8:
        {
            int pos;
            scanf("%d", &pos);
            deleteNode(&head, pos);
            printList(&head);
            break;
        }
        default:
        {
            printf("Please choose between 1 to 8\n");
        }
        }
        noOfOperations--;
    }

    freeList(&head);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

int isDigit(char ch)
{
    return (ch >= '0' && ch <= '9');
}

void inputStringToArray(int **array, int *size)
{
    char string[1000];
    scanf("%[^\n]%*c", string);
    int i = 0;
    *size = 0;

    while (string[i] != '\0')
    {
        if (string[i] == ' ')
        {
            (*size)++;
            i++;
            continue;
        }
        i++;
    }
    *size = *size + 1;

    *array = malloc(*size * sizeof(int));
    int index = 0;
    i = 0;

    while (string[i] != '\0')
    {
        int sign = 1;
        if (string[i] == '-')
        {
            sign = -1;
            i++;
        }
        if (isDigit(string[i]))
        {
            int num = 0;
            while (isDigit(string[i]))
            {
                num = num * 10 + (string[i] - '0');
                i++;
            }
            (*array)[index++] = num * sign;
        }
        else
        {
            i++;
        }
    }
}

struct Node *createNode(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Error in memory allocation");
        return newNode;
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct Node *createList(int *array, int size)
{
    if (size == 0)
        return NULL;

    struct Node *head = createNode(array[0]);
    struct Node *current = head;

    for (int i = 1; i < size; i++)
    {
        current->next = createNode(array[i]);
        current = current->next;
    }

    return head;
}

void splitEvenAndOddLinkedList(struct Node *head, struct Node **oddHead, struct Node **evenHead)
{
    *oddHead = NULL;
    *evenHead = NULL;
    struct Node *oddTail = NULL;
    struct Node *evenTail = NULL;

    while (head)
    {
        if (head->val % 2 == 0)
        {

            if (*evenHead == NULL)
            {
                *evenHead = head;
                evenTail = head;
            }
            else
            {
                evenTail->next = head;
                evenTail = evenTail->next;
            }
        }
        else
        {

            if (*oddHead == NULL)
            {
                *oddHead = head;
                oddTail = head;
            }
            else
            {
                oddTail->next = head;
                oddTail = oddTail->next;
            }
        }
        head = head->next;
    }

    if (evenTail)
        evenTail->next = NULL;
    if (oddTail)
        oddTail->next = NULL;
}

void sortLinkedList(struct Node **head)
{
    struct Node *sorted = NULL;
    struct Node *current = *head;

    while (current != NULL)
    {
        struct Node *next = current->next;

        if (sorted == NULL || sorted->val >= current->val)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            struct Node *temp = sorted;
            while (temp->next != NULL && temp->next->val < current->val)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    *head = sorted;
}

void mergeLinkedList(struct Node **head, struct Node *oddHead, struct Node *evenHead)
{
    if (evenHead == NULL)
    {
        *head = oddHead;
        return;
    }

    struct Node *temp = evenHead;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = oddHead;

    *head = evenHead;
}

void printLinkedList(struct Node *head)
{

    while (head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
}

void freeLinkedList(struct Node *head)
{

    struct Node *temp = head;
    while (head != NULL)
    {

        temp = head;
        head = head->next;
        free(temp);
        temp = NULL;
    }
}

int main()
{

    int *array;
    int size;

    inputStringToArray(&array, &size);

    struct Node *head = createList(array, size);

    struct Node *oddHead;
    struct Node *evenHead;

    splitEvenAndOddLinkedList(head, &oddHead, &evenHead);

    sortLinkedList(&oddHead);
    sortLinkedList(&evenHead);

    mergeLinkedList(&head, oddHead, evenHead);

    printLinkedList(head);

    free(array);
    freeLinkedList(head);
    return 0;
}
